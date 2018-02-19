#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <ros/ros.h>
#include <signal.h>
#include <termios.h>
#include <tf/transform_broadcaster.h>
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include <turtlesim/Pose.h>
//TF2
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_ros/transform_listener.h>

#define PI 3.141592
#define Kl 0.6
#define Kw 0.6

using namespace std;


class SendVelocity
{
public:
  SendVelocity();
  void sendVel(double,double);
  void stopTurtle();
  void odomCallback(const turtlesim::PoseConstPtr&);
  void infoOdom();
  void goTo(float,float,float);

private:

  
  ros::NodeHandle nh;
  ros::Publisher vel_pub;
  //ros::Publisher vazio_pub;
  //ros::Subscriber vazio_sub;
  ros::Subscriber odom_sub;
  geometry_msgs::Twist vel;
  double odomX;
  double odomY;
  double odomTheta;
  // para ter sempre a odometria à mão
  turtlesim::PoseConstPtr aPose;
  // variavel do tipo pose para as coordenadas de destino
  turtlesim::Pose gPose;
  //TF2

  
};

SendVelocity::SendVelocity(){

  vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
  //vazio_pub=nh.advertise<std_msgs::Bool>("/pedro",1);
  //vazio_sub=nh.subscribe("/pedro",1,&SendVelocity::stopTurtle,this);
  odom_sub = nh.subscribe("/turtle1/pose",10,&SendVelocity::odomCallback,this);
  //Foo foo_object;
  //ros::Subscriber sub = nh.subscribe("my_topic", 1, &Foo::callback, &foo_object);
  
}


void SendVelocity::sendVel(double line_x, double ang_z){

  vel.linear.x = line_x;
  vel.angular.z = ang_z;
  vel_pub.publish(vel);

  //ROS_INFO("Velocity Comands: linear= %f e angular= %f", vel.linear.x, vel.angular.z);

  return;
}


void SendVelocity::stopTurtle(){

  sendVel(0.0,0.0);
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


void SendVelocity::infoOdom(){

  ROS_DEBUG("OdometriaFun: X= %f, Y= %f, e Theta= %f", odomX,odomY,odomTheta);
}


void SendVelocity::goTo(float xf, float yf,float limiar){
  // calculo do módulo
  float d=sqrt(pow((xf-odomX),2)+pow((yf-odomY),2));
  float c=pow((xf-odomX),2)+pow((yf-odomY),2);
  while (c>pow(limiar,2)){
    c=pow((xf-odomX),2)+pow((yf-odomY),2);
    d=sqrt(pow((xf-odomX),2)+pow((yf-odomY),2));
    // vetores normalizados -> versor
    float dx=(xf-odomX)/d;
    float dy=(yf-odomY)/d;
    // calculo velocidades a enviar
    float vx=cos(odomTheta)*dx+sin(odomTheta)*dy;
    float vy=cos(odomTheta)*dy-sin(odomTheta)*dx;
    // projecções * os ganhos
    sendVel(vx*Kl,vy*Kw);
    ROS_INFO("vx= %f vw= %f", vx*Kl, vy*Kw);
    ROS_DEBUG("vx= %f vy= %f d= %f xf= %f yf= %f",vx,vy, d, xf, yf);
    ros::spinOnce();
  }

  if(c<pow(limiar,2)){
    ROS_INFO("chegou ao ponto x= %f e y= %f",xf, yf);
    infoOdom();
  } 

} 
  

int main(int argc, char** argv)
{
  // nome igual ao do ficheiro
  ros::init(argc, argv, "velocityturtle1_node");
  // criação do objecto da classe
  SendVelocity turtle1;

  ifstream myReadFile;
  myReadFile.open("/home/rmp/catkin_ws/src/testeturtle/src/pontos.txt");
 float xf[100];
 float yf[100];
 int i=0;
 int j=0;
 if (myReadFile.is_open()) {
 while (!myReadFile.eof()) {

    myReadFile >> xf[i] >> yf[i];
    i++;
  }
}
myReadFile.close();



  ros::Rate rate(10.0);
  while(ros::ok()){
  
  if(j<i-2){
  turtle1.goTo(xf[j],yf[j],0.3);
  j++;
  }
  else turtle1.stopTurtle();

   ros::spinOnce();
   rate.sleep();

  }

return 0;
}