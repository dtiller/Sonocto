/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F15325
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/drivers/i2c_slave.h"

#include "main.h"

volatile uint16_t timerValue = 0;
volatile uint8_t count = 0;
volatile uint8_t waitForGate[8] = {0, 0, 0, 0, 0, 0, 0, 0};

volatile uint16_t maxReading[8] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile uint16_t minReading[8] = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff};

const uint16_t SAF_ADDR = END_FLASH - CONFIG_SIZE;

config_t config;

void initializeConfig(config_t *cfg) {
    for (uint8_t i = 0; i < 8; i++) {
        cfg->cfg.enabled[i] = 1;
        cfg->cfg.maxEchoLimit[i] = 0x0f;
    }
}

uint8_t writeNVRAM(config_t *cfg) {
    return FLASH_WriteBlock(SAF_ADDR, cfg->dummy);
}

void readNVRAM(void) {
    uint16_t temp = FLASH_ReadWord(SAF_ADDR);
    if ((temp & 0x3f00) != 0) {
        // NVRAM not initialized - let's write the defaults in.
        writeNVRAM(&config);
    } else {
        for (uint8_t i = 0; i < WRITE_FLASH_BLOCKSIZE; i++) {
            config.dummy[i] = FLASH_ReadWord(SAF_ADDR + i);
        }
    }
}

// Read from the perspective of the SLAVE
void mySlaveReadHandler(void) {
    count = 0;
    LED_READ_SetHigh();
    
    uint8_t dataByte = i2c1_driver_getRXData();
    uint8_t channel = (dataByte & 0x07);
    uint8_t command;
    if (dataByte & 0x80) {
        command = CMD_ECHO_LIM_WRITE;
    } else if ((dataByte & 0xe0) == 0) {
        // 5 bit command
        command = (dataByte >> 3) & 0x03;
    } else {
        command = ((dataByte >> 5) & 0x03) + 3;
    }
    
    switch (command) {
        case CMD_READ_DISTANCE:
            readDistance(channel);
            break;
        case CMD_READ_ECHOLIMIT:
            readEchoLimit(channel, dataByte);
            break;
        case CMD_MIN_MAX:
            readResetMinMaxStats(channel, dataByte);
            break;
        case CMD_ENABLE:
            enableDisable(channel, dataByte);
            break;
        case CMD_CONFIG:
            manageConfig(channel, dataByte);
            break;
        case CMD_ECHO_LIM_WRITE:
            setEchoLimit(channel, dataByte);
            break;
        case CMD_UNDEF_02:
        case CMD_UNDEF_03:
        default:
            timerValue = UNKNOWN_CMD;
            break;          
    }
}

// [ 0 0 0 0 0 ] [ A A A ]
void readDistance(uint8_t channel) {
    // Set Up mux/demux
    //LATC = (LATC & 0xc7) | value;
    if (config.cfg.enabled[channel] == 0) {
        timerValue = CHANNEL_DISABLED;
        return;
    }
    
    LATCbits.LATC3 = channel & 0x01;
    LATCbits.LATC4 = (channel >> 1) & 0x01;
    LATCbits.LATC5 = (channel >> 2) & 0x01;
    
    if (waitForGate[channel]) {
        while (TMR1_CheckGateValueStatus()) ;
    }
    
    TMR1_WriteTimer(0x0000);
    //TMR0_WriteTimer(0x0000);
    TMR0_WriteTimer(0xFFFF - ((config.cfg.maxEchoLimit[channel] + 1) << 10) + 1);
    TMR0_StartTimer();
    TMR1_StartTimer();
    TMR1_StartSinglePulseAcquisition();
    
    TRIGGER_SetHigh();
    __delay_us(10);
    TRIGGER_SetLow();
    
    while (!TMR1_HasOverflowOccured() && !TMR0_HasOverflowOccured() &&
            T1GCONbits.GGO_nDONE == 1) ;
    
    TMR0_StopTimer();
    TMR1_StopTimer();
    
    waitForGate[channel] = 0;
    
    uint16_t t = TMR1_ReadTimer();
    if (TMR0_HasOverflowOccured()) {
        if (t == 0) {
            timerValue = NO_MODULE;
        } else {
            timerValue = NO_ECHO;
            waitForGate[channel] = 1;
            LED_OVFL_SetHigh();
        }
    } else if (TMR1_HasOverflowOccured()) {
        timerValue = TMR1_OVFL;
        waitForGate[channel] = 1;
        LED_OVFL_SetHigh();
    } else {
        timerValue = t;
        if (t > maxReading[channel]) maxReading[channel] = t;
        if (t < minReading[channel]) minReading[channel] = t;
        
        LED_OVFL_SetLow();
    }
    
    PIR0bits.TMR0IF = 0;
    PIR4bits.TMR1IF = 0;
}

