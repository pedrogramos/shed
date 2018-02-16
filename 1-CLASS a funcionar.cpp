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

class SendVelocity
{
public:
  SendVelocity();
  void comVel(double,double);
  void stopTurtle();
  void odomCallback(const turtlesim::PoseConstPtr&);
  void infoOdom();
  void goTo(double,double,turtlesim::PoseConstPtr&);
  void run(double,double,double);

private:

  
  ros::NodeHandle nh;
  ros::Publisher vel_pub;
  ros::Subscriber odom_sub;
  geometry_msgs::Twist vel;
  double odomX;
  double odomY;
  double odomTheta;
  // para ter sempre a odometria à mão
  turtlesim::PoseConstPtr aPose;
  // variavel do tipo pose para as coordenadas de destino
  turtlesim::Pose gPose;
  
};

SendVelocity::SendVelocity(){

  vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
  odom_sub = nh.subscribe("/turtle1/pose",10,&SendVelocity::odomCallback,this);
  //Foo foo_object;
  //ros::Subscriber sub = nh.subscribe("my_topic", 1, &Foo::callback, &foo_object);
}


void SendVelocity::comVel(double line_x, double ang_z){

  vel.linear.x = line_x;
  vel.angular.z = ang_z;
  vel_pub.publish(vel);

  ROS_INFO("Velocity Comands: linear= %f e angular= %f", vel.linear.x, vel.angular.z);

  return;
}

void SendVelocity::stopTurtle(){

  vel.linear.x = 0.0;
  vel.angular.z = 0.0;
  vel_pub.publish(vel);
  ROS_INFO("STOP!!");
}


// rosmsg show [turtlesim/Pose] = msg1-> [x] 
void SendVelocity::odomCallback(const turtlesim::PoseConstPtr& msg1){ 
  // nav_msgs::Odometry --> pose.pose.position.
  odomX = msg1->x;
  odomY = msg1->y;
  odomTheta = msg1->theta;
  aPose=msg1;

  //ROS_INFO("Odometria: X= %f, Y= %f, e Theta= %f", x,y,theta);
}
/*
void SendVelocity::goTo(double line_x, double ang_z, const turtlesim::PoseConstPtr msg2){

  vel.linear.x = line_x;
  vel.angular.z = ang_z;
  vel_pub.publish(vel);

}
*/

void SendVelocity::infoOdom(){

  ROS_INFO("OdometriaFun: X= %f, Y= %f, e Theta= %f", odomX,odomY,odomTheta);
}

void SendVelocity::run(double x, double y, double theta){
  if(odomX > x+1 || odomX < x-1){
    ROS_DEBUG("Se %f for dif de %f.", x,odomX);
    comVel(0.2,0.0);
  }
    
  else if(odomTheta > theta+0.5 || odomTheta < theta-0.5){
    ROS_DEBUG("Se %f for dif de %f.", theta,odomTheta);
    comVel(0.0,0.2);
  }
    
  else stopTurtle();

}



int main(int argc, char** argv)
{
  // nome igual ao do ficheiro
  ros::init(argc, argv, "velocityturtle1_node");
  // criação do objecto da classe
  SendVelocity turtle1;

  ros::Rate rate(1);
  while(ros::ok){
    rate.sleep();
    turtle1.infoOdom();
    turtle1.run(7,0,2);

    ros::spinOnce();

  }
  
}