#ifndef TM1637_H
#define TM1637_H

#include <stdbool.h>
#include "main.h"

#define data_setting		0x40 //01000000
#define control_satting		0x88 //10001000
#define first_address		0xC0


void TM1637_init(int clock_p, int data_p);
void TM1637_start();
void TM1637_stop();
unsigned char TM1637_transmit_byte(unsigned char data);
void TM1637_transmit_data(unsigned char data, unsigned char address);
void TM1637_display_dec(int data, char position, bool colon);
void TM1637_clear();
#endif