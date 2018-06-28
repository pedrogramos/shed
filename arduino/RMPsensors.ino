/*
codigo exemplo para a aquisição e tratamento dos valores dos sensores do RMP 200
4 SharpIR GP2Y0A02YK0F
3 HC-SR04
Publica os resultados numa ROS node

--> disposição dos sensores:
		 s5		
   IR4 	      IR3 

IR1 		     IR2
s1			     s2

*/

#include <ros.h>
#include <NewPing.h>
#include <rosserial_arduino/sensors.h> 

ros::NodeHandle nh;
rosserial_arduino::sensors values;
ros::Publisher sensorArray("sensorArray", &values);
//definição das portas
#define IR_NUM 4 
#define IR1 A1
#define IR2 A2
#define IR3 A3
#define IR4 A4
#define SONAR_NUM 2
#define MAX_DISTANCE 150 // Maximum distance (in cm) to ping.
#define timeDelay 50

float getIRDistance(int _sensorPin) {
  float v1 = analogRead(_sensorPin)* (5.0 / 1023.0);
  //Serial.println(v1);
  float d = 61.8 * pow(v1, -1.1);
  //Serial.println(d);
  return d*0.1;
}



//array para os sonares
NewPing sonar[SONAR_NUM] = {
  NewPing(4, 5, MAX_DISTANCE), //Left  
  NewPing(6, 7, MAX_DISTANCE), //Right
  NewPing(8, 9, MAX_DISTANCE)  //Center
};


void setup(){
	pinMode(A1,OUTPUT);
	pinMode(A2,OUTPUT);
	pinMode(A3,OUTPUT);
	pinMode(A4,OUTPUT);
	nh.initNode();
	nh.advertise(sensorArray);
	Serial.begin(115200);

}


void loop(){

	values.ir1 = getIRDistance(IR1)
	values.s1 = sonar[0].ping_cm();
	delay(timeDelay);
	values.ir2 = getIRDistance(IR2)
	values.s2 = sonar[1].ping_cm();
	delay(timeDelay);
	values.ir3 = getIRDistance(IR3)
	delay(timeDelay);
	values.ir4 = getIRDistance(IR4)
	delay(timeDelay);
	values.s5 = sonar[2].ping_cm();
	delay(timeDelay);


	sensorArray.publish(&values);
	nh.spinOnce();
}