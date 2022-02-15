from torch import device
import rclpy
from rclpy.node import Node 
from droneinterfaces.msg import FrameArray
import sys
import torch
import os
from .networks import *
from .network import CoordRegressionNetwork
from scipy.ndimage import maximum_filter, gaussian_filter
from skimage import io, transform
import itertools
import logging
import math
from collections import namedtuple
import cv2
import numpy as np
from torchsummary import summary


class ResEstimator:
    def __init__(self, model_path, net, inp_dim=224):
        self.inp_dim = inp_dim
        self.net = net
        self.net.load_state_dict(torch.load(model_path, map_location=lambda storage, loc: storage))
        self.net.eval()
        self.device = torch.device("cuda" if True else "cpu")
        summary(self.net, input_size=(3, 224, 224))

    def addlayer(self, image):
        h, w = image.shape[:2]
        # todo retraining model
        x = np.arange(0, h)
        y = np.arange(0, w) 
        x, y = np.meshgrid(x, y)
        x = x[:,:, np.newaxis]
        y = y[:,:, np.newaxis]
        image = np.concatenate((image, x, y), axis=2)
        
        return image

    def wrap(self, image, output_size):
        image_ = image/256.0
        h, w = image_.shape[:2]
        if isinstance(output_size, int):
            if h > w:
                new_h, new_w = output_size * h / w, output_size
            else:
                new_h, new_w = output_size, output_size * w / h
        else:
            new_h, new_w = output_size

        new_h, new_w = int(new_h), int(new_w)

        image = transform.resize(image_, (new_w, new_h))
        pose_fun = lambda x: (x.reshape([-1,2]) * 1.0 /np.array([new_w, new_h])*np.array([w,h]))
        return {'image': image, 'pose_fun': pose_fun}
        
    def rescale(self, image, output_size):

        image_ = image/256.0
        h, w = image_.shape[:2]
        im_scale = min(float(output_size[0]) / float(h), float(output_size[1]) / float(w))
        new_h = int(image_.shape[0] * im_scale)
        new_w = int(image_.shape[1] * im_scale)
        image = cv2.resize(image_, (new_w, new_h), interpolation=cv2.INTER_LINEAR)
        left_pad =int( (output_size[1] - new_w) / 2.0)
        top_pad = int((output_size[0] - new_h) / 2.0)
        mean=np.array([0.485, 0.456, 0.406])
        pad = ((top_pad, top_pad), (left_pad, left_pad))
        image = np.stack([np.pad(image[:,:,c], pad, mode='constant', constant_values=mean[c])for c in range(3)], axis=2)
        pose_fun = lambda x: ((((x.reshape([-1,2])+np.array([1.0,1.0]))/2.0*np.array(output_size)-[left_pad, top_pad]) * 1.0 /np.array([new_w, new_h])*np.array([w,h])))
        return {'image': image, 'pose_fun': pose_fun}

    def to_tensor(self, image):
     
        mean=np.array([0.485, 0.456, 0.406])
        std=np.array([0.229, 0.224, 0.225])    
        image = torch.from_numpy(((image-mean)/std).transpose((2, 0, 1))).float().to(self.device)
        return image

    def inference(self, in_npimg):
        canvas = np.zeros_like(in_npimg)
        height = canvas.shape[0]
        width = canvas.shape[1]

        rescale_out = self.rescale(in_npimg, (self.inp_dim, self.inp_dim))
       
        image = rescale_out['image']
        image = self.to_tensor(image)
        image = image.unsqueeze(0)
        pose_fun = rescale_out['pose_fun']
        # print("shape of tensor:", image.size())
        with torch.no_grad():
            keypoints = self.net(image)
        # print(keypoints.shape)
        # print("0:", keypoints[0])
        # print("-----:")
        keypoints1 = keypoints[1][0].cpu().detach().numpy()
        keypoints = keypoints[0].cpu().detach().numpy()
        # for a in keypoints:
        #     pos = np.unravel_index(np.argmax(a),a.shape)
        #     print(a[pos[0], pos[1]])
        keypoints = pose_fun(keypoints).astype(int)
        for i in range(16):
            pos = np.unravel_index(np.argmax(keypoints1[i]), (56, 56))
            if(keypoints1[i][pos[0], pos[1]] < 0.1):
                keypoints[i] = [-1, -1]
        # print("keypoints2:", keypoints)
        return keypoints

    @staticmethod
    def draw_humans(npimg, pose, imgcopy=False):
        if imgcopy:
            npimg = np.copy(npimg)
        image_h, image_w = npimg.shape[:2]
        centers = {}

        colors = [[255, 0, 0], [255, 85, 0], [255, 170, 0], [255, 255, 0], [170, 255, 0], [85, 255, 0], [0, 255, 0],
              [0, 255, 85], [0, 255, 170], [0, 255, 255], [0, 170, 255], [0, 85, 255], [0, 0, 255], [85, 0, 255],
              [170, 0, 255], [255, 0, 255]]

        pairs = [[8,9],[11,12],[11,10],[2,1],[1,0],[13,14],[14,15],[3,4],[4,5],[8,7],[7,6],[6,2],[6,3],[8,12],[8,13]]
        colors_skeleton = ['r', 'y', 'y', 'g', 'g', 'y', 'y', 'g', 'g', 'm', 'm', 'g', 'g', 'y','y']
        colors_skeleton = [[255, 0, 0], [255, 85, 0], [255, 170, 0], [255, 255, 0], [170, 255, 0], [85, 255, 0], [0, 255, 0],
              [0, 255, 85], [0, 255, 170], [0, 255, 255], [0, 170, 255], [0, 85, 255], [0, 0, 255], [85, 0, 255],
              [170, 0, 255]]
        ok = 0
        for i in range(16):
            if(pose[i][0]):
                ok +=1
        if ok >= 10:
            for idx in range(len(colors)):
                if(pose[idx][0]):
                    cv2.circle(npimg, (pose[idx,0], pose[idx,1]), 3, colors[idx], thickness=3, lineType=8, shift=0)
        # for idx in range(len(colors_skeleton)):
        #     npimg = cv2.line(npimg, (pose[pairs[idx][0],0], pose[pairs[idx][0],1]), (pose[pairs[idx][1],0], pose[pairs[idx][1],1]), colors_skeleton[idx], 3)
        return npimg

