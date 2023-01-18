#include <stdbool.h>
#include<stdio.h>
#include<string.h>
#include <stdint.h>
#include <stddef.h>
#include "xc.h"
#include "display_clock.h"

#define MY_BUFFER_SIZE 500

#define SET_TIME_HEADER "SET\n"
#define READ_TIME_HEADER "READ\n"

#define HEADER_SIZE 100

typedef enum 
{
    INIT,
    IDLE,
    SET_TIME,
    CHECK_TIME,
    ERROR_MODE
} _Read_State;

static _Read_State message_handler_state = INIT;

void process_mesage (char *message,uint16_t message_length)
{
    if (message_length < HEADER_SIZE)
    {
   //     error;
    }
    char message_decode[message_length];
    memcpy(message_decode, message, message_length*sizeof(char));
    if(strcmp(message_decode,SET_TIME_HEADER)== 0)
    {
        printf("SET_TIME_HEADER\n");
        message_handler_state = SET_TIME;
    }
    if(strcmp(message_decode,READ_TIME_HEADER)== 0)
    {
        printf("Its me , ye i am the problem");
    }
 }


void message_handler_state_machine(void)
{
    switch (message_handler_state)
    {
        case INIT:
        {
            message_handler_state = IDLE;
            break;
        }
        case IDLE:
        {
            message_handler_state = IDLE;
            break;
        }
        case SET_TIME:
        {
            message_handler_state = IDLE;
            change_time();
            break;
        }
        
       
        }
}