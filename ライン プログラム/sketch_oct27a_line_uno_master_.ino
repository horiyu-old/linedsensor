//ラインセンサ　プログラム　master

#include <Wire.h>

#define M1a 4
#define M1b 5
#define M2a 6
#define M2b 7
#define M3a 8
#define M3b 9
#define M4a 10
#define M4b 11

int x1a; //モータHIGH or LOW　　　a=正転　　b=逆転
int x1b;
int x2a;
int x2b;
int x3a;
int x3b;
int x4a;
int x4b;

short sensorVal01 = 0;
short sensorVal02 = 0;
short sensorVal03 = 0;
short sensorVal04 = 0;
short sensorVal05 = 0;



void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  
  if (sensorVal01 > 880) {
      x1a == 0;
      x1b == 200;
      x2a == 200;
      x2b == 0;
      x3a == 200;
      x3b == 0;
      x4a == 0;
      x4b == 200;
   }else if (sensorVal02 > 880) {
      x1a == 0;
      x1b == 200;
      x2a == 0;
      x2b == 200;
      x3a == 200;
      x3b == 0;
      x4a == 200;
      x4b == 0;
   }else if (sensorVal03 > 880) {
      x1a == 200;
      x1b == 0;
      x2a == 0;
      x2b == 200;
      x3a == 0;
      x3b == 200;
      x4a == 200;
      x4b == 0;
   }else if (sensorVal04 > 880) {
      x1a == 200;
      x1b == 0;
      x2a == 200;
      x2b == 0;
      x3a == 0;
      x3b == 200;
      x4a == 0;
      x4b == 200;
        }
    else if (sensorVal05 > 880) {

      //★★★超音波センサ読む★★★//
      
        }

  analogWrite(M1a, x1a);
  analogWrite(M1b, x1b);
  analogWrite(M2a, x2a);
  analogWrite(M2b, x2b);
  analogWrite(M3a, x3a);
  analogWrite(M3b, x3b);
  analogWrite(M4a, x4a);
  analogWrite(M4b, x4b);

  
  Wire.requestFrom(8, 2);    // request 2 bytes from slave device #8

  unsigned short sensorVal=0;
  
  while (Wire.available()) { // slave may send less than requested

//ラインセンサ01
    byte buf1 = Wire.read(); // receive a byte as character
    byte buf2 = Wire.read(); // receive a byte as character
    sensorVal01 = (buf2<<8)&0xff00|(buf1&0xff);
    Serial.print(sensorVal01);         // print the character
    
    if(sensorVal01 <= 880){
      Serial.println(" : Green   line 01");
    }else{
      Serial.println(" : White   line 01");
    }

    
//ラインセンサ02
    byte buf3 = Wire.read(); // receive a byte as character
    byte buf4 = Wire.read(); // receive a byte as character
    sensorVal02 = (buf4<<8)&0xff00|(buf3&0xff);
    Serial.print(sensorVal02);         // print the character
    
    if(sensorVal02 <= 880){
      Serial.println(" : Green   line 02");
    }else{
      Serial.println(" : White   line 02");
    }


//ラインセンサ03
    byte buf5 = Wire.read(); // receive a byte as character
    byte buf6 = Wire.read(); // receive a byte as character
    sensorVal03 = (buf6<<8)&0xff00|(buf5&0xff);
    Serial.print(sensorVal03);         // print the character
    
    if(sensorVal03 <= 880){
      Serial.println(" : Green   line 03");
    }else{
      Serial.println(" : White   line 03");
    }


//ラインセンサ04
    byte buf7 = Wire.read(); // receive a byte as character
    byte buf8 = Wire.read(); // receive a byte as character
    sensorVal04 = (buf8<<8)&0xff00|(buf7&0xff);
    Serial.print(sensorVal04);         // print the character
    
    if(sensorVal04 <= 880){
      Serial.println(" : Green   line 04");
    }else{
      Serial.println(" : White   line 04");
    }


//ラインセンサ05
    byte buf9 = Wire.read(); // receive a byte as character
    byte buf10 = Wire.read(); // receive a byte as character
    sensorVal05 = (buf10<<8)&0xff00|(buf9&0xff);
    Serial.print(sensorVal05);         // print the character
    
    if(sensorVal05 <= 880){
      Serial.println(" : Green   line 05");
    }else{
      Serial.println(" : White   line 05");
    }
  
  }

  delay(20);

}
