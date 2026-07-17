/*
  Example: Accelerometer Test

  Description:
  This example demonstrates how to read acceleration values
  from the MPU6050 using the MPU6050_Nexa library.
  The acceleration values are displayed in G units.

  Author:
  Nesara Thejan

  Library:
  MPU6050_Nexa

  Version:
  1.0.0
*/


#include <MPU6050_Nexa.h>//including MPU6050_Nexa Lbrary//

MPU6050_Nexa mpu(0x68);//Address of the MPU 6050, Use (0x68) or (0x69).If you want to scan the I2C address use the I2C scanner in examples.//

float ax, ay, az; 
                
void setup()
{
  Serial.begin(9600);

  mpu.begin();

  Serial.println("MPU6050 Accelerometer Test");
}

void loop()
{
  mpu.getAccelerationG(ax, ay, az);//reading Values.//
  //If you want values in ms-2 unit.Use getAccelerationMS2();//
  
  Serial.print("X = ");
  Serial.print(ax);
  Serial.print(" G   ");

  Serial.print("Y = ");
  Serial.print(ay);
  Serial.print(" G   ");

  Serial.print("Z = ");
  Serial.print(az);
  Serial.println(" G ");

  delay(500);
}