/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include "xc.h" // include processor files - each processor file is guarded.  
#include "max7219.h"
#include "stdio.h"
typedef enum 
{
    Digit_0 = 0x01,
    Digit_1 = 0x02,
    Digit_2 = 0x03,
    Digit_3 = 0x04,
    Digit_4 = 0x05,
    Digit_5 = 0x06,
    Digit_6 = 0x07,
    Digit_7 = 0x08
} Digit_t;

typedef enum 
{
    Character_Zero  = 0x00,
    Character_One   = 0x01,
    Character_Two   = 0x02,
    Character_Three = 0x03,
    Character_Four  = 0x04,
    Character_Five  = 0x05,
    Character_Six   = 0x06,
    Character_Seven = 0x07,
    Character_Eight = 0x08,
    Character_Nine  = 0x09,
    Character_Dash  = 0x0A,
    Character_E     = 0x0B,
    Character_H     = 0x0C,
    Character_L     = 0x0D,
    Character_P     = 0x0E,
    Character_Blank = 0x0F
} Character_t;
/******************************************************************//**
 * Setup
 **********************************************************************/
 void setup_max7219(void);
/**************************************************************************//**
* test digit
 ******************************************************************************/
 void test(void);
   /**************************************************************************//**
* watch clock 1s timer 
 ******************************************************************************/
 void watch_clock_1s_timer(void);
    /**************************************************************************//**
* watch display time
 ******************************************************************************/
 void display_time(void);
 /**************************************************************************//**
* watch set time
 ******************************************************************************/
 void set_time(uint8_t hour, uint8_t minute, uint8_t second);
 
/**************************************************************************//**
* watch state machine
 ******************************************************************************/
 void display_clock_state_machine( void );
 
 /**************************************************************************//**
* change time
 ******************************************************************************/
 void change_time(void );
  
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

