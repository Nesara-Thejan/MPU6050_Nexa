/*
  MPU6050_Nexa Library

  A simple Arduino library for the MPU6050 sensor.
  Supports accelerometer, gyroscope, temperature,
  calibration and unit conversions.
  
  Date:  17/07/2026
  Author: Nesara Thejan
  Version: 1.0.0
*/


#ifndef MPU6050_Nexa_h
#define MPU6050_Nexa_h

#include <Arduino.h>
#include <Wire.h>


class MPU6050_Nexa
{

public:

    MPU6050_Nexa(byte address);

    void begin();

    int16_t readAccelX();
    int16_t readAccelY();
    int16_t readAccelZ();
    
    void getAccelerationRAW(int16_t &x, int16_t &y, int16_t &z);
    void getAccelerationG(float &x, float &y, float &z);
    void getAccelerationMS2(float &x, float &y, float &z);
    void calibrateAccel(uint16_t samples = 500);
    void getGyroRAW(int16_t &x, int16_t &y, int16_t &z);
    void getGyroDPS(float &x, float &y, float &z);
    void calibrateGyro(uint16_t samples = 500);
    void getGyroAngle(float &x, float &y, float &z);
   
   

    int16_t readGyroX();
    int16_t readGyroY();
    int16_t readGyroZ();

    int16_t readTemperature();
    float getTemperatureC();
    float getTemperatureF();
    float getTemperatureK();

    


private:

    byte _address;

    void writeRegister(byte reg, byte data);

    byte readRegister(byte reg);

    int16_t read16(byte reg);

    int16_t accelOffsetX = 0;
    int16_t accelOffsetY = 0;
    int16_t accelOffsetZ = 0;

    int16_t gyroOffsetX = 0;
    int16_t gyroOffsetY = 0;
    int16_t gyroOffsetZ = 0;

    float gyroAngleX = 0;
    float gyroAngleY = 0;
    float gyroAngleZ = 0;

    unsigned long lastGyroTime = 0;

  

};


#endif