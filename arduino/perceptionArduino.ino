/*
codigo exemplo para a aquisição e tratamento dos valores dos sensores do RMP 200
4 SharpIR GP2Y0A02YK0F
3 HC-SR04
Publica os resultados numa ROS node

--> disposição dos sensores:
     s5   
   IR4        IR3 

IR1          IR2
s1           s2

*/

//#include <ros.h>
#include <NewPing.h>
//#include <RMPISR/sensors.h> 
#include <math.h>
#include <string.h>
/*
ros::NodeHandle nh;
RMPISR::sensors values;
ros::Publisher p("sensorArray", &values);
*/
// definição das portas
#define IR_NUM 4 
#define IR1 A1
#define IR2 A2
#define IR3 A3
#define IR4 A4
#define SONAR_NUM 3
#define MAX_DISTANCE 150 // Maximum distance (in cm) to ping.
#define timeDelay 50
char receivedChar;
char buf[80];
float values[7];
float vlr;
float vlr2;

float getIRDistance(int _sensorPin) {
  float v1 = analogRead(_sensorPin)* (5.0 / 1023.0);
  //Serial.println(v1);
  float d = 61.8 * pow(v1, -1.1);
  //Serial.println(d);
  return d*0.01;
}

void recvOneChar() {
 if (Serial.available() > 0) {
  receivedChar = Serial.read();
 }
}




//array para os sonares
NewPing sonar[SONAR_NUM] = {
  NewPing(4, 5, MAX_DISTANCE), //Left  
  NewPing(6, 7, MAX_DISTANCE), //Right
  NewPing(8, 9, MAX_DISTANCE)  //Center
};


void setup(){
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  /*
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(p);
  */
  Serial.begin(115200);

}


void loop(){

  values[0] = getIRDistance(IR1);
  values[1] = sonar[0].ping_cm()*0.01;
  delay(timeDelay);
  values[2] = getIRDistance(IR2);
  values[3] = sonar[1].ping_cm()*0.01;
  delay(timeDelay);
  values[4] = getIRDistance(IR3);
  delay(timeDelay);
  values[5] = getIRDistance(IR4);
  delay(timeDelay);
  values[6] = sonar[2].ping_cm()*0.01;
  delay(timeDelay);

  /*

  Serial.println("Before");
  Serial.println(values[0]);
  Serial.println(values[1]);
  Serial.println(values[2]);
  Serial.println(values[3]);
  Serial.println(values[4]);
  Serial.println(values[5]);
  Serial.println(values[6]);
  delay(1000);
  */

 //checking if measures are between the acceptable values
  for( int i = 0; i<=6; i++){
    if(values[i] < 0.20 || values[i] > 1.50) values[i] = 0;

  }
  
  Serial.println("hshake");
  Serial.println(values[0]);
  Serial.println(values[1]);
  Serial.println(values[2]);
  Serial.println(values[3]);
  Serial.println(values[4]);
  Serial.println(values[5]);
  Serial.println(values[6]);
  delay(1000);




/*
  Serial.println("hshake");
  Serial.println(getIRDistance(IR1));
  Serial.println( sonar[0].ping_cm()*0.01);
  delay(timeDelay);
  Serial.println( getIRDistance(IR2));
  Serial.println( sonar[1].ping_cm()*0.01);
  delay(timeDelay);
  Serial.println(getIRDistance(IR3));
  delay(timeDelay);
  Serial.println(getIRDistance(IR4));
  delay(timeDelay);
  Serial.println(sonar[2].ping_cm()*0.01);
  delay(timeDelay);
  delay(1000);
 */



// A INTRODUZIR NUMERO DO SENSOR
/*
  
  recvOneChar();

  if(receivedChar == '1'){
    vlr = getIRDistance(IR1);
    vlr2 = sonar[0].ping_cm();
    Serial.print("\nMeasure 1: IR= ");
    Serial.print( vlr );
    Serial.print("  HC= ");
    Serial.print( vlr2 );
    
    receivedChar = 'n';

  }

  else if(receivedChar == '2'){
     vlr = getIRDistance(IR2);
     vlr2 = sonar[1].ping_cm();
    delay(timeDelay);
    float a = sensor.getDistance();
    
    Serial.print("\nMeasure 2: IR= ");
    Serial.print( vlr );
    Serial.print( " other: ");
    Serial.print( a );
    Serial.print("   HC= ");
    Serial.print( vlr2);

    
    receivedChar = 'n';
  }

  else if(receivedChar == '3'){
     vlr = getIRDistance(IR3);
    Serial.print("\nMeasure 3: IR= ");
    Serial.print( vlr);
    
    receivedChar = 'n';  
  }

  else if(receivedChar == '4'){
     vlr = getIRDistance(IR4);
     delay(timeDelay);
    float a = sensor.getDistance();
    Serial.print("\nMeasure 4: IR= ");
    Serial.print( vlr);
    Serial.print( " other: ");
    Serial.print( a );
    
    receivedChar = 'n';
  }

  else if(receivedChar == '5'){
     vlr = sonar[2].ping_cm();
    Serial.print("\nMeasure 5: HC= ");
    Serial.print( vlr);
    
    receivedChar = 'n';
  }

  else if(receivedChar == 't'){

    Serial.print("estou1");

    values[0] = getIRDistance(IR1);
    values[1] = sonar[0].ping_cm();
    delay(timeDelay);
    values[2] = getIRDistance(IR2);
    values[3] = sonar[1].ping_cm();
    delay(timeDelay);
    values[4] = getIRDistance(IR3);
    delay(timeDelay);
    values[5] = getIRDistance(IR4);
    delay(timeDelay);
    values[6] = sonar[2].ping_cm();
    delay(timeDelay);

    Serial.print("estou");
    

    for (int i = 0; i <= 5; i++){
      Serial.println( values[i]);
    }

    receivedChar = 'n';

    
  }
*/

  
}
