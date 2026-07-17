//Arduino I2C Scanner.
//Created by B.A.N.Thejan.
//(16/07/2026)
//All Rights Reserved. 

#include <Wire.h>

void setup() {

  Serial.begin(9600);
  Serial.println("Aduino I2C Scanner by B.A.N.Thejan.");
  Serial.println("Scanning");
  delay(500);
  Serial.print(".");
  delay(500);
  Serial.print(".");
  delay(500);
  Serial.print(".");
  delay(500);
  Serial.println(".");
  delay(500);


   for (byte address = 1; address <= 128; address++) {
    Wire.beginTransmission(address);

    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.println(" ");
      Serial.println("Address found successfully ✅✅✅✅");
      Serial.print("Address is 0x");

      if (address < 16) {
        Serial.print("0");
        Serial.println(address,HEX);
        Serial.println(" ");
        Serial.println(" ");
        Serial.print("DONE");


      }

      else {
        Serial.println(address,HEX);
        Serial.println(" ");
        Serial.println(" ");
        Serial.print("DONE");
      }
    }

   
    
  }

  
  
}

void loop() {

 
}
