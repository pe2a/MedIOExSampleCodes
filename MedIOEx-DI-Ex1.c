/* MedIOEx-DI-Ex1.c
 * Emergency stop sample with MedIOEx provides Raspberry Shield.
 *
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */


#include <stdio.h>
#include "pmedex.h"
#include <bcm2835.h>


int main(){


    pe2a_DO_DI_init(); //DO and DI pins intialize
	uint8_t arr_diGPIO[16];


	for(;;){

	arr_diGPIO[0] = pe2a_DI_getVal(pe2a_GPIO_J14_16);
	arr_diGPIO[1] = pe2a_DI_getVal(pe2a_GPIO_J14_15);


	printf("pe2a_GPIO_J14_16 status : %d \n",arr_diGPIO[0]);
	printf("pe2a_GPIO_J14_15 status : %d \n",arr_diGPIO[1]);


	printf("\n\n");


	delay(3); //3ms

	}

 	pe2a_bcm2835_close();  //All SPI port will be closed.

 	return 0;
}
