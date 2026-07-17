/*
  Example: Accelerometer Test

  Description:
  This example demonstrates how to read acceleration values
  from the MPU6050 using the MPU6050_Nexa library.
  The acceleration values are displayed in dps units.

  Author:
  Nesara Thejan

  Library:
  MPU6050_Nexa

  Version:
  1.0.0
*/

#include <MPU6050_Nexa.h>//Inluding MPU6050_Nexa Library//


MPU6050_Nexa mpu(0x68);

float gx, gy, gz;

void setup()
{
  Serial.begin(9600);

  mpu.begin();

  Serial.println("Keep sensor still");
  delay(3000);

  mpu.calibrateGyro();//Calibarting MPU6050.//

  Serial.println("Calibration complete");
}


void loop()
{
  mpu.getGyroDPS(gx, gy, gz);//Values are in Degrees Per Second//


  Serial.print("GX = ");
  Serial.print(gx);

  Serial.print("  GY = ");
  Serial.print(gy);

  Serial.print("  GZ = ");
  Serial.println(gz);


  delay(100);
}