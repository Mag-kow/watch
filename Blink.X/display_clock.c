/*
 * File:   display_clock.c
 * Author: kowal
 *
 * Created on December 29, 2022, 5:22 PM
 */


#include "xc.h"
#include "display_clock.h"
#include "max7219.h"
/******************************************************************************
 * typedef, structures, and variables.
 ******************************************************************************/
 typedef enum 
{
    SETUP_CLOCK,
    RUN_MODE,
    MODIFY_MODE,
    ERROR_MODE
} _Watch_State;

typedef struct _Real_Time{
     uint8_t seconds;
     uint8_t minutes;
     uint8_t hours;
}_Real_Time;

typedef struct _Clock{
    _Real_Time real_time;
    _Watch_State clock_state;
}_Clock;

 static _Clock clock =
 {
     .clock_state = SETUP_CLOCK,
     .real_time.seconds = 0,
     .real_time.minutes = 0,
     .real_time.hours = 0,
 };

 extern void writeDigit(Digit_t digit, Character_t  character);
  /**************************************************************************//**
* watch clock 1s timer 
 ******************************************************************************/
 void watch_clock_1s_timer(void)
 {
     if(clock.real_time.seconds < 60)
     {
         clock.real_time.seconds ++;
     }
     else
     {
        clock.real_time.seconds = 0;
        if (clock.real_time.minutes < 60)
        {
            clock.real_time.minutes ++;
        }
        else
        {
            clock.real_time.minutes = 0;
            if (clock.real_time.hours < 24)
            {
                clock.real_time.hours ++;
            }
            else
            {
                clock.real_time.hours = 0;
            }
        }
     }
 }
   /**************************************************************************//**
* watch display time
 ******************************************************************************/
 void display_time(void)
 {
    // Write digit 1m value.
    writeDigit(Digit_0, (uint8_t)(clock.real_time.seconds%10));
    // Write digit 10m value.
    writeDigit(Digit_1, (uint8_t)(clock.real_time.seconds/10));
    // Write digit 1h value.
    writeDigit(Digit_2, (uint8_t)(clock.real_time.minutes%10));
    // Write digit 10h value.
    writeDigit(Digit_3, (uint8_t)(clock.real_time.minutes/10));
}
 
/**************************************************************************//**
* watch set time
 ******************************************************************************/
 void set_time(uint8_t hour, uint8_t minute, uint8_t second)
 {
     clock.real_time.seconds = second;
     clock.real_time.minutes = minute;
     clock.real_time.hours = hour;
 }
 
/**************************************************************************//**
* watch state machine
 ******************************************************************************/
 
 void state_machine(void)
 {
     switch (clock.clock_state)
     {
         case SETUP_CLOCK:
         {
             setup_max7219();
             clock.clock_state = RUN_MODE;
             break;
         }  
         case RUN_MODE:
         {
            display_time();
            break;
         }
         case MODIFY_MODE:
         {
             clock.clock_state = RUN_MODE;
             uint8_t hour =0xC;
             uint8_t minute= 0x1E;
             uint8_t second = 0x0;
             set_time( hour,  minute,  second);
             break;
         }
         case ERROR_MODE:
         {
             break;
             //error mode
         }
                
     }
 }

