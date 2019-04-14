#ifndef	_SONARCTOPUS_H

#define _SONARCTOPUS_H

#include <Arduino.h>
#include <Wire.h>

#define DEBUG_SONAR   0

#define BENCHMARK 0
#define READ_DISTANCE 0x00
#define READ_MAXECHO  0x08
#define RW_MIN_MAX    0x20
#define RW_ENABLE     0x40
#define RW_CONFIG     0x60
#define WRITE_MAXECHO 0x80

// Use w/ RW_MIN_MAX
#define MAX           0x10
#define RESET         0x08

// Use with RW_ENABLE
#define ENABLE        0x10
#define WRITE         0x08

// Use with RW_CONFIG
#define NV_CURRENT    0x00
#define DEF_NV        0x08
#define DEF_CURRENT   0x10
#define CURRENT_NV    0x18

class SonoctoClass {
  public:
    void begin(int speed=100000);
    uint16_t getEchoLimit(uint8_t i2cAddr, uint8_t channel);
    uint16_t getMaxValue(uint8_t i2cAddr, uint8_t channel);
    uint16_t getMinValue(uint8_t i2cAddr, uint8_t channel);
    uint16_t resetMaxValue(uint8_t i2cAddr, uint8_t channel);
    uint16_t resetMinValue(uint8_t i2cAddr, uint8_t channel);
    uint16_t enableChannel(uint8_t i2cAddr, uint8_t channel);
    uint16_t disableChannel(uint8_t i2cAddr, uint8_t channel);
    uint16_t getEnabled(uint8_t i2cAddr, uint8_t channel);
    uint16_t readConfigFromNVRAM(uint8_t i2cAddr);
    uint16_t initializeConfigFromDefaults(uint8_t i2cAddr);
    uint16_t initializeNVRAMFromDefaults(uint8_t i2cAddr);
    uint16_t writeConfigToNVRAM(uint8_t i2cAddr);
    uint16_t setEchoLimit(uint8_t i2cAddr, uint8_t channel, uint16_t limit);
    uint16_t getDistance(uint8_t i2cAddr, uint8_t channel);

  private:
    void writeI2C(uint8_t i2cAddr, uint8_t value);
    uint16_t readI2C(uint8_t i2cAddr);
};

extern SonoctoClass Sonocto; ///< instantiated by default

#endif

