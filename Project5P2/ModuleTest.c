/*
 * ModuleTest.c
 *
 *	Provides the testing functions all of individual peripheral testing
 *	and full system testing
 *
 * Created on: September 3rd, 2023
 *		Author: Jackie Huynh
 *
 */
 
#include "ModuleTest.h"
#include "TCS34727.h"
#include "MPU6050.h"
#include "UART0.h"
#include "Servo.h"
#include "LCD.h"
#include "I2C.h"
#include "util.h"
#include "ButtonLED.h"
#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>


static char printBuf[100];
static char angleBuf[LCD_ROW_SIZE];
static char colorBuf[LCD_ROW_SIZE];
static char colorString[6];
const uint8_t color_wheel[] = {RED, GREEN, BLUE, YELLOW, CYAN, PURPLE, WHITE, DARK};
const int color_wheel_size = 8; // Number of colors in the color wheel
uint8_t ledColorIndex = 0;
unsigned volatile long currentColor = RED; // Current LED color
extern volatile uint8_t mode;

/* RGB Color Struct Instance */
RGB_COLOR_HANDLE_t RGB_COLOR;
	
/* MPU6050 Struct Instance */
MPU6050_ACCEL_t Accel_Instance;
MPU6050_GYRO_t 	Gyro_Instance;
MPU6050_ANGLE_t Angle_Instance;

static void Test_Delay(void){
	LEDs ^= currentColor;				//Toggle Red Led
	DELAY_1MS(500);				//Delay for 0.5s using millisecond delay
}

static void Test_UART(void){
	int val = 123;
	double val2 = 3.14;
	sprintf(printBuf, "Test String: letters=%s, number=%d, float=%0.2f", "ABC", val, val2); //
	UART0_OutString(printBuf); 
	UART0_OutCRLF();
	DELAY_1MS(1000); // 1 second delay
}

static void Test_I2C(void){
    
    uint8_t sensorId = I2C0_Receive(TCS34727_ADDR, TCS34727_CMD|TCS34727_ID_R_ADDR);
    
    sprintf(printBuf, "Sensor ID: %x\r\n", sensorId);
		UART0_OutString(printBuf);
		DELAY_1MS(1000);
}

static void Test_MPU6050(void){
	/* Grab Accelerometer and Gyroscope Raw Data*/
	/*CODE_FILL*/
		
	/* Process Raw Accelerometer and Gyroscope Data */
	/*CODE_FILL*/
		
	/* Calculate Tilt Angle */
	/*CODE_FILL*/
		
	/* Format buffer to print data and angle */
	/*CODE_FILL*/
	
	DELAY_1MS(50);
}

static void Test_TCS34727(void){
	char rColor[50];
	char gColor[50];
	char bColor[50];


	/* Grab Raw Color Data From Sensor */
	RGB_COLOR.R_RAW = TCS34727_GET_RAW_RED();
	RGB_COLOR.B_RAW = TCS34727_GET_RAW_BLUE();
	RGB_COLOR.G_RAW = TCS34727_GET_RAW_GREEN();
	RGB_COLOR.C_RAW = TCS34727_GET_RAW_CLEAR();
		
	/* Process Raw Color Data to RGB Value */
	TCS34727_GET_RGB (&RGB_COLOR);
		
	/* Change Onboard RGB LED Color to Detected Color */
	switch(Detect_Color(&RGB_COLOR)){
		case RED_DETECT:
			LEDs = RED;
			break;
		case GREEN_DETECT:
			LEDs = GREEN;
			break;
		case BLUE_DETECT:
			LEDs = BLUE;
			break;
		case NOTHING_DETECT:
			LEDs = DARK;
			break;
		}
		
	/* Format String to Print */
	sprintf(rColor, "R: %0.2f", RGB_COLOR.R);				
	sprintf(bColor, "B: %0.2f", RGB_COLOR.B);						
	sprintf(gColor, "G: %0.2f", RGB_COLOR.G);
		
	/* Print String to Terminal through USB */
	UART0_OutString(rColor);
	UART0_OutString(" ");		
	UART0_OutString(bColor);
	UART0_OutString(" ");		
	UART0_OutString(gColor);
	UART0_OutString(" ");		
	UART0_OutCRLF();
		
	DELAY_1MS(50);
}

static void Test_Servo(void){
	/*
	 * In this test, follow the series of steps below (each step requires a 1s delay after)
	 * 1. Drive Servo to 0 degree
	 * 2. Drive Servo to -45 degree
	 * 3. Drive Servo to 0 degree
	 * 4. Drive Servo to 45 degree
	 * 5. Drive Servo to 0 degree
	 * 6. Drive Servo to -90 degree
	 * 7. Drive Servo to 0 degree
	 * 8. Drive Servo to 90 degree
	 */ 
	
	/*CODE_FILL*/
	
}

