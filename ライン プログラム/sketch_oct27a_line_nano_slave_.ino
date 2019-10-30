//ラインセンサ　プログラム　slave

#include<Wire.h>

void setup() {
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  
  Serial.begin(9600);
  
}

void loop() {

}

short sensorVal = 0;

void requestEvent(){
  int sensorVal = analogRead(0);
  Wire.write((++sensorVal)&0xff);
  Wire.write((sensorVal>>8)&0xff);

  Serial.print("line 01 : ");
  Serial.println(sensorVal);

}
