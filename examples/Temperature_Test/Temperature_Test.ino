/*
  Example: Accelerometer Test

  Description:
  This example demonstrates how to read acceleration values
  from the MPU6050 using the MPU6050_Nexa library.
  The acceleration values are displayed in C,F,K units.

  Author:
  Nesara Thejan

  Library:
  MPU6050_Nexa

  Version:
  1.0.0
*/

#include <MPU6050_Nexa.h>//Including the MPU6050_Nexa Libary//

MPU6050_Nexa mpu(0x68);


void setup()
{
  Serial.begin(9600);

  mpu.begin();
}


void loop()
{
  Serial.print("Celsius: ");
  Serial.println(mpu.getTemperatureC());//Reading Values in Celsius unit//

  Serial.print("Fahrenheit: ");
  Serial.println(mpu.getTemperatureF());//Reading Values in Fahrenheit unit//

  Serial.print("Kelvin: ");
  Serial.println(mpu.getTemperatureK());//Reading Values in Kelvin unit//


  Serial.println();

  delay(1000);
}