//ラインセンサ　プログラム　nano slave

#include<Wire.h>

void setup() {
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  
  Serial.begin(9600);
  
}

void loop() {

  if();
  
}

short sensorVal01 = 0;
short sensorVal02 = 0;
short sensorVal03 = 0;
short sensorVal04 = 0;
short sensorVal05 = 0;

void requestEvent(){

//ラインセンサ01
  int sensorVal01 = analogRead(0);
  Wire.write((++sensorVal01)&0xff);
  Wire.write((sensorVal01>>8)&0xff);

  Serial.print("line 01 : ");
  Serial.println(sensorVal01);

//ラインセンサ02
  int sensorVal02 = analogRead(1);
  Wire.write((++sensorVal02)&0xff);
  Wire.write((sensorVal02>>8)&0xff);

  Serial.print("line 02 : ");
  Serial.println(sensorVal02);

//ラインセンサ03
  int sensorVal03 = analogRead(2);
  Wire.write((++sensorVal03)&0xff);
  Wire.write((sensorVal03>>8)&0xff);

  Serial.print("line 03 : ");
  Serial.println(sensorVal03);

//ラインセンサ04
  int sensorVal04 = analogRead(3);
  Wire.write((++sensorVal04)&0xff);
  Wire.write((sensorVal04>>8)&0xff);

  Serial.print("line 04 : ");
  Serial.println(sensorVal04);

//ラインセンサ05
  int sensorVal05 = analogRead(4);
  Wire.write((++sensorVal05)&0xff);
  Wire.write((sensorVal05>>8)&0xff);

  Serial.print("line 05 : ");
  Serial.println(sensorVal05);

}
