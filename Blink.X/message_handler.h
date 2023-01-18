/* 
 * File:   message_handler.h
 * Author: kowal
 *
 * Created on January 18, 2023, 1:31 PM
 */

#ifndef MESSAGE_HANDLER_H
#define	MESSAGE_HANDLER_H

#include <stdbool.h>
#include<stdio.h>
#include<string.h>
#include <stdint.h>
#include <stddef.h>
#include "xc.h"
#include "mcc_generated_files/uart1.h"

void process_mesage (char *message,uint16_t message_length);
void message_handler_state_machine(void);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MESSAGE_HANDLER_H */

