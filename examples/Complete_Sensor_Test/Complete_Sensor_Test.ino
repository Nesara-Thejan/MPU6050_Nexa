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


#include <MPU6050_Nexa.h>//Including MPU6050_Nexa Library//

MPU6050_Nexa mpu(0x68);

float ax, ay, az;//acceleration variables//
float gx, gy, gz;//gyro variables//


void setup()
{
  Serial.begin(9600);

  mpu.begin();

  mpu.calibrateGyro();//Calibrating MPU6050//

  Serial.println("Ready");
}


void loop()
{
  mpu.getAccelerationG(ax, ay, az);//Reading accelaration values in G unit//

  mpu.getGyroDPS(gx, gy, gz);//Reading Gyro values in DPS unit//


  Serial.println("Acceleration");
  Serial.print(ax);
  Serial.print(" ");
  Serial.print(ay);
  Serial.print(" ");
  Serial.println(az);


  Serial.println("Gyro");
  Serial.print(gx);
  Serial.print(" ");
  Serial.print(gy);
  Serial.print(" ");
  Serial.println(gz);


  Serial.print("Temp: ");
  Serial.println(mpu.getTemperatureC());//Reading tepmeature in Celsius unit//


  Serial.println("----------------");

  delay(500);
}