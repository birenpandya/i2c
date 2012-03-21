/**
 * @file    msp430lib.h
 * @brief   
 * @version 00.10
 *
 * Put the file comments here.
 *
 * @verbatim
 * ============================================================================
 * Copyright (c) Texas Instruments Inc 2007
 *
 * Use of this software is controlled by the terms and conditions found in the
 * license agreement under which this software has been supplied or provided.
 * ============================================================================
 * @endverbatim
 */

#ifndef _I2CGPIOLIB_H
#define _I2CGPIOLIB_H

#define LIB_SUCCESS 1     //!< Indicates success of an API call.
#define LIB_FAILURE 0       //!< Indicates failure of an API call.


extern int gpio_i2c_init(void);
extern unsigned int gpio_Read(unsigned char, unsigned char*);
extern unsigned int gpio_write(unsigned char,unsigned char);

#endif // _SIMPLEWIDGET_H
