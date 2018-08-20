#ifndef RTC_H
#define RTC_H

#include "main.h"

//RTC I2C address
#define RTC_i2c_W		0xD0  //write
#define RTC_i2c_R		0xD1  //read

//time register addresses
#define SEC_ADDRESS		0x00
#define MIN_ADDRESS		0x01
#define HOUR_ADDRESS	0x02
#define DAY_ADDRESS		0x03
#define DATE_ADDRESS	0x04
#define MONTH_ADDRESS	0X05
#define YEAR_ADDRESS	0X06

//date
struct mDate
{
	unsigned char sec, min, hour, day, date, month, year;
};

void set_clock(struct mDate* date);
unsigned char get_reg(unsigned char address);
struct mDate  get_date();

#endif
