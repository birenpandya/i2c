#include <stdio.h>
#include <stdlib.h>
#include "I2Cgpiolib.h"





int main(void)
{
	int status;
	unsigned char sw_no,led_no= 0x02 ;
	unsigned char* value;
	
	status = gpio_i2c_init();
	if(!status)
	{
		printf("Failed to init i2c  lib\n");
		return -1;
	}
	   printf("\n...\n " );

		
	while(1)
	{
	 value = 0;
 	gpio_Read(sw_no,value);
	printf(".%d",value);
	if(value){
		printf("Switch pressed\n");
	}
	sleep(1);
	}	

	return 0;
}
