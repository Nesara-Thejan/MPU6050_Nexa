# MPU6050_Nexa

An Arduino library for the MPU6050 6-axis motion sensor.

MPU6050_Nexa provides simple functions to read:
- Accelerometer data
- Gyroscope data
- Temperature data

It also includes calibration functions and different unit conversions.

---

## Features

✅ Accelerometer RAW values  
✅ Acceleration in g units  
✅ Acceleration in m/s²  
✅ Gyroscope RAW values  
✅ Gyroscope speed in °/s  
✅ Gyroscope angle calculation  
✅ Gyroscope calibration  
✅ Accelerometer calibration  
✅ Temperature in Celsius, Fahrenheit and Kelvin  

---

# Installation

### Arduino IDE

1. Download this repository.
2. Extract the folder.
3. Place it inside:

```
Documents/Arduino/libraries/
```

4. Restart Arduino IDE.

The library will appear under:

```
Sketch → Include Library → MPU6050_Nexa
```

---

# Wiring

## Arduino UNO / Nano

| MPU6050 | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## Arduino Mega

| MPU6050 | Arduino |
|---|---|
| SDA | 20 |
| SCL | 21 |

---

# Basic Usage

```cpp
#include <MPU6050_Nexa.h>

MPU6050_Nexa mpu(0x68);

void setup()
{
  Serial.begin(9600);

  mpu.begin();
}

void loop()
{

}
```

The I2C address must be provided by the user.

Common addresses:

```
0x68 → AD0 LOW
0x69 → AD0 HIGH
```

---

# Functions

## Accelerometer

### getAccelerationRAW()

```cpp
mpu.getAccelerationRAW(x,y,z);
```

Returns raw accelerometer values.

---

### getAccelerationG()

```cpp
mpu.getAccelerationG(x,y,z);
```

Returns acceleration in g units.

---

### getAccelerationMS2()

```cpp
mpu.getAccelerationMS2(x,y,z);
```

Returns acceleration in meters per second squared.

---

## Gyroscope

### getGyroRAW()

```cpp
mpu.getGyroRAW(x,y,z);
```

Returns raw gyro values.

---

### getGyroDPS()

```cpp
mpu.getGyroDPS(x,y,z);
```

Returns angular velocity in degrees per second.

---

### getGyroAngle()

```cpp
mpu.getGyroAngle(x,y,z);
```

Returns calculated rotation angle.

Note:
Gyroscope angles can slowly drift over time.

---

## Calibration

### calibrateAccel()

```cpp
mpu.calibrateAccel();
```

Calibrates accelerometer offset.

Keep the sensor still during calibration.

---

### calibrateGyro()

```cpp
mpu.calibrateGyro();
```

Calibrates gyro bias.

Keep the sensor completely still during calibration.

---

## Temperature

### Celsius

```cpp
mpu.getTemperatureC();
```

Returns temperature in °C.

### Fahrenheit

```cpp
mpu.getTemperatureF();
```

Returns temperature in °F.

### Kelvin

```cpp
mpu.getTemperatureK();
```

Returns temperature in K.

---

# Examples

The library includes examples:

- Accelerometer_Test
- Accelerometer_Units
- Gyroscope_Test
- Gyro_Angle
- Temperature_Test
- Complete_Test

Open them from:

```
File → Examples → MPU6050_Nexa
```

---

# Author

Created by:

**Nesara Thejan**

---

# License

This project is licensed under the MIT License.