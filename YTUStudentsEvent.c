/* YTUStudentsEvent.c
 * YTU Students Sample Code by Students
 * J3_1 and J3_2 relays will be activited depends temperature
 * (EN) MedIOEx is completely industrial Raspberry IO shield. Supply voltage is 24V. 
 * update date 04.12.16
 * !EN
 * Requirements:
 * bcm2835.h must be in /usr/lib
 * for further information pe2a.com/docs
 * edited by Pe2a 
 * 
 * compile:
 *  gcc -o YTUStudentsEvent YTUStudentsEvent.c -lbcm2835 pmedex.c -std=gnu11 
 * 
 * Run:
 * ./YTUStudentsEvent
 *
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */

#include <stdio.h>
#include "pmedex.h"
#include <bcm2835.h>

#define MinBorderTemperature 29 //Celcius

int main(){
	

    pe2a_DO_DI_init(); //DO and DI pins intialize
    pe2a_getTemperature_init();
	uint8_t arr_diGPIO[16]; //Digital Input Array
	
	
	for(;;){
			
	arr_diGPIO[0] = pe2a_DI_getVal(pe2a_GPIO_J14_13);

	printf("pe2a_GPIO_J14_13 staus : %d \n",arr_diGPIO[0]);
	printf("pe2a_getTemperature(1) : %.2f \n",pe2a_getTemperature(1)); //reads temperature via i2c 

	
	if ( pe2a_DI_getVal(pe2a_GPIO_J14_13) ==1 ) {
	delay (3000); //3000ms

		if ( pe2a_DI_getVal(pe2a_GPIO_J14_13) ==1 &&  pe2a_getTemperature(1) > MinBorderTemperature) {
			pe2a_DO_setHigh(pe2a_GPIO_J3_1); 
			pe2a_DO_setHigh(pe2a_GPIO_J3_2);
		}
	}
	else{

    pe2a_DO_setLow(pe2a_GPIO_J3_1); 
	pe2a_DO_setLow(pe2a_GPIO_J3_2);
	
	}
	printf("\n\n");
	
	delay(100); //100ms

	}

 	pe2a_bcm2835_close();  //All SPI port will be closed.
 	
 	return 0;
}

