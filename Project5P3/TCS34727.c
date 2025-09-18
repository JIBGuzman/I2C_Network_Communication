/*
 * TCS34727.c
 *
 *	Main implementation of the functions to interact with
 *	the TCS34727 RGB Color Sensor
 *
 * Created on: May 24th, 2023
 *		Author: Jackie Huynh
 *
 */

#include "TCS34727.h"
#include "I2C.h"
#include "UART0.h"
#include "util.h"
#include <stdio.h>
#include "tm4c123gh6pm.h"

/*	-------------------TCS34727_Init------------------
 *	Basic Initialization Function for TCS34727 at default settings
 *	Input: none
 *	Output: none
 */
void TCS34727_Init(void){
    uint8_t ret; // Temp variable to hold return values
    char printBuf[20]; // String buffer to print
    
    /* Check if RGB Color Sensor has been detected */
    ret = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_ID_R_ADDR);
    
    // Print ID or Error to Terminal
    sprintf(printBuf, "ID: %x\r\n", ret);
    UART0_OutString(printBuf);
    
    if(ret != TCS34727_ID){
        UART0_OutString("TCS34727 has not been Detected\r\n");
        return;
    }
    UART0_OutString("TCS34727 has been Detected\r\n");
    
    /* Set Integration Time to 2.4ms in timing register */
    ret = I2C0_Transmit(TCS34727_ADDR, TCS34727_CMD|TCS34727_TIMING_R_ADDR, TCS34727_ATIME_2_4_MS);
    if(ret != 0)
        UART0_OutString("Error on Transmit\r\n");
    else
        UART0_OutString("TCS34727 Integration Time Set\r\n");
    
    // Necessary Delay when setting integration time/wait time. 
    // This varies for which integration time is chosen.
    // This project chooses 2.4ms.
    DELAY_1MS(3);
    
    /* Setting Gain to 1X gain */
    ret = I2C0_Transmit(TCS34727_ADDR, TCS34727_CMD|TCS34727_CTRL_R_ADDR, TCS34727_CTRL_AGAIN_1);
    if(ret != 0)
        UART0_OutString("Error on Transmit\r\n");
    else
        UART0_OutString("TCS34727 Gain Set\r\n");
    
    /* Powering On Sensor at Enable register */
    ret = I2C0_Transmit(TCS34727_ADDR, TCS34727_CMD|TCS34727_ENABLE_R_ADDR, TCS34727_ENABLE_PON);
    if(ret != 0)
        UART0_OutString("Error on Transmit\r\n");
    else
        UART0_OutString("TCS34727 Power On\r\n");

    // Necessary Delay When Powering On Module
    DELAY_1MS(3);
    
    /* Enabling RGBC 2-Channel ADC at Enable register */
    ret = I2C0_Transmit(TCS34727_ADDR, TCS34727_CMD|TCS34727_ENABLE_R_ADDR, TCS34727_ENABLE_PON |TCS34727_ENABLE_AEN);
    if(ret != 0)
        UART0_OutString("Error on Transmit\r\n");
    else
        UART0_OutString("TCS34727 RGBC On\r\n");
    
    // Integration Time Delay when Activating. Varies with Integration Time Chosen by User
    DELAY_1MS(3);
    
    UART0_OutString("TCS34727 Color Sensor Initialized\r\n");
    
}

/*	---------------TCS34727_GET_RAW_CLEAR-------------
 *	Receive RAW clear data reading from the sensor
 *	Input: none
 *	Output: Returns 16-bit RAW clear data
 */
uint16_t TCS34727_GET_RAW_CLEAR(void){
    uint8_t clear_low;
    uint8_t clear_high;
    uint16_t clear_data;
    
    /* Use I2C to grab both HIGH and LOW data */
    clear_low = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_CDATAL_R_ADDR);
    clear_high = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_CDATAH_R_ADDR);
    
    /* Concatenate into 16-bit value */
    clear_data = (clear_high << 8) | clear_low;
    
    // Integration Time Delay
    DELAY_1MS(3);
    
    return clear_data;
}

/*	---------------TCS34727_GET_RAW_RED---------------
 *	Receive RAW red data reading from the sensor
 *	Input: none
 *	Output: Returns 16-bit RAW red data
 */
