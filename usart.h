#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <string.h>
#include <stdlib.h>

void usart_transmit_byte(unsigned char data);
void usart_init(unsigned long speed);
void usart_transmit_str(char* data);
void usart_transmit_dec(int data);
void usart_transmit_bin(unsigned char data);

unsigned char usart_receive();

#endif