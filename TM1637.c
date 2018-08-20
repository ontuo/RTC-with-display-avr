#include "TM1637.h"

int clock_pin = 7, data_pin = 6;

unsigned char digit[]= {0x3F, 0x06, 0x5B, 0x4F, 0x66,		//0-4
	0x6D, 0x7D, 0x07, 0x7F, 0x6F,		//5-9
	0x80								//point
};

void TM1637_display_dec(int data, char position, bool colon){
	TM1637_transmit_data(digit[data], first_address + position);
	if(colon){
		TM1637_transmit_data(digit[10], first_address + 2);
		TM1637_transmit_data(digit[10], first_address + 3);
	}
}

void TM1637_init(int clock_p, int data_p){
	DDRD = 0xFF; //выв
	PORTD = 0x00;
	clock_pin = clock_p;
	data_pin = data_p;
}

void TM1637_start(){
	PORTD |= (1<<clock_pin);
	PORTD |= (1<<data_pin);
	_delay_us(100);
	PORTD &= ~(1<<data_pin);
}

void TM1637_stop(){
	PORTD &= ~(1<<clock_pin);
	_delay_us(100);
	PORTD &= ~(1<<data_pin);
	_delay_us(100);
	PORTD |= 1<<clock_pin;
	_delay_us(100);
	PORTD |= 1<<data_pin;
	
}

unsigned char TM1637_transmit_byte(unsigned char data){
	unsigned char ACK=0, buf=data;
	for (int i = 0; i < 8; i++){
		PORTD &= ~(1<<clock_pin);
		if (buf & 0b000000001){       
			PORTD |= 1<<data_pin;
		}
		else{
			PORTD &= ~(1<<data_pin);
		}
		_delay_us(100);
		buf = buf>>1;
		PORTD |= 1<<clock_pin;
		_delay_us(100);
	}
	PORTD &= ~(1<<clock_pin);
	_delay_us(100);
	DDRD &= ~(1<<data_pin);
	while(PIND & (1>>data_pin ))ACK = PIND;
	DDRD |= (1<<data_pin);
	PORTD |= 1<<clock_pin;
	_delay_us(100);
	PORTD &= ~(1<<clock_pin);
	
	return ACK;
}

void TM1637_transmit_data(unsigned char data, unsigned char address){
	TM1637_start();
	TM1637_transmit_byte(data_setting);
	TM1637_stop();
	
	TM1637_start();
	TM1637_transmit_byte(address);
	TM1637_transmit_byte(data);
	TM1637_stop();
	
	TM1637_start();
	TM1637_transmit_byte(control_satting);
	TM1637_stop();
}

void TM1637_clear(){
	for (int i = 0; i < 4; i++){
		TM1637_transmit_data(0x00, first_address + i);
	}
}