static void Test_LCD(void){
	/* Print Name to LCD at Center Location */
	/*CODE_FILL*/
}

static void Test_Full_System(void){
	/* Grab Accelerometer and Gyroscope Raw Data*/
	/*CODE_FILL*/
		
	/* Process Raw Accelerometer and Gyroscope Data */
	/*CODE_FILL*/
		
	/* Calculate Tilt Angle */
	/*CODE_FILL*/
		
	/* Drive Servo Accordingly to Tilt Angle on X-Axis*/
	/*CODE_FILL*/
		
	/* Format buffer to print MPU6050 data and angle */
	/*CODE_FILL*/
		
	/* Grab Raw Color Data From Sensor */
	/*CODE_FILL*/
		
	/* Process Raw Color Data to RGB Value */
	/*CODE_FILL*/
		
	/* Change Onboard RGB LED Color to Detected Color */
	switch(CODE_FILL){
		case RED_DETECT:
			LEDs = RED;
			strcpy(colorString, "RED");
			break;
		case GREEN_DETECT:
			LEDs = GREEN;
			strcpy(colorString, "GREEN");
			break;
		case BLUE_DETECT:
			LEDs = BLUE;
			strcpy(colorString, "BLUE");
			break;
		case NOTHING_DETECT:
			LEDs = DARK;
			strcpy(colorString, "NA");
			break;
	}
		
	/* Format String to Print RGB value*/
	/*CODE_FILL*/
		
	/* Print String to Terminal through USB */
	/*CODE_FILL*/
		
	/* Update LCD With Current Angle and Color Detected */
//	sprintf(angleBuf, "Angle:%0.2f\0", Angle_Instance.ArX);				//Format String to print angle to 2 Decimal Place
//	sprintf(colorBuf, "Color:%s\0", colorString);									//Format String to print color detected

	sprintf(angleBuf, "Angle:%0.2f", Angle_Instance.ArX);				//Format String to print angle to 2 Decimal Place
	sprintf(colorBuf, "Color:%s", colorString);									//Format String to print color detected
	
	/*CODE_FILL*/						//Clear LCD
	/*CODE_FILL*/						//Safety Delay of 2ms
	/*CODE_FILL*/						//Set Cursor to Row 1 Column 0
	/*CODE_FILL*/						//Print angleBuf String on LCD
	/*CODE_FILL*/						//Safety Delay of 2ms
	/*CODE_FILL*/						//Set Cursor to Row 2 Column 1
	/*CODE_FILL*/						//Print colorBuf String on LCD	
		
	DELAY_1MS(20);
}

void Module_Test(MODULE_TEST_NAME test){
	
	switch(test){
		case DELAY_TEST:
			Test_Delay();
			break;
		
		case UART_TEST:
			Test_UART();
			break;
		
		case I2C_TEST:
			Test_I2C();
			break;
		
		case MPU6050_TEST:
			Test_MPU6050();
			break;
		
		case TCS34727_TEST:
			Test_TCS34727();
			break;
		
		case SERVO_TEST:
			Test_Servo();
			break;
		
		case LCD_TEST:
			Test_LCD();
			break;
			
		case FULL_SYSTEM_TEST:
			Test_Full_System();
			break;
		
		default:
			break;
	}
	
}

void GPIOPortF_Handler(void)
{
	DELAY_1MS(50);				 // 50ms debounce	
	
	// SW 1 Button Press: Mode Switch
	if (SW1_FLAG)
	{
		// mode uart or led
		PORTF_FLAGS |= SW1_PIN; // Clear interrupt flag
		if(mode == 1){
			GPIO_PORTF_IM_R &= ~SW2_PIN;		// disarm interrupt on PF4
			mode = 2;
			UART0_OutCRLF();
			UART0_OutString("Entering Mode 2: UART TEST	\r\n");
			LEDs = DARK;
		}
		else if(mode == 2){
			GPIO_PORTF_IM_R &= ~SW2_PIN;		// disarm interrupt on PF4
			mode = 3;
			UART0_OutCRLF();
			UART0_OutString("Entering Mode 3: I2C TEST	\r\n");
			LEDs = DARK;
		}
		else if(mode == 3){
			GPIO_PORTF_IM_R |= SW2_PIN;		// arm interrupt on PF4
			mode = 1;
			UART0_OutCRLF();
			UART0_OutString("Enter Modeing 1: DELAY TEST	\r\n");
		}		
	}
	
	// SW 2 Button Press: LED COLOR WHEEL
	if (SW2_FLAG )
	{
		if(mode == 1) {
			// mode uart or led
		ledColorIndex = (ledColorIndex + 1) % color_wheel_size;
		currentColor = color_wheel[ledColorIndex];
		LEDs = currentColor;	
		}
		PORTF_FLAGS |= SW2_PIN; // Clear interrupt flag
	}	

}
 