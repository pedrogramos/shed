// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------


#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <NewPing.h>

#define SONAR_NUM 3      // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define dangerDistL 10
#define dangerDistF 20
#define dangerDistR 10

ros::NodeHandle  nh;
std_msgs::Bool danger;
ros::Publisher sonarFlag("sonarFlag", &danger);
bool aux[SONAR_NUM];



// Each sensor's trigger pin, echo pin, and max distance to ping.
NewPing sonar[SONAR_NUM] = {
  NewPing(4, 5, MAX_DISTANCE), //Left  
  NewPing(6, 7, MAX_DISTANCE), //Center
  NewPing(8, 9, MAX_DISTANCE)  //Right
};

int dSonar[SONAR_NUM];

void setup() {
  
  nh.initNode();
  nh.advertise(sonarFlag);
  Serial.begin(115200);
}

void loop() { 
  
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    delay(100); // Wait 100ms between pings, and raise later for better results
    dSonar[i]=sonar[i].ping_cm();
    //Serial.print(i);
    //Serial.print("=");
    //Serial.print(dSonar[i]);
    //Serial.print("cm ");
  }
  //Serial.println();

  if(dSonar[0] < dangerDistL && dSonar[0] != 0){
    danger.data=true;
    Serial.print("Sonar 0 - Left");
    Serial.println();
  }
  if(dSonar[1] < dangerDistF && dSonar[1] != 0){
    danger.data=true;
    Serial.print("Sonar 1 - Centre");
    Serial.println();
  }
  if(dSonar[2] < dangerDistR && dSonar[2] != 0){
    danger.data=true;
    Serial.print("Sonar 2 - Right");
    Serial.println();
  }
  //if((dSonar[0] > dangerDistL || dSonar[0] == 0) && (dSonar[1] > dangerDistF || dSonar[1] == 0 ) && (dSonar[2] > dangerDistR || dSonar[2] == 0)) danger.data=false;

  //if(dSonar[0] > dangerDistL || dSonar[0] == 0) aux[0]=true;
  //if(dSonar[1] > dangerDistF || dSonar[1] > dangerDistF == 0 ) aux[1]=true;
  
  
  sonarFlag.publish( &danger );
  nh.spinOnce();
  //delay(1000);
}
