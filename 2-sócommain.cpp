#include <iostream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include "ros/ros.h"
#include <signal.h>
#include <termios.h>
#include <tf/transform_broadcaster.h>
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/String.h"
#include <turtlesim/Pose.h>

#define PI 3.141592


/*
int main(int argc, char**argv){
ros::init(argc, argv, "publish_velocity");
ros::NodeHandle nh;

ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

srand(time(0));

ros::Rate rate(2);
while(ros::ok()){
geometry_msgs::Twist msg;
msg.linear.x = double(rand())/double(RAND_MAX);
msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

pub.publish(msg);

ROS_INFO_STREAM("Sending random velocity command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);

rate.sleep();
}
}
*/

/*
void commandTurtle(ros::Publisher twist_pub, float linear, float angular)
{
  geometry_msgs::Twist twist;
  twist.linear.x = linear;
  twist.angular.z = angular;
  twist_pub.publish(twist);
}
*/



  
  ros::NodeHandle nh;
  ros::Publisher vel_pub;
  ros::Subscriber odom_sub;
  geometry_msgs::Twist vel;
  turtlesim::PoseConstPtr pose;
  turtlesim::Pose goalPose;

void SvelCont(double line_x, double ang_z){

  vel.linear.x = line_x;
  vel.angular.z = ang_z;
  vel_pub.publish(vel);

  ROS_INFO("Velocity Comands: linear= %f e angular= %f", vel.linear.x, vel.angular.z);

  return;
}

void stopTurtle(){

  vel.linear.x = 0.0;
  vel.angular.z = 0.0;
  vel_pub.publish(vel);
  ROS_INFO("STOP!!");
}

void odomCallback(const turtlesim::PoseConstPtr& msg1){

  pose = msg1;
}

void fala(){
    double x = pose->x;
  double y = pose->y;
  double theta = pose->theta;
   ROS_INFO("Odometria: X= %f, Y= %f, e Theta= %f", x,y,theta);
}

int main(int argc, char** argv)
{
  // nome igual ao do ficheiro
  ros::init(argc, argv, "velocityturtle1_node");
  vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
  odom_sub = nh.subscribe("/turtle1/Pose",100,odomCallback);

  // for the callbacks if i have a subscription
  ros::spin();
  //ros::spinOnce();
}