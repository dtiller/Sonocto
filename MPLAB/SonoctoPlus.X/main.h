/* 
 * File:   main.h
 * Author: dtiller
 *
 * Created on April 3, 2019, 6:48 PM
 * 
 * Sonocto (tm) Controller v1.0
 * Usage:
 * write a single byte command to the device then read 2 bytes back as the
 * result.
 * 
 * Commands:
 * 0 0 0 0 0 A A A
 * Read distance for channel A A A
 * 
 * 0 0 0 0 1 A A A      
 * Read max echo limit for channel A A A
 * 
 * 0 0 0 1 0 0 [ 0 0 = NVRAM -> current  ]
 *             [ 0 1 = default -> MVRAM  ]
 *             [ 1 0 = default -> current]
 *             [ 1 1 = current -> NVRAM  ]
 * Manage current and NVRAM configuration for channel A A A
 * 
 * 0 0 0 1 0 1 x x 
 * Reboot device
 * 
 * Read Version
 * 0 0 0 1 1 0 x x 
 * 
 * 0 0 0 1 1 1 x x
 * Undefined
 * 
 * 0 0 1 [0=min/1=max] [0=read/1=reset] A A A
 * Read/reset min/max distance read for channel A A A
 * 
 * 0 1 0 [0=disable/1=enable] [0=read/1=write] A A A
 * Get/set enable/disable status for channel A A A
 * 
 * 0 1 1 b5 b4 b3 b2 b1
 * Set i2c address to 0 1 b4 b3 b2 b1 b0
 * (20, 21, ... 3F)
 * 
 * 1 [ X X X X ] [ A A A ]
 * Write max echo limit for channel A A A
 * 
 * Echo limit values:
 * 
    5.57m 0000
    5.22m 0001
    4.87m 0010 
    4.52m 0011
    4.18m 0100
    3.83m 0101
    3.48m 0110
    3.13m 0111
    2.79m 1000
    2.44m 1001
    2.09m 1010
    1.74m 1011
    1.39m 1100
    1.04m 1101
    0.70m 1110
    0.35m 1111
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "version.h"

#define CONFIG_SIZE         32
    
#define I2C_UPPER_BITS      0x20

#define READ_INDEX_EXCEEDED 0xf0
#define NO_ECHO             0xf1f1
#define NO_MODULE           0xf2f2
#define UNKNOWN_CMD         0xf3f3
#define CHANNEL_DISABLED    0xf4f4
#define TMR1_OVFL           0xf5f5
#define GATE_TIMEOUT        0xf6f6

#define CMD_READ_DISTANCE   0
#define CMD_READ_ECHOLIMIT  1
#define CMD_CONFIG          2
#define CMD_RESET           3
#define CMD_VERSION         4
#define CMD_UNDEF_05        5
#define CMD_MIN_MAX         6
#define CMD_ENABLE          7
#define CMD_I2C_ADDR        8
#define CMD_ECHO_LIM_WRITE  9

typedef union config {
    struct {
        volatile uint16_t i2cAddr;
        volatile uint16_t enabled;
        volatile uint16_t maxEchoLimit[8];
    } cfg;
    uint16_t dummy[WRITE_FLASH_BLOCKSIZE];
} config_t;

void initializeConfig(config_t *cfg);
uint8_t writeNVRAM(config_t *cfg);
void readNVRAM(void);
void mySlaveReadHandler(void);
void readDistance(uint8_t channel);
void readEchoLimit(uint8_t channel, uint8_t dataByte);
void readResetMinMaxStats(uint8_t channel, uint8_t dataByte);
void enableDisable(uint8_t channel, uint8_t dataByte);
void manageConfig(uint8_t channel, uint8_t dataByte);
void setEchoLimit(uint8_t channel, uint8_t dataByte);
void setI2CAddr(uint8_t channel, uint8_t dataByte);
void reboot(uint8_t channel, uint8_t dataByte);
void readVersion(uint8_t channel, uint8_t dataByte);
void mySlaveWriteHandler(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

