#include "RTC.h"


void set_clock(struct mDate* date){
	i2c_start();
	i2c_transmit(RTC_i2c_W);
	i2c_transmit(SEC_ADDRESS);
	i2c_transmit(date->sec);
	i2c_stop();
	
	i2c_start();
	i2c_transmit(RTC_i2c_W);
	i2c_transmit(MIN_ADDRESS);
	i2c_transmit(date->min);
	i2c_stop();
	
	i2c_start();
	i2c_transmit(RTC_i2c_W);
	i2c_transmit(HOUR_ADDRESS);
	i2c_transmit(date->hour);
	i2c_stop();
	
	i2c_start();
	i2c_transmit(RTC_i2c_W);
	i2c_transmit(DAY_ADDRESS);
	i2c_transmit(date->day);
	i2c_stop();
	
	i2c_start();
	i2c_transmit(RTC_i2c_W);
	i2c_transmit(DATE_ADDRESS);
	i2c_transmit(date->date);
	i2c_stop();
	
	i2c_start();
	i2c_transmit(RTC_i2c_W);
	i2c_transmit(MONTH_ADDRESS);
	i2c_transmit(date->month);
	i2c_stop();
	
	i2c_start();
	i2c_transmit(RTC_i2c_W);
	i2c_transmit(YEAR_ADDRESS);
	i2c_transmit(date->year);
	i2c_stop();
}


unsigned char get_reg(unsigned char address){
	unsigned char data = 0;
	i2c_start();
	i2c_transmit(RTC_i2c_W);
	i2c_transmit(address);
	i2c_stop();
	
	i2c_start();
	i2c_transmit(RTC_i2c_R);
	data = i2c_receive();
	i2c_stop();
	
	return data;
}

//pointer
struct mDate get_date(){
	struct mDate  data;
	data.sec = get_reg(SEC_ADDRESS);
	data.min = get_reg(MIN_ADDRESS);
	data.hour = get_reg(HOUR_ADDRESS);
	data.day = get_reg(DAY_ADDRESS);
	data.date = get_reg(DATE_ADDRESS);
	data.month = get_reg(MONTH_ADDRESS);
	data.year = get_reg(YEAR_ADDRESS);
	
	return data;
}
