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
// #include ""

/*
int main(int argc, char **argv) {

    //Initializes ROS, and sets up a node with the name "send_velocity_node"
    ros::init(argc, argv, "velocity_turtle_node");
    ros::NodeHandle nh;

    // topico que vai publicar os comandos de velocidade 
    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
    // topico que vai subscrever a odometria
    //ros::Subscriber odo_sub =nh.subscribe(nav_msgs::Odometry)("/turtle1/Pose",1000,); // type: turtlesim/Pose

    ros::Rate loop_rate(10);

    geometry_msgs::Twist vel;


    vel.linear.x=10.0;
    //vel.angular.z=0;

    vel_pub.publish(vel);
    

    ros::spin();

return 0;
}
*/

class SendVelocity
{
public:
  SendVelocity();
  //void vel_teste();
  void OdomCallback();

private:

  
  ros::NodeHandle nh;
  double linear_, angular_, l_scale_, a_scale_;
  ros::Publisher vel_pub;
  
};

SendVelocity::SendVelocity()
{
  vel_sub = nh.subscribe<geometry_msgs::Twist>("cmd_vel",nav_msgs/Odometry, 100, );
}


void SendVelocity::vel_teste()
{


  ROS_INFO("About to send the velocities comand");

    geometry_msgs::Twist vel;
    vel.angular.z = 10.0;
    vel.linear.x = 10.0;

    vel_pub.publish(vel);



  return;
}

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{


int main(int argc, char** argv)
{
  // nome igual ao do ficheiro
  ros::init(argc, argv, "velocity_turtle1_node");
  // criação do objecto da classe
  SendVelocity velocityturtle1_node;
  // iniciação da função teste 
  velocityturtle1_node.vel_teste();

  ros::spin();
  
  return(0);
}



