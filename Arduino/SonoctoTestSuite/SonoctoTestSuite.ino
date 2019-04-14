#include "Sonocto.h"

#define ADDR  0x08

uint8_t test(char *msg, uint8_t t) {
  if (!t) {
    Serial.println(msg);
  }

  return t;
}

void testEnableDisableChannel(void) {
  Serial.println("In testEnableDisableChannel...");
  for (int i = 0; i < 8; i++) {
    Sonocto.enableChannel(ADDR, i);
    uint16_t value = Sonocto.getEnabled(ADDR, i);
    test("channel should be enabled", value == 1);
    Sonocto.disableChannel(ADDR, i);
    value = Sonocto.getEnabled(ADDR, i);
    test("channel should be disabled", value == 0);
  }
}

void testGetSetMaxEcho(void) {
  Serial.println("In testGetSetMaxEcho...");
  for (int i = 0; i < 8; i++) {
    Sonocto.setEchoLimit(ADDR, i, i);
    uint16_t value = Sonocto.getEchoLimit(ADDR, i);
    test("channel echoLimit incorrect", value == i);
    
  }
}

void testInitConfigFromDefaults(void) {
  Serial.println("In testInitConfigFromDefaults...");
  for (int i = 0; i < 8; i++) {
    Sonocto.setEchoLimit(ADDR, i, i);
    Sonocto.disableChannel(ADDR, i);
    uint16_t value = Sonocto.getEchoLimit(ADDR, i);
    test("channel echoLimit incorrect", value == i);
    value = Sonocto.getEnabled(ADDR, i);
    test("channel should be disabled", value == 0);
  }

  Sonocto.initializeConfigFromDefaults(ADDR);

  for (int i = 0; i < 8; i++) {
    uint16_t value = Sonocto.getEchoLimit(ADDR, i);
    test("channel echoLimit incorrect", value == 0x0f);
    value = Sonocto.getEnabled(ADDR, i);
    test("channel should be enabled", value == 1);
  }
}

void verifyConfig(boolean defaults) {

  for (int i = 0; i < 8; i++) {
    uint16_t limit = Sonocto.getEchoLimit(ADDR, i);
    uint16_t enabled = Sonocto.getEnabled(ADDR, i);
    
    if (defaults) {
      test("default channel echoLimit incorrect", limit == 0x0f);
      test("default channel enabled bit incorrect", enabled == 1);
    } else {
      test("channel echoLimit incorrect", limit == i);
      test("channel enabled bit incorrect", enabled == 0);
    }
  }
}

void testNVRAM(void) {
  Serial.println("In testNVRAM...");
  for (int i = 0; i < 8; i++) {
    // Step 1: Set config to known state
    Sonocto.setEchoLimit(ADDR, i, i);
    Sonocto.disableChannel(ADDR, i);
  }

  verifyConfig(false);

  // Step 2: Write to to NVRAM and verify config is still ok
  Sonocto.writeConfigToNVRAM(ADDR);

  verifyConfig(false);
  
  // Step 3: Init config from defaults and verify
  Sonocto.initializeConfigFromDefaults(ADDR);
  verifyConfig(true);

  // Step 4: Read config from NVRAM and verify
  Sonocto.readConfigFromNVRAM(ADDR);
  verifyConfig(false);
}

void testDisabledChannelReturnValue(void) {
  Serial.println("In testDisabledChannelReturnValue...");
  for (int i = 0; i < 8; i++) {
    Sonocto.disableChannel(ADDR, i);
    uint16_t value = Sonocto.getDistance(ADDR, i);
    test("Returned value from disabled channel should be 0xf4f4", value == 0xf4f4);
  }
}

uint16_t testGetDistance(void) {
  Serial.println("In testGetDistance...");
  uint16_t value;
    Sonocto.initializeConfigFromDefaults(ADDR);
    
    while (1) {
      value = Sonocto.getDistance(ADDR, 0);
      if (!test("Returned distance from sensor 0 should be 0-16383. Make it so.", value < 16384 && value > 0)) {
        delay(1000);
      } else {
        break;
      }
    }

    return value;
}

void testMinMaxDistance() {
  Serial.println("In testMinMaxDistance...");
  Sonocto.resetMaxValue(ADDR, 0);
  Sonocto.resetMinValue(ADDR, 0);

  uint16_t value = Sonocto.getMaxValue(ADDR, 0);
  test("Max value should be 0", value == 0);

  value = Sonocto.getMinValue(ADDR, 0);
  test("Min value should be 0xffff", value == 0xffff);
  
  // Get a reading on sensor 0

  uint16_t dist = testGetDistance();
  
  value = Sonocto.getMaxValue(ADDR, 0);
  test("Max value incorrect", value == dist);

  value = Sonocto.getMinValue(ADDR, 0);
  test("Min value incorrect", value == dist);
}

void setup() {
  Sonocto.begin(400000);
  Serial.begin(115200);
}
  
void loop() {
    testEnableDisableChannel();
    testGetSetMaxEcho();
    testInitConfigFromDefaults();
    testNVRAM();
    testDisabledChannelReturnValue();
    testGetDistance();
    testMinMaxDistance();
    delay(2000);
//  }
}
