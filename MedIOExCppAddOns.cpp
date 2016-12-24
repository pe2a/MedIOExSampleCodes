/* MedIOExCppAddOns.cpp
 * In this program, you can compile and run MedIOExCppAddOns.cpp
 * Compile gcc -o MedIOExCppAddOns MedIOExCppAddOns.cpp pmedex.c -lbcm2835
 * first c++ program on MedIOEx
 * pe2a.h provides c++
 * please set SW2 as being Buzzer ON
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */


#include <iostream>
#include <bcm2835.h>
#include "pmedex.h"

class SmartHome{

public:

    SmartHome(); //initialize GPIO
    void set_ON_AlarmBuzzer(); //ON Buzzer!
    void set_OFF_AlarmBuzzer(); //OFF Buzzer!
    ~SmartHome(); //close comm. port


};


SmartHome::SmartHome(){

    std::cout<<"First Cpp Program"<<std::endl;
    std::cout<<"Smart Home Class is being created"<<std::endl;
    pe2a_DO_DI_init();

}


SmartHome::~SmartHome(){

    std::cout<<"Smart Home is being deleted "<<std::endl;
    pe2a_bcm2835_close();

}


void SmartHome::set_ON_AlarmBuzzer(){

    pe2a_DO_setHigh(pe2a_GPIO_J4_1);

}


void SmartHome::set_OFF_AlarmBuzzer(){

    pe2a_DO_setLow(pe2a_GPIO_J4_1);

}



int main(){

  SmartHome bedRoom;

  bedRoom.set_ON_AlarmBuzzer();//ON Buzzer
  delay(1000); //1second
  bedRoom.set_OFF_AlarmBuzzer(); //OFF Buzzer

  return 0;
}
