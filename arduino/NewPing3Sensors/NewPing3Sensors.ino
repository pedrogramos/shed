// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define SONAR_NUM 3      // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.


// Each sensor's trigger pin, echo pin, and max distance to ping.
NewPing sonar[SONAR_NUM] = {
  NewPing(2, 3, MAX_DISTANCE), //Left  
  NewPing(4, 5, MAX_DISTANCE), //Center
  NewPing(10, 11, MAX_DISTANCE)  //Right
};
int dSonar[SONAR_NUM];

void setup() {
  Serial.begin(115200);
}

void loop() { 
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    delay(100); // Wait 100ms between pings, and raise later for better results
    dSonar[i]=sonar[i].ping_cm();
    Serial.print(i);
    Serial.print("=");
    Serial.print(dSonar[i]);
    Serial.print("cm ");
  }
  Serial.println();

}
