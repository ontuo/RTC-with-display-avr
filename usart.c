#include "usart.h"

void usart_init(unsigned long ubrr){
	if (ubrr == 115200) ubrr = 16;
	if (ubrr == 9600) ubrr = 207;
	if (ubrr == 19200) ubrr = 103;
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0B=(1<<RXEN0)|( 1<<TXEN0);
	UCSR0B |= (1<<RXCIE0); 
	UCSR0A |= (1<<U2X0);
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
}

void usart_transmit_byte(unsigned char data){
	while( !(UCSR0A &(1<<UDRE0)) );
	UDR0 = data;
}

unsigned char usart_receive(){
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void usart_transmit_str(char* data){
	int length = strlen(data);
	for(int i = 0; i< length; i++ ){
		usart_transmit_byte(data[i]);
	}
}


void usart_transmit_dec(int data){
	int length = 1 + 8*sizeof(int);
	char buf[length];
	itoa(data, buf, 10);
	usart_transmit_str(buf);
}


void usart_transmit_bin(unsigned char data){
	
}