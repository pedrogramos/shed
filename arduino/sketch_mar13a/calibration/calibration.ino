//import the library in the sketch
#include <SharpIR.h>
#include <math.h>

/*
Acumula 10 valores faz a média e devolve or resultado.
Para inciciar o processo enviar o char s através do serial.
 */

#define s1 A2
#define s2 A3
bool once = true;
char receivedChar;
int d = 0;
float v1 = 0;
float sumV = 0, sumD = 0;
float meanV = 0, meanD = 0;


SharpIR sensor( SharpIR::GP2Y0A02YK0F, s1 );
SharpIR sensor2( SharpIR::GP2Y0A02YK0F, s2 );


/*
int getDistanceCm(int _sensorPin) {
  float sensorValue = analogRead(_sensorPin);
    float cm = 10650.08 * pow(sensorValue,-0.935) - 10;
    return roundf(cm);
}
*/

float getMyDistance(int _sensorPin) {
  float v1 = analogRead(_sensorPin)* (5.0 / 1023.0);
  //Serial.println(v1);
  float d = 61.8 * pow(v1, -1.1);
  //Serial.println(d);
  return d;
}



void recvOneChar() {
 if (Serial.available() > 0) {
  receivedChar = Serial.read();
 }
}



  
void setup()
{
  Serial.begin( 115200 ); //Enable the serial comunication
  pinMode(A5, INPUT);
  pinMode(A1, INPUT);

  
  
}

void loop()
{


  /*
  float v2 = analogRead(s2)* (5.0 / 1023.0);
  int d1 = sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  delay(100);
  int d2 = sensor2.getDistance();

  int d12 = getDistanceCm(s1);
  delay(100);  
  int d21 = getDistanceCm(s2);


  Serial.print("\nvoltage:");
  */

  recvOneChar();

  if(receivedChar == 's'){
    Serial.println("Calibration initialized ...");
    float v1 = 0, d = 0;
    float sumV = 0, sumD = 0;
    float meanV = 0, meanD = 0;
    
    for(int i =1; i<=10; i++){
      
      v1 = analogRead(s1)* (5.0 / 1023.0);
      d = 60.374 * pow(v1, -1.16);
      Serial.println(v1);
      Serial.println(d);
      sumV = sumV + v1;
      sumD = sumD + d;
      delay(100);
    }
  
    
  
    meanV = sumV/10;
    meanD = sumD/10; 
    Serial.print("\nMean V: ");
    Serial.print(meanV);
    Serial.print("\nMean D: ");
    Serial.print(meanD);
  
    Serial.println("\nCalibration Done!");
    receivedChar = 'n';
  

  }

  if (receivedChar == 'm'){
    float d12 = getMyDistance(s1);
    float d22 = getMyDistance(s2);
    delay(50);
    Serial.print("\nMeasure: ");
    Serial.print(d12);
    Serial.print("\nMeasure2: ");
    Serial.print(d22);
    receivedChar = 'n';   
    
  }
    /*
  if (teste < 150 ){
      Serial.print("\nsensor1: ");
      Serial.print( teste );
  }
  else Serial.print("\nnot value");



  Serial.print( d12 );
  Serial.println(analogRead(A5)* (5.0 / 1023.0));
  Serial.print("\n");
  Serial.print("\nsensor2: ");
  Serial.print( d2 );
  Serial.print( d21 );
  Serial.println(analogRead(A1)* (5.0 / 1023.0));
  */
  
  //printf("Sensor 1: %d | %d | %f", d1, d12, analogRead(A5)* (5.0 / 1023.0));
  //printf("Sensor 2: %d | %d | %f", d2, d21, analogRead(A1)* (5.0 / 1023.0));

  
  

}
