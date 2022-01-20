/******************************************************************************
  YFLineFollow.h
  YFROBOT Line Follow Sensor Library Source File
  Creation Date: 01-18-2022
  @ YFROBOT

  Distributed as-is; no warranty is given.
******************************************************************************/

#include "Arduino.h"
#include "sx1508.h"

#ifndef YFLINEFOLLOW_H
#define YFLINEFOLLOW_H

#define SX1508_ADDRESS 0x20  // I2C address

#define LINESENSOR1 0  // line sensor 1
#define LINESENSOR2 1  // line sensor 2
#define LINESENSOR3 2  // line sensor 3
#define LINESENSOR4 3  // line sensor 4
#define LINESENSOR5 4  // line sensor 5
#define LINESENSOREN 6  // line sensor enable pin 6
#define LINESENSORCS 7  // line sensor cs pin 7 - 默认不使用

class YFLINEFOLLOW
{
  public:
    YFLINEFOLLOW(uint8_t address = SX1508_ADDRESS);
    uint8_t begin(uint8_t address = SX1508_ADDRESS);
    uint8_t readSensor(uint8_t numSensor);       //读取传感器值
    void disableSensor();      //禁用传感器
    void enableSensor();       //使能传感器

  private:
    SX1508 _sx1508;
};


YFLINEFOLLOW::YFLINEFOLLOW(uint8_t address = SX1508_ADDRESS) {}

//初始化传感器
uint8_t YFLINEFOLLOW::begin(uint8_t address = SX1508_ADDRESS) {
  return  _sx1508.begin(address);
}

//读取传感器值
// numSensor : 0 1 2 3 4  ; 5路巡线传感器
uint8_t YFLINEFOLLOW::readSensor(uint8_t numSensor) {
  return _sx1508.digitalRead(numSensor);
}

//禁用传感器
void YFLINEFOLLOW::disableSensor() {
  _sx1508.pinMode(LINESENSOREN, OUTPUT);
  _sx1508.digitalWrite(LINESENSOREN, LOW);
}

//使能传感器
void YFLINEFOLLOW::enableSensor() {
  _sx1508.pinMode(LINESENSOREN, OUTPUT);
  _sx1508.digitalWrite(LINESENSOREN, HIGH);
}

#endif YFLINEFOLLOW_H
