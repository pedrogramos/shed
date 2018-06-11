source /opt/ros/kinetic/setup.bash
source ~/catkin_ws/devel/setup.bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/lib
export PYTHONPATH=$PYTHONPATH:$HOME/lib
source ~/openar/bin/openardfs
export CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:/home/rmp/openar/lib/CMake
export ROS_HOSTNAME=localhost
export ROS_MASTER_URI=http://localhost:11311