uint16_t TCS34727_GET_RAW_RED(void){
    uint8_t red_low;
    uint8_t red_high;
    uint16_t red_data;
    
    /* Use I2C to grab both HIGH and LOW data */
    red_low = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_RDATAL_R_ADDR);
    red_high = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_RDATAH_R_ADDR);
    
    /* Concatenate into 16-bit value */
    red_data = (red_high << 8) | red_low;
    
    // Integration Time Delay
    DELAY_1MS(3);
    
    return red_data;
}

/*	---------------TCS34727_GET_RAW_GREEN-------------
 *	Receive RAW green data reading from the sensor
 *	Input: none
 *	Output: Returns 16-bit RAW green data
 */
uint16_t TCS34727_GET_RAW_GREEN(void){
    uint8_t green_low;
    uint8_t green_high;
    uint16_t green_data;
    
    /* Use I2C to grab both HIGH and LOW data */
    green_low = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_GDATAL_R_ADDR);
    green_high = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_GDATAH_R_ADDR);
    
    /* Concatenate into 16-bit value */
    green_data = (green_high << 8) | green_low;
    
    // Integration Time Delay
    DELAY_1MS(3);
    
    return green_data;
}

/*	---------------TCS34727_GET_RAW_BLUE-------------
 *	Receive RAW blue data reading from the sensor
 *	Input: none
 *	Output: Returns 16-bit RAW blue data
 */
uint16_t TCS34727_GET_RAW_BLUE(void){
    uint8_t blue_low;
    uint8_t blue_high;
    uint16_t blue_data;
    
    /* Use I2C to grab both HIGH and LOW data */
    blue_low = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_BDATAL_R_ADDR);
    blue_high = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_BDATAH_R_ADDR);
    
    /* Concatenate into 16-bit value */
    blue_data = (blue_high << 8) | blue_low;
    
    // Integration Time Delay
    DELAY_1MS(3);
    
    return blue_data;
}

/*	---------------TCS34727_GET_RGB------------------
 *	Normalize RAW data into RGB range (0-255)
 *	Input: RGB Color Struct User Instance
 *	Output: none
 */
void TCS34727_GET_RGB(RGB_COLOR_HANDLE_t* rgb_color_instance){
    
    // Prevent Dividing by 0 by checking if the C_RAW value from struct is equal to 0
    if(rgb_color_instance->C_RAW == 0){
        rgb_color_instance->R = rgb_color_instance->G = rgb_color_instance->B = 0;
        return;
    }
    /*
    Divide all RGB value with their (RAW Value / (float)Clear Raw Value) and multiple everything with 255.0
    Store in RGB Color Instance Struct
    */ 
    
    rgb_color_instance->R = (((rgb_color_instance->R_RAW / (float)rgb_color_instance->C_RAW)) * 255.0);
    rgb_color_instance->G = (((rgb_color_instance->G_RAW / (float)rgb_color_instance->C_RAW)) * 255.0);
    rgb_color_instance->B = (((rgb_color_instance->B_RAW / (float)rgb_color_instance->C_RAW)) * 255.0);
    
}

/*	-----------------Detect_Color--------------------
 *	Detect which color is more prominent and returns that color
 *	Input: RGB Color User Instance Struct
 *	Output: COLOR_DETECTED enum value
 */
COLOR_DETECTED Detect_Color(RGB_COLOR_HANDLE_t* rgb_color_instance){
    // Red is the most prominent color
    if(rgb_color_instance->R > rgb_color_instance->G && rgb_color_instance->R > rgb_color_instance->B && rgb_color_instance->R_RAW > MIN_RAW_VALUE){
        return RED_DETECT;
    }
    // Green is the most prominent color
    else if(rgb_color_instance->G > rgb_color_instance->R && rgb_color_instance->G > rgb_color_instance->B && rgb_color_instance->G_RAW > MIN_RAW_VALUE){
        return GREEN_DETECT;
    }
    // Blue is the most prominent color
    else if(rgb_color_instance->B > rgb_color_instance->R && rgb_color_instance->B > rgb_color_instance->G && rgb_color_instance->B_RAW > 2){
        return BLUE_DETECT;
    }
    // No color is detected
    return NOTHING_DETECT;		
}