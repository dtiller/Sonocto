#ifndef	_SONARCTOPUS_H

#define _SONARCTOPUS_H

#include <Arduino.h>
#include <Wire.h>

#define TIMER_CLOCK             500000.0f
#define SOUND_METERS_SEC_2      170.0f
#define SOUND_FEET_SEC_2        557.74f

// Change this _and_ the code in MPLAB-X to change the i2c addr range
// By default it's 0x20-0x3F.
#define I2C_UPPER_BITS	0x20
#define DEFAULT_I2C_ADDR I2C_UPPER_BITS

#define BENCHMARK 0
#define READ_DISTANCE 0x00
#define READ_MAXECHO  0x08
#define RW_CONFIG     0x10
#define REBOOT	      0x14
#define GET_VERSION   0x18
#define RW_MIN_MAX    0x20
#define RW_ENABLE     0x40
#define SET_I2C_ADDR  0x60
#define WRITE_MAXECHO 0x80

// Use w/ RW_MIN_MAX
#define MAX           0x10
#define RESET         0x08

// Use with RW_ENABLE
#define ENABLE        0x10
#define WRITE         0x08

// Use with RW_CONFIG
#define NV_CURRENT    0x00
#define DEF_NV        0x01
#define DEF_CURRENT   0x02
#define CURRENT_NV    0x03

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
    float SonoctoClass::getDistanceMeters(uint8_t i2cAddr, uint8_t channel);
    float SonoctoClass::getDistanceFeet(uint8_t i2cAddr, uint8_t channel);
    uint16_t reboot(uint8_t i2cAddr);
    uint16_t setI2CAddr(uint8_t i2cAddr, uint8_t newAddr);
    uint16_t getVersion(uint8_t i2cAddr);

  private:
    void writeI2C(uint8_t i2cAddr, uint8_t value);
    uint16_t readI2C(uint8_t i2cAddr);
};

extern SonoctoClass Sonocto; ///< instantiated by default

#endif

