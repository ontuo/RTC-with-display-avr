#ifndef TWI_H
#define TWI_H

#include "main.h"

void i2c_init();
void i2c_start();
void i2c_stop();
void i2c_transmit( unsigned char data );
unsigned char i2c_receive();

#endif