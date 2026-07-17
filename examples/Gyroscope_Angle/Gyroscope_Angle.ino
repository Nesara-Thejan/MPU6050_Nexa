/*
  Example: Accelerometer Test

  Description:
  This example demonstrates how to read acceleration values
  from the MPU6050 using the MPU6050_Nexa library.
  The acceleration values are displayed in Degress.

  Author:
  Nesara Thejan

  Library:
  MPU6050_Nexa

  Version:
  1.0.0
*/

#include <MPU6050_Nexa.h>//Including the MPU6050_Nexa Libary//



MPU6050_Nexa mpu(0x68);

float x, y, z;

void setup()
{
  Serial.begin(9600);

  mpu.begin();

  mpu.calibrateGyro();//Calibrating the MPU6050//
}


void loop()
{
  mpu.getGyroAngle(x, y, z);


  Serial.print("Angle X = ");
  Serial.print(x);

  Serial.print("  Y = ");
  Serial.print(y);

  Serial.print("  Z = ");
  Serial.println(z);


  delay(50);
}