// [ 0 0 0 0 1 ] [ A A A ]
void readEchoLimit(uint8_t channel, uint8_t dataByte) {
    timerValue = config.cfg.maxEchoLimit[channel];
}

// [ 0 0 1 ] [ 0 = min 1 = max ] [ = 0 read 1 = reset] [ A A A ]
void readResetMinMaxStats(uint8_t channel, uint8_t dataByte) {
    uint8_t max = dataByte & 0x10;
    if (dataByte & 0x08) {
        timerValue = 0;
        // RESET
        if (max) {
            maxReading[channel] = 0;
        } else {
            minReading[channel] = 0xffff;
        }
    } else {
        if (max) {
            timerValue = maxReading[channel];
        } else {
            timerValue = minReading[channel];
        }
    }
}

// [ 0 1 0 ] [ 0 = disable 1 = enable] [ 0 = read 1 = write ] [ A A A ]
void enableDisable(uint8_t channel, uint8_t dataByte) {
    // Always return the previous value
    timerValue = config.cfg.enabled[channel];
    if (dataByte & 0x08) {
        config.cfg.enabled[channel] = (dataByte >> 4) & 0x01;
    }
}

// [ 0 1 1 ] [ X Y ] [ A A A ]
// X Y Action
// 0 0 Copy NVRAM --> current config
// 0 1 Set NVRAM config to default values
// 1 0 Set current config to default values
// 1 1 Copy current config to NVRAM
void manageConfig(uint8_t channel, uint8_t dataByte) {
    uint8_t action = (dataByte >> 3) & 0x03;
    timerValue = 0;
    switch (action) {
        case 0:
            readNVRAM();
            break;
        case 1:
        { config_t localConfig;
            initializeConfig(&localConfig);
            writeNVRAM(&localConfig);
            break;
        }
        case 2:
            initializeConfig(&config);
            break;
        case 3:
            writeNVRAM(&config);
            break;
    }
}

// [ 1 ] [ X X X X ] [ A A A ]
void setEchoLimit(uint8_t channel, uint8_t dataByte) {
    uint8_t limit = (dataByte >> 3) & 0x0f;
    timerValue = config.cfg.maxEchoLimit[channel];
    config.cfg.maxEchoLimit[channel] = limit;
}

// Write from the perspective of the SLAVE
void mySlaveWriteHandler(void) {
    //if (i2c1_driver_isNACK() == 1) return;
    if (i2c1_driver_isData() == 1 && i2c1_driver_isNACK() == 1) return;
    
    switch (count) {
        case 0:
            i2c1_driver_TXData((timerValue >> 8) & 0xff);
            count++;
            break;
        case 1:
            i2c1_driver_TXData(timerValue & 0xff);
            count++;
            LED_READ_SetLow();
            break;
        default:
            i2c1_driver_TXData(READ_INDEX_EXCEEDED);
            break;
    }       
}

void startupLights(void) {
    // Blink at the same time if WDT fired, alternately if not
    // Check for WDT reset
    
    LED_READ_SetLow();

    if (__timeout == 0) {
        LED_OVFL_SetLow();
    } else {
        LED_OVFL_SetHigh();
    }
    
    TMR0_WriteTimer(0x0000);
    TMR0_StartTimer();
    
    for (int i = 0; i < 10; i++) {
        while (!TMR0_HasOverflowOccured()) ;
        PIR0bits.TMR0IF = 0;
        LED_OVFL_Toggle();
        LED_READ_Toggle();
    }
    
    TMR0_StopTimer();
    LED_OVFL_SetLow();
    LED_READ_SetLow();
}

/*
                         Main application
 */
void main(void)
{   
    // initialize the device
    SYSTEM_Initialize();
    
    startupLights();
    
    initializeConfig(&config);
    
    readNVRAM();
    
    i2c_slave_open();
    i2c_slave_setWriteIntHandler(mySlaveWriteHandler);
    i2c_slave_setReadIntHandler(mySlaveReadHandler);
    i2c1_driver_start();    // Sets SEN = 1
    mssp1_enableIRQ();      // Sets SSP1IE = 1
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
      
    while (1)
    {
        CLRWDT();
    }
}
/**
 End of File
*/