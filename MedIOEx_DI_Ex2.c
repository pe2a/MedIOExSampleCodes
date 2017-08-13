/* MedIOEx-DI-Ex2.c
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
	uint8_t arr_diGPIO[4]; //emergency stop buttons


	for(;;){

    	arr_diGPIO[0] = pe2a_DI_getVal(pe2a_GPIO_J14_16); //DI : emergency stop NC
    	arr_diGPIO[1] = pe2a_DI_getVal(pe2a_GPIO_J14_15); //DI : emergency stop NC

      	arr_diGPIO[2] = pe2a_DI_getVal(pe2a_GPIO_J14_14); //DI : emergency stop NC
      	arr_diGPIO[3] = pe2a_DI_getVal(pe2a_GPIO_J14_13); //DI : emergency stop NC


            if(arr_diGPIO[0]  || arr_diGPIO[1] || arr_diGPIO[2] || arr_diGPIO[3] ){

                printf("Emergency Status is NOT OK , buzzer should be ON \n")
                pe2a_DO_setHigh(pe2a_GPIO_J4_1); //buzzer ON
                pe2a_DO_setHigh(pe2a_GPIO_J4_2);

            }

            else
            {

                printf("Emergency Status is OK , buzzer should be OFF \n")
                pe2a_DO_setLow(pe2a_GPIO_J4_1); //buzzer OFF
                pe2a_DO_setLow(pe2a_GPIO_J4_2);

            }

    	printf("\n\n");
    	delay(3); //3ms is needed for emergency stop in some cases
	}
 	    pe2a_bcm2835_close();  //All SPI port will be closed.

 	return 0;
}
