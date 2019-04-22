#include "Wire.h"
#include "Sonocto.h"

void SonoctoClass::begin(int speed) {
  Wire.begin();
  Wire.setClock(speed);
}

// Private methods

void SonoctoClass::writeI2C(uint8_t i2cAddr, uint8_t value) {
  Wire.beginTransmission(i2cAddr);
  Wire.write(value);
  Wire.endTransmission();
}

uint16_t SonoctoClass::readI2C(uint8_t i2cAddr) {
  Wire.requestFrom(i2cAddr, (uint8_t) 2);
  uint16_t value = 0xffaa;
  uint8_t count = 0;
  while (Wire.available()) {
    delay(1);
    uint8_t c = Wire.read();
    value *= 256;
    value += (c & 0xff);
    count++;
  }

  if (count != 2) {
    value = 0xe0e0;
  }

  return value;
}

// Public methods

uint16_t SonoctoClass::getEchoLimit(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, READ_MAXECHO | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::getMaxValue(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, RW_MIN_MAX | MAX | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::getMinValue(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, RW_MIN_MAX | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::resetMaxValue(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, RW_MIN_MAX | MAX | RESET | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::resetMinValue(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, RW_MIN_MAX | RESET | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::enableChannel(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, RW_ENABLE | ENABLE | WRITE | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::disableChannel(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, RW_ENABLE | WRITE | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::getEnabled(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, RW_ENABLE | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::readConfigFromNVRAM(uint8_t i2cAddr) {
  writeI2C(i2cAddr, RW_CONFIG);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::initializeConfigFromDefaults(uint8_t i2cAddr) {
  writeI2C(i2cAddr, RW_CONFIG | DEF_CURRENT);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::initializeNVRAMFromDefaults(uint8_t i2cAddr) {
  writeI2C(i2cAddr, RW_CONFIG | DEF_NV);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::writeConfigToNVRAM(uint8_t i2cAddr) {
  writeI2C(i2cAddr, RW_CONFIG | CURRENT_NV);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::setEchoLimit(uint8_t i2cAddr, uint8_t channel, uint16_t limit) {
  writeI2C(i2cAddr, WRITE_MAXECHO | ((limit & 0x0f) << 3) | channel);
  return readI2C(i2cAddr);
}

uint16_t SonoctoClass::getDistance(uint8_t i2cAddr, uint8_t channel) {
  writeI2C(i2cAddr, channel);
  return readI2C(i2cAddr); 
}

uint16_t SonoctoClass::reboot(uint8_t i2cAddr) {
  writeI2C(i2cAddr, REBOOT);
}

uint16_t SonoctoClass::setI2CAddr(uint8_t i2cAddr, uint8_t newAddr) {
  if (newAddr < I2C_UPPER_BITS || newAddr > I2C_UPPER_BITS + 0x1f) {
    return 0xffff;
  }
  writeI2C(i2cAddr, SET_I2C_ADDR | (newAddr & 0x1f));
  return readI2C(newAddr);
}
