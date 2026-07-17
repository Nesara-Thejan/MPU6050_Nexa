/*
  MPU6050_Nexa Library

  A simple Arduino library for the MPU6050 sensor.
  Supports accelerometer, gyroscope, temperature,
  calibration and unit conversions.
  
  Date:  17/07/2026
  Author: Nesara Thejan
  Version: 1.0.0
*/


#include "MPU6050_Nexa.h"


MPU6050_Nexa::MPU6050_Nexa(byte address)
{
    _address = address;
}



void MPU6050_Nexa::begin()
{
    Wire.begin();

    // Wake up MPU6050
    writeRegister(0x6B,0x00);
}



void MPU6050_Nexa::writeRegister(byte reg, byte data)
{
    Wire.beginTransmission(_address);

    Wire.write(reg);
    Wire.write(data);

    Wire.endTransmission();
}



byte MPU6050_Nexa::readRegister(byte reg)
{
    Wire.beginTransmission(_address);

    Wire.write(reg);

    Wire.endTransmission(false);

    Wire.requestFrom(_address,1);

    return Wire.read();
}



int16_t MPU6050_Nexa::read16(byte reg)
{

    Wire.beginTransmission(_address);

    Wire.write(reg);

    Wire.endTransmission(false);


    Wire.requestFrom(_address,2);


    int16_t value = Wire.read()<<8;

    value |= Wire.read();


    return value;
}



// Accelerometer

int16_t MPU6050_Nexa::readAccelX()
{
    return read16(0x3B) - accelOffsetX;
}


int16_t MPU6050_Nexa::readAccelY()
{
    return read16(0x3D) - accelOffsetY;
}


int16_t MPU6050_Nexa::readAccelZ()
{
    return read16(0x3F) - accelOffsetZ;
}


// Gyroscope

int16_t MPU6050_Nexa::readGyroX()
{
    return read16(0x43);
}


int16_t MPU6050_Nexa::readGyroY()
{
    return read16(0x45);
}


int16_t MPU6050_Nexa::readGyroZ()
{
    return read16(0x47);
}



// Temperature

int16_t MPU6050_Nexa::readTemperature()
{
    return read16(0x41);
}

void MPU6050_Nexa::getAccelerationRAW(int16_t &x, int16_t &y, int16_t &z)
{
    x = readAccelX();
    y = readAccelY();
    z = readAccelZ();
}

void MPU6050_Nexa::getAccelerationG(float &x, float &y, float &z)
{
    int16_t ax, ay, az;

    getAccelerationRAW(ax, ay, az);

    x = ax / 16384.0;
    y = ay / 16384.0;
    z = az / 16384.0;
}
void MPU6050_Nexa::getAccelerationMS2(float &x, float &y, float &z)
{
    int16_t ax, ay, az;

    getAccelerationRAW(ax, ay, az);

    x = (ax * 9.80665) / 16384.0;
    y = (ay * 9.80665) / 16384.0;
    z = (az * 9.80665) / 16384.0;
}

void MPU6050_Nexa::calibrateAccel(uint16_t samples)
{
    long sumX = 0;
    long sumY = 0;
    long sumZ = 0;

    int16_t x,y,z;


    for(uint16_t i=0; i<samples; i++)
    {
        getAccelerationRAW(x,y,z);

        sumX += x;
        sumY += y;
        sumZ += z;

        delay(2);
    }


    accelOffsetX = sumX / samples;
    accelOffsetY = sumY / samples;

    // Z should be 1g when flat
    accelOffsetZ = (sumZ / samples) - 16384;
}

void MPU6050_Nexa::getGyroRAW(int16_t &x, int16_t &y, int16_t &z)
{
  x = read16(0x43) - gyroOffsetX;
  y = read16(0x45) - gyroOffsetY;
  z = read16(0x47) - gyroOffsetZ;
}
void MPU6050_Nexa::getGyroDPS(float &x, float &y, float &z)
{
    int16_t gx, gy, gz;

    getGyroRAW(gx, gy, gz);

    x = gx / 131.0f;
    y = gy / 131.0f;
    z = gz / 131.0f;
}
void MPU6050_Nexa::calibrateGyro(uint16_t samples)
{
    long sumX = 0;
    long sumY = 0;
    long sumZ = 0;

    int16_t x, y, z;


    for(uint16_t i = 0; i < samples; i++)
    {
        getGyroRAW(x, y, z);

        sumX += x;
        sumY += y;
        sumZ += z;

        delay(2);
    }


    gyroOffsetX = sumX / samples;
    gyroOffsetY = sumY / samples;
    gyroOffsetZ = sumZ / samples;
}

void MPU6050_Nexa::getGyroAngle(float &x, float &y, float &z)
{
    float gx, gy, gz;

    getGyroDPS(gx, gy, gz);

    unsigned long now = millis();

    if(lastGyroTime == 0)
    {
        lastGyroTime = now;
        x = gyroAngleX;
        y = gyroAngleY;
        z = gyroAngleZ;
        return;
    }

    float dt = (now - lastGyroTime) / 1000.0;

    lastGyroTime = now;

    gyroAngleX += gx * dt;
    gyroAngleY += gy * dt;
    gyroAngleZ += gz * dt;

    x = gyroAngleX;
    y = gyroAngleY;
    z = gyroAngleZ;
}

float MPU6050_Nexa::getTemperatureC()
{
    int16_t raw = readTemperature();

    return (raw / 340.0) + 36.53;
}


float MPU6050_Nexa::getTemperatureF()
{
    return (getTemperatureC() * 9.0 / 5.0) + 32.0;
}


float MPU6050_Nexa::getTemperatureK()
{
    return getTemperatureC() + 273.15;
}

