#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <bcm2835.h>
#include "pmedex.h"

/*
*
* Basic thread simple via pe2a.h 
* You can see how to create Digital Output and Analog Output functions as using thread functions
* Compile : gcc -o thread_time thread_time.c pmedex.c -lbcm2835 -lpthread -std=gnu11 
* Run : ./thread
*
*/


void *fTimePicker_1(); //thread1
void *fTimePicker_2(); //thread2
void *fTimePicker_3(); //thread3
void fDOSet();
void fAOSet();
void fGrassSetHigh();
void fGrassSetLow();
void fFlowerSetHigh();
void fFlowerSetLow();


int main(){

	pthread_t thread1,thread2,thread3;

	pthread_create(&thread1,NULL,&fTimePicker_1,NULL);
	pthread_create(&thread2,NULL,&fTimePicker_2,NULL);
	pthread_create(&thread3,NULL,&fTimePicker_3,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);


	exit(EXIT_SUCCESS);

	return 0;

}


void fGrassSetHigh(){


	pe2a_DO_setHigh(pe2a_GPIO_J4_1);
	pe2a_DO_setHigh(pe2a_GPIO_J4_2);

}

void fGrassSetLow(){


	pe2a_DO_setLow(pe2a_GPIO_J4_1);
	pe2a_DO_setLow(pe2a_GPIO_J4_2);

}

void fFlowerSetHigh(){
	
	pe2a_DO_setHigh(pe2a_GPIO_J5_5);
	pe2a_DO_setHigh(pe2a_GPIO_J5_6);
	
}


void fFlowerSetLow(){
	
	pe2a_DO_setLow(pe2a_GPIO_J5_5);
	pe2a_DO_setLow(pe2a_GPIO_J5_6);
	
}

void *fTimePicker_1(){
	
	
	int state = 0;
	pe2a_DO_DI_init();
	
	while(1){

		switch (state){
			
			case 0:
			
				;
			case 1:
			
				fGrassSetHigh();
				sleep(1);
				
			case 2:
			
				fGrassSetLow();
				sleep(1);
				
		}

	}
}


void *fTimePicker_2(){
	
	
	int state = 0;
	pe2a_DO_DI_init();
	
	while(1){

		switch (state){
			
			case 0:
			
				
			case 1:
			
				fFlowerSetHigh();
				sleep(2);
				
			case 2:
			
				fFlowerSetLow();
				sleep(2);
				
		}

	}
}



void *fTimePicker_3(){
	
	
	int state = 0;
	pe2a_AO_init();
	while(1){

		switch (state){
			
			case 0:
			
				
			case 1:
			
				pe2a_AO_writeVal(pe2a_GPIO_J1_1,4095);	
				sleep(2);
				
			case 2:
			
				pe2a_AO_writeVal(pe2a_GPIO_J1_1,2048);
				sleep(2);
				
		}

	}
}

