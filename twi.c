#include "twi.h"

void i2c_init(){
	TWBR = 0x72;
}

void i2c_start(){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
}

void i2c_stop(){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void i2c_transmit( unsigned char data ){
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}

unsigned char i2c_receive(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}
