#！ /bin/bash
cd /home/jakeluo/Documents/MonitoringSystemRos2/src
. /home/jakeluo/Documents/MonitoringSystemRos2/src/ros2_setup.sh
ros2 run droneutility drone t1 111 &
ros2 run humanpose estimater t1 &
ros2 run droneutility drone t2 222 &
ros2 run humanpose estimater t2 &
ros2 run droneutility dronemanager &
ros2 run qt gui 
