/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F15323
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TRIGGER aliases
#define TRIGGER_TRIS                 TRISAbits.TRISA2
#define TRIGGER_LAT                  LATAbits.LATA2
#define TRIGGER_PORT                 PORTAbits.RA2
#define TRIGGER_WPU                  WPUAbits.WPUA2
#define TRIGGER_OD                   ODCONAbits.ODCA2
#define TRIGGER_ANS                  ANSELAbits.ANSA2
#define TRIGGER_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define TRIGGER_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define TRIGGER_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define TRIGGER_GetValue()           PORTAbits.RA2
#define TRIGGER_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define TRIGGER_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define TRIGGER_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define TRIGGER_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define TRIGGER_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define TRIGGER_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define TRIGGER_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define TRIGGER_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED_OVFL aliases
#define LED_OVFL_TRIS                 TRISAbits.TRISA5
#define LED_OVFL_LAT                  LATAbits.LATA5
#define LED_OVFL_PORT                 PORTAbits.RA5
#define LED_OVFL_WPU                  WPUAbits.WPUA5
#define LED_OVFL_OD                   ODCONAbits.ODCA5
#define LED_OVFL_ANS                  ANSELAbits.ANSA5
#define LED_OVFL_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_OVFL_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_OVFL_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_OVFL_GetValue()           PORTAbits.RA5
#define LED_OVFL_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_OVFL_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_OVFL_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_OVFL_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_OVFL_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_OVFL_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_OVFL_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED_OVFL_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC0
#define SCL1_LAT                  LATCbits.LATC0
#define SCL1_PORT                 PORTCbits.RC0
#define SCL1_WPU                  WPUCbits.WPUC0
#define SCL1_OD                   ODCONCbits.ODCC0
#define SCL1_ANS                  ANSELCbits.ANSC0
#define SCL1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SCL1_GetValue()           PORTCbits.RC0
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC1
#define SDA1_LAT                  LATCbits.LATC1
#define SDA1_PORT                 PORTCbits.RC1
#define SDA1_WPU                  WPUCbits.WPUC1
#define SDA1_OD                   ODCONCbits.ODCC1
#define SDA1_ANS                  ANSELCbits.ANSC1
#define SDA1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SDA1_GetValue()           PORTCbits.RC1
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set LED_READ aliases
#define LED_READ_TRIS                 TRISCbits.TRISC2
#define LED_READ_LAT                  LATCbits.LATC2
#define LED_READ_PORT                 PORTCbits.RC2
#define LED_READ_WPU                  WPUCbits.WPUC2
#define LED_READ_OD                   ODCONCbits.ODCC2
#define LED_READ_ANS                  ANSELCbits.ANSC2
#define LED_READ_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED_READ_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED_READ_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED_READ_GetValue()           PORTCbits.RC2
#define LED_READ_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED_READ_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED_READ_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LED_READ_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LED_READ_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LED_READ_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LED_READ_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LED_READ_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set ADDR0 aliases
#define ADDR0_TRIS                 TRISCbits.TRISC3
#define ADDR0_LAT                  LATCbits.LATC3
#define ADDR0_PORT                 PORTCbits.RC3
#define ADDR0_WPU                  WPUCbits.WPUC3
#define ADDR0_OD                   ODCONCbits.ODCC3
#define ADDR0_ANS                  ANSELCbits.ANSC3
#define ADDR0_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define ADDR0_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define ADDR0_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define ADDR0_GetValue()           PORTCbits.RC3
#define ADDR0_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define ADDR0_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define ADDR0_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define ADDR0_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define ADDR0_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define ADDR0_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define ADDR0_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define ADDR0_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set ADDR1 aliases
#define ADDR1_TRIS                 TRISCbits.TRISC4
#define ADDR1_LAT                  LATCbits.LATC4
#define ADDR1_PORT                 PORTCbits.RC4
#define ADDR1_WPU                  WPUCbits.WPUC4
#define ADDR1_OD                   ODCONCbits.ODCC4
#define ADDR1_ANS                  ANSELCbits.ANSC4
#define ADDR1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define ADDR1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define ADDR1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define ADDR1_GetValue()           PORTCbits.RC4
#define ADDR1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define ADDR1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define ADDR1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define ADDR1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define ADDR1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define ADDR1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define ADDR1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define ADDR1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set ADDR2 aliases
#define ADDR2_TRIS                 TRISCbits.TRISC5
#define ADDR2_LAT                  LATCbits.LATC5
#define ADDR2_PORT                 PORTCbits.RC5
#define ADDR2_WPU                  WPUCbits.WPUC5
#define ADDR2_OD                   ODCONCbits.ODCC5
#define ADDR2_ANS                  ANSELCbits.ANSC5
#define ADDR2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define ADDR2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define ADDR2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define ADDR2_GetValue()           PORTCbits.RC5
#define ADDR2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define ADDR2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define ADDR2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define ADDR2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define ADDR2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define ADDR2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define ADDR2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define ADDR2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/