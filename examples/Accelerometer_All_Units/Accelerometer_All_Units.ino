/*
  Example: Accelerometer Test

  Description:
  This example demonstrates how to read acceleration values
  from the MPU6050 using the MPU6050_Nexa library.
  
  Author:
  Nesara Thejan

  Library:
  MPU6050_Nexa

  Version:
  1.0.0
*/

#include <MPU6050_Nexa.h>


#include <MPU6050_Nexa.h>//Including MPU6050_Nexa Library//

MPU6050_Nexa mpu(0x68);

int16_t ax, ay, az;
float gx, gy, gz;
float mx, my, mz;

void setup()
{
  Serial.begin(9600);

  mpu.begin();
}

void loop()
{
  mpu.getAccelerationRAW(ax, ay, az);//Values in RAW Numbers//

  mpu.getAccelerationG(gx, gy, gz);//Values in G unit//

  mpu.getAccelerationMS2(mx, my, mz);//Values in ms-2 unit//


  Serial.println("RAW:");
  Serial.print(ax);
  Serial.print(" ");
  Serial.print(ay);
  Serial.print(" ");
  Serial.println(az);


  Serial.println("G:");
  Serial.print(gx);
  Serial.print(" ");
  Serial.print(gy);
  Serial.print(" ");
  Serial.println(gz);


  Serial.println("m/s2:");
  Serial.print(mx);
  Serial.print(" ");
  Serial.print(my);
  Serial.print(" ");
  Serial.println(mz);


  delay(1000);
}