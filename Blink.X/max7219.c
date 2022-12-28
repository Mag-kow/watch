
/**************************************************************************//**
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
 * \file MAX7219.cpp
 ******************************************************************************/
 
/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/
#include "xc.h"
#include "max7219.h"

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

/******************************************************************************
 * Public method definitions.
 ******************************************************************************/


/**************************************************************************//**
 * \fn void MAX7219::setDecodeMode(DecodeModes mode)
 *
 * \brief Set MAX7219 decode mode.
 *
 * \param	mode	Decode mode to set.
 ******************************************************************************/
void setDecodeMode(DecodeMode_t mode)
{
    write(REG_DECODE_MODE, mode);
}

/**************************************************************************//**
 * \fn void MAX7219::setIntensity(Intensities intensity)
 *
 * \brief Set MAX7219 intensity.
 *
 * \param	itensity	Intensity to set.
 ******************************************************************************/
void setIntensity(Intensity_t intensity)
{
    write(REG_INTENSITY, intensity);
}

/**************************************************************************//**
 * \fn void MAX7219::setScanLimit(ScanLimits limit)
 *
 * \brief Set MAX7219 scan limit.
 *
 * \param	limit	Scan limit to set.
 ******************************************************************************/
void setScanLimit(ScanLimit_t limit)
{
    write(REG_SCAN_LIMIT, limit);
}

/**************************************************************************//**
 * \fn void MAX7219::setShutdownMode(ShutdownModes mode)
 *
 * \brief Set MAX7219 shutdown mode.
 *
 * \param	mode	Shutdown mode to set.
 ******************************************************************************/
void setShutdownMode(ShutdownMode_t mode)
{
    write(REG_SHUTDOWN, mode);
}

/**************************************************************************//**
 * \fn void MAX7219::setDisplayTestMode(DisplayTestModes mode)
 *
 * \brief Set MAX7219 display test mode.
 *
 * \param	mode	Display test mode to set.
 ******************************************************************************/
void setDisplayTestMode(DisplayTestMode_t mode)
{
    write(REG_DISPLAY_TEST, mode);
}

/**************************************************************************//**
 * \fn void MAX7219::writeDigit(
 * Digits       digit,
 * Characters   character,
 * bool         decimalPoint)
 *
 * \brief Write character on digit.
 *
 * \param	digit		    Digit to write.
 * \param	character	    Character to write.
 * \param   decimalPoint    Display decimal point if true.
 ******************************************************************************/
void writeDigit(Digit_t digit, Character_t  character)
{
    uint8_t value = character;
 
    write(digit, value);
}

/******************************************************************************
 * Private method definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn void MAX7219::write(byte address, byte value)
 *
 * \brief Write value into MAX7219 register.
 *
 * \param	address	Register address.
 * \param	value	Value to write.
 ******************************************************************************/
static void write(uint16_t address, uint16_t value)
{
    uint16_t Data_to_Transfer = ((uint16_t)address << 8 ) + (uint16_t)value;
    CS_PIN = SET_PIN_LOW;
    SPI1_Exchange16bit(Data_to_Transfer);
    CS_PIN = SET_PIN_HIGH;

}
/**************************************************************************//**
* setup
 ******************************************************************************/
 void setup_max7219(void)
 {
    // Turn off display test mode.
    setDisplayTestMode(NormalOperation);
    // Set scan limit.
    setScanLimit(ScanLimit_Digit0To3);
    // Set decode mode.
    setDecodeMode(DecodeMode_AllDigits);
    // Set intensity.
    setIntensity(Intensity_Level15);
    // Set shutdown mode.
    setShutdownMode(ShutdownMode_NormalOperation);
 }
 /**************************************************************************//**
* test digit
 ******************************************************************************/
 void test(void)
 {
    // Write digit 0 value.
    writeDigit(Digit_0, Character_Zero);
    // Write digit 1 value.
    writeDigit(Digit_1, Character_One);
    // Write digit 2 value.
    writeDigit(Digit_2, Character_Two);
    // Write digit 3 value.
    writeDigit(Digit_3, Character_Three);
 }