class HumanPose(Node):
    def __init__(self, name, predicter):
        super().__init__('humanpose')
        self.subscription = self.create_subscription(
            FrameArray,
            name+"_Framearray",
            self.framecallback,
            10
        )
        self.predicter = predicter
        self.subscription
        # self.im = np.zeros((720, 960, 3), np.uint8)

    def framecallback(self, msg):
        image = (np.asarray(msg.framebuf, np.uint8).reshape((720, 960, 3)))[...,::-1].copy()
        humans = self.predicter.inference(image)
        image = ResEstimator.draw_humans(image, humans, imgcopy=False)
        cv2.imshow('MobilePose', image)
        cv2.waitKey(40)
        # self.get_logger().info("test human pose: %d.\n"%(len(msg.framebuf)))

def main(args=None):
    os.environ["CUDA_VISIBLE_DEVICES"]="0"
    torch.backends.cudnn.enabled = True
    device = torch.device("cuda" if True else "cpu")
    print("GPU NUM: %d"%(torch.cuda.device_count()))
    modelPath = "/home/jakeluo/Documents/MonitoringSystemRos2/src/humanpose/humanpose/mobilenetv2_224_adam_best.t7"
    inputsize = 224
    net = CoordRegressionNetwork(n_locations=16, backbone='mobilenetv2').to(device)
    e = ResEstimator(modelPath, net, inputsize)
    # e.inference()
    rclpy.init(args=args)
    subscriber = HumanPose(sys.argv[1], e)

    rclpy.spin(subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()