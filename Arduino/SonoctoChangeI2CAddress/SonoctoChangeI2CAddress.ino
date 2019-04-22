#include "Sonocto.h"

#define OLD_ADDRESS DEFAULT_I2C_ADDR
#define NEW_ADDRESS 0x21
void setup() {
  Sonocto.begin(400000);
  Serial.begin(115200);

  Serial.print("Changing Sonocto i2c address from "); Serial.print(OLD_ADDRESS); 
  Serial.print(" to "); Serial.print(NEW_ADDRESS); Serial.println(" in 10 seconds");
  delay(10000);
  uint16_t value = Sonocto.setI2CAddr(OLD_ADDRESS, NEW_ADDRESS);
  if (value != OLD_ADDRESS) {
    Serial.print("Address change failed: "); Serial.println(value);
    return;
  }
  
  Serial.println("Address changed successfully - writing config to NVRAM.");
  value = Sonocto.writeConfigToNVRAM(NEW_ADDRESS);
  if (value != 0) {
    Serial.println("Write to NVRAM failed: "); Serial.println(value);
    return;
  }

  Serial.print("Rebooting....");
  Sonocto.reboot(NEW_ADDRESS);
  Serial.println("Done.");
 
}

void loop() {
  Serial.println("Complete. Power off the module.");
  delay(2000);

}
