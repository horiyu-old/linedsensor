//ラインセンサ　プログラム　master

#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(8, 2);    // request 2 bytes from slave device #8

  unsigned short sensorVal=0;
  
  while (Wire.available()) { // slave may send less than requested
    byte buf1 = Wire.read(); // receive a byte as character
    byte buf2 = Wire.read(); // receive a byte as character
    sensorVal = (buf2<<8)&0xff00|(buf1&0xff);
    Serial.print(sensorVal);         // print the character
    
    if(sensorVal <= 880){
      Serial.println(" : Green   line 01");
    }else{
      Serial.println(" : White   line 01");
    }
  
  }
  delay(20);

}
