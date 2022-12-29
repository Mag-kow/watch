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


//**************************************************************************//**
/*
 * \brief MAX7219 library for Arduino
 * \author Copyright (C) 2011  Julien Le Sech - www.idreammicro.com
 * \version 1.0
 * \date 20110801
 *
 * This file is part of the MAX7219 library for Arduino.
 *
 * This library is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 * 
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/
 ******************************************************************************/

/**************************************************************************//**
 * \headerfile MAX7219.h
 ******************************************************************************/
 
#ifndef MAX7219_h
#define MAX7219_h

/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

/******************************************************************//**
 * \enum DecodeModes
 * \typedef DecodeMode_t
 **********************************************************************/
#include "xc.h" // include processor files - each processor file is guarded.  
#include "mcc_generated_files/spi1.h"

#define CS_PIN _LATB15
#define SET_PIN_LOW 0
#define SET_PIN_HIGH 1
/******************************************************************************
 * Private macros.
 ******************************************************************************/

#define REG_NO_OP           0x00
#define REG_DIGIT_0         0x01
#define REG_DIGIT_1         0x02
#define REG_DIGIT_2         0x03
#define REG_DIGIT_3         0x04
#define REG_DIGIT_4         0x05
#define REG_DIGIT_5         0x06
#define REG_DIGIT_6         0x07
#define REG_DIGIT_7         0x08
#define REG_DECODE_MODE     0x09
#define REG_INTENSITY       0x0A
#define REG_SCAN_LIMIT      0x0B
#define REG_SHUTDOWN        0x0C
#define REG_DISPLAY_TEST    0x0F

/******************************************************************//**
 * \enum Digits
 * \typedef Digit_t
 **********************************************************************/
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
    DecodeMode_NoDecode     = 0x00,
    DecodeMode_Digit0       = 0x01,
    DecodeMode_Digit1       = 0x02,
    DecodeMode_Digit2       = 0x04,
    DecodeMode_Digit3       = 0x08,
    DecodeMode_Digit4       = 0x10,
    DecodeMode_Digit5       = 0x20,
    DecodeMode_Digit6       = 0x40,
    DecodeMode_Digit7       = 0x80,
    DecodeMode_AllDigits    = 0xFF
} DecodeMode_t;

/******************************************************************//**
 * \enum DecodeModes
 * \typedef DecodeMode_t
 **********************************************************************/
typedef enum 
{
    Intensity_Level0    = 0x00,
    Intensity_Level1    = 0x01,
    Intensity_Level2    = 0x02,
    Intensity_Level3    = 0x03,
    Intensity_Level4    = 0x04,
    Intensity_Level5    = 0x05,
    Intensity_Level6    = 0x06,
    Intensity_Level7    = 0x07,
    Intensity_Level8    = 0x08,
    Intensity_Level9    = 0x09,
    Intensity_Level10   = 0x0A,
    Intensity_Level11   = 0x0B,
    Intensity_Level12   = 0x0C,
    Intensity_Level13   = 0x0D,
    Intensity_Level14   = 0x0E,
    Intensity_Level15   = 0x0F
} Intensity_t;

/******************************************************************//**
 * \enum ScanLimits
 * \typedef ScanLimit_t
 **********************************************************************/
typedef enum 
{   
    ScanLimit_Digit0    = 0x00,
    ScanLimit_Digit0To1 = 0x01,
    ScanLimit_Digit0To2 = 0x02,
    ScanLimit_Digit0To3 = 0x03,
    ScanLimit_Digit0To4 = 0x04,
    ScanLimit_Digit0To5 = 0x05,
    ScanLimit_Digit0To6 = 0x06,
    ScanLimit_Digit0To7 = 0x07
} ScanLimit_t;

/******************************************************************//**
 * \enum ShutdownModes
 * \typedef ShutdownMode_t
 **********************************************************************/
typedef enum 
{
    ShutdownMode_Shutdown           = 0x00,
    ShutdownMode_NormalOperation    = 0x01
} ShutdownMode_t;

/******************************************************************//**
 * \enum DisplayTestModes
 * \typedef DisplayTestMode_t
 **********************************************************************/
typedef enum 
{
    NormalOperation = 0x00,
    TestMode        = 0x01
} DisplayTestMode_t;


/******************************************************************//**
 * \enum Characters
 * \typedef Character_t
 **********************************************************************/
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
 * \fn void setDecodeMode(DecodeModes mode)
 *
 * \brief Set MAX7219 decode mode.
 *
 * \param	mode	Decode mode to set.
 **********************************************************************/
void setDecodeMode(DecodeMode_t mode);

/******************************************************************//**
 * \fn void setIntensity(Intensities intensity)
 *
 * \brief Set MAX7219 intensity.
 *
 * \param	itensity	Intensity to set.
 **********************************************************************/
void setIntensity(Intensity_t intensity);

/******************************************************************//**
 * \fn void setScanLimit(ScanLimits limit)
 *
 * \brief Set MAX7219 scan limit.
 *
 * \param	limit	Scan limit to set.
 **********************************************************************/
void setScanLimit(ScanLimit_t limit);

/******************************************************************//**
 * \fn void setShutdownMode(ShutdownModes mode)
 *
 * \brief Set MAX7219 shutdown mode.
 *
 * \param	mode	Shutdown mode to set.
 **********************************************************************/
void setShutdownMode(ShutdownMode_t mode);

/******************************************************************//**
 * \fn void setDisplayTestMode(DisplayTestModes mode)
 *
 * \brief Set MAX7219 display test mode.
 *
 * \param	mode	Display test mode to set.
 **********************************************************************/
void setDisplayTestMode(DisplayTestMode_t mode);

/******************************************************************//**
 * \fn void writeDigit(
 * Digits       digit,
 * Characters   character,
 *
 * \brief Write character on digit.
 *
 * \param	digit		    Digit to write.
 * \param	character	    Character to write.
 **********************************************************************/
extern void writeDigit(Digit_t digit, Character_t  character);


/******************************************************************//**
 * \fn void write(byte address, byte value)
 *
 * \brief Write value into MAX7219 register.
 *
 * \param	address	Register address.
 * \param	value	Value to write.
 **********************************************************************/
static void write(uint16_t address, uint16_t value);

/**************************************************************************//**
* setup
 ******************************************************************************/
 void setup_max7219(void);
 /**************************************************************************//**
* test digit
 ******************************************************************************/
 void test(void);
#endif // MAX7219_h
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

