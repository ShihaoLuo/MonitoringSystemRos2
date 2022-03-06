import sys
sys.path.append("/home/jakeluo/Documents/darknet/")
import random
import darknet
import cv2
import numpy as np
import rclpy
from rclpy.node import Node 
from droneinterfaces.msg import FrameArray
from droneinterfaces.msg import HumanBox


class Detector:
    def __init__(self, config_file, data_file, weights, batch_size, thresh) -> None:
        self.network, self.class_names, self.class_colors = darknet.load_network(
            config_file,
            data_file,
            weights,
            batch_size=batch_size
        )
        self.width = darknet.network_width(self.network)
        self.height = darknet.network_height(self.network)
        self.thresh = thresh

    def image_detection(self, image):
        rY = image.shape[0] / self.height
        rX = image.shape[1] / self.width
        # Darknet doesn't accept numpy images.
        # Create one with image we reuse for each detect
        darknet_image = darknet.make_image(self.width, self.height, 3)
        image_resized = cv2.resize(image, (self.width, self.height),
                                interpolation=cv2.INTER_LINEAR)

        darknet.copy_image_from_bytes(darknet_image, image_resized.tobytes())
        detections = darknet.detect_image(self.network, self.class_names, darknet_image, thresh=self.thresh)
        darknet.free_image(darknet_image)
        # image = darknet.draw_boxes(detections, image_resized, self.class_colors)
        for i in detections:
            if i[0] == 'person':    
                box = [i[2][0] * rX, i[2][1] * rY, i[2][2] * rX, i[2][3] * rY]
                return box
        return [-1., -1., -1., -1.]



# def check_arguments_errors(args):
#     assert 0 < args.thresh < 1, "Threshold should be a float between zero and one (non-inclusive)"
#     if not os.path.exists(args.config_file):
#         raise(ValueError("Invalid config path {}".format(os.path.abspath(args.config_file))))
#     if not os.path.exists(args.weights):
#         raise(ValueError("Invalid weight path {}".format(os.path.abspath(args.weights))))
#     if not os.path.exists(args.data_file):
#         raise(ValueError("Invalid data file path {}".format(os.path.abspath(args.data_file))))
#     if args.input and not os.path.exists(args.input):
#         raise(ValueError("Invalid image path {}".format(os.path.abspath(args.input))))



# def parser():
#     parser = argparse.ArgumentParser(description="YOLO Object Detection")
#     parser.add_argument("--input", type=str, default="",
#                         help="image source. It can be a single image, a"
#                         "txt with paths to them, or a folder. Image valid"
#                         " formats are jpg, jpeg or png."
#                         "If no input is given, ")
#     parser.add_argument("--batch_size", default=1, type=int,
#                         help="number of images to be processed at the same time")
#     parser.add_argument("--weights", default="/home/jakeluo/Documents/darknet/yolov4.weights",
#                         help="yolo weights path")
#     parser.add_argument("--dont_show", action='store_true',
#                         help="windown inference display. For headless systems")
#     parser.add_argument("--ext_output", action='store_true',
#                         help="display bbox coordinates of detected objects")
#     parser.add_argument("--save_labels", action='store_true',
#                         help="save detections bbox for each image in yolo format")
#     parser.add_argument("--config_file", default="/home/jakeluo/Documents/darknet/cfg/yolov4.cfg",
#                         help="path to config file")
#     parser.add_argument("--data_file", default="/home/jakeluo/Documents/darknet/cfg/coco.data",
#                         help="path to data file")
#     parser.add_argument("--thresh", type=float, default=0.9,
#                         help="remove detections with lower confidence")
#     parser.add_argument("--name", type=str, default="t1",
#                         help="drone name")
#     return parser.parse_args()

class HumanPose(Node):
    def __init__(self, name, predicter):
        super().__init__('humanbox')
        self.subscription = self.create_subscription(
            FrameArray,
            name+"_Framearray",
            self.framecallback,
            10
        )
        self.predicter = predicter
        self.subscription
        self.publisher = self.create_publisher(HumanBox, name+"_HumanBox", 10)
        self.coor = HumanBox()
        # self.im = np.zeros((720, 960, 3), np.uint8)

    def framecallback(self, msg):
        image = (np.asarray(msg.framebuf, np.uint8).reshape((720, 960, 3)))[...,::-1].copy()
        det = self.predicter.image_detection(image)  
        self.coor.coordinate = det
        self.publisher.publish(self.coor)

def main(args=None):
    # args = parser()
    # check_arguments_errors(args)

    random.seed(3)  # deterministic bbox colors

    detector = Detector(
        "/home/jakeluo/Documents/darknet/cfg/yolov4.cfg", 
        "/home/jakeluo/Documents/darknet/cfg/coco.data", 
        "/home/jakeluo/Documents/darknet/yolov4.weights", 
        1, 
        0.85
    )
    rclpy.init(args=args)
    subscriber = HumanPose(sys.argv[1], detector)

    rclpy.spin(subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    # unconmment next line for an example of batch processing
    # batch_detection_example()
    main()


