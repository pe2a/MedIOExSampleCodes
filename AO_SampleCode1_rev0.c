/*Ao_test.c
 * 4ch 12 bit ANALOG OUTPUT Sample Program_1
 *
 * Requirements:
 * bcm2835.h must be in /usr/lib
 * for further information pe2a.com/docs
 * "pe2a.h"
 *
 * compile:
 * gcc -o AO_SampleCode1_rev0 AO_SampleCode1_rev0.c pmedex.c -lbcm2835 -std=gnu11
 *
 * Run:
 * ./AO_SampleCode1_rev0
 * access : 12.2016
 * update :
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */


#include <stdio.h>
#include <bcm2835.h>
#include "pmedex.h"


int convertAnalog_to_Digital(const double getVal){

	return (int)((4095.0  / 10.0) * getVal); //Digital Number
}

double convertDigital_to_Analog(const int getVal){

return (double)((10.0  / 4095.0) * getVal); //Voltage
}

int main(){

	pe2a_AO_init();	 //initialize Analog output
	int i = 0;

	printf("Analog Output test program starting \n");
	printf("\n");
	for(;;){


		//to send voltage reference
		//min. 0V, max. 10V
		pe2a_AO_writeVal(pe2a_GPIO_J1_1,convertAnalog_to_Digital(2.8)); //voltage reference

		//to read Voltage reference
		printf("Pin Voltage : %.2f \n",convertDigital_to_Analog(convertAnalog_to_Digital(2.8)));

		delay(1000); //1second


	}


 	pe2a_bcm2835_close(); //All SPI port will be closed.

 	return 0;
}
