
/**************************************************************
Name Biren Pandya
Date sept 29th

Linux Library for I2C which is communitcating with MSP board.
***************************************************************/


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <pthread.h>


/* User defined library */
#include "i2c-dev.h"
#include "I2Cgpiolib.h"


/* I2C device info with Master Adress */
#define I2C_DEVICE "/dev/i2c-0"
#define I2C_DEV_ADDR 0x25

static int i2clib_fd = -1 ;
#define LIB_SUCCESS	1
#define LIB_FAILURE	0


unsigned int gpio_Read(unsigned char sw_no, unsigned char* value)
{

	*value = 0;
        unsigned char buf[3];
        int status = LIB_SUCCESS;
        unsigned short int key ;
        unsigned int temp = 0;


	while(!*value)
	{
         buf[0] = 0x04;   // set the messege length
        //transfer the command
    if (write(i2clib_fd, buf, 1) != 1) {
        printf("Failed to write GPIO command to device [%s]\n", strerror(errno));
        status = LIB_FAILURE;
        return status;
    } else   {
	//	printf("Write SUCCESS \n");
	 
    }
	
    if (read(i2clib_fd, buf, 3) != 3) {

        printf("Failed to read GPIO data\n");
        status = LIB_FAILURE;
        return status;
    }
    else {
	// Decoding data .
	if(buf[2] & 0x04){
	//	value = 1;		
	//	printf(" 3\t\n");
	}

	else if(buf[2] & 0x02 )	{
	//	printf(" 2\t\n" );
	}

	else if(buf[2] & 0x08){
	//	printf(" 4\t\n" );
		*value =1;
        }
	else {
	  //   printf(" .\t\n" );
		*value =0 ;	
		}
	}
	usleep(300000);
}
	return status;
}


 unsigned int gpio_write(unsigned char led_no ,unsigned char value )
{


	int status;
        unsigned char buf[2];
        buf[0] = 0x03;
        buf[1] = led_no;

   if (write(i2clib_fd, buf, 2) != 2) {
        printf("Failed to write GPIO command to device [%s]\n", strerror(errno));
        status = LIB_FAILURE;
        return status;
    }
    else{
       // printf("Writes GPIO pin  is : 0x%04x\n",buf[1]);
    }

}



int gpio_i2c_init(void)
{
	 int status = LIB_SUCCESS;

	//open the i2c device file decriptor
 	i2clib_fd = open(I2C_DEVICE, O_RDWR);
    	if (i2clib_fd < 0){
        	printf("Error while opening i2c device %s\n", I2C_DEVICE);
      		status = LIB_FAILURE;
    	}
	else
		printf("Device Successfully opened %s\n",I2C_DEVICE);

	//configure the i2c device as master
    if (ioctl(i2clib_fd, I2C_SLAVE, I2C_DEV_ADDR) == -1) {
        printf("Failed to set I2C_MASTER to %#x\n", I2C_DEV_ADDR);
        status = LIB_FAILURE;
    }
    else {		
	printf("Master is set to %x \n",I2C_DEV_ADDR);
    }	
    return status;
}




