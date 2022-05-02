/**
 *author: Erick Correia Silva
 *date: 17/04/2022
 *file   Button_with_led.c
 *brief  blink led with button
 *platform: KL25Z development board
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */


int main(void) {
	//habilitando clock do port c e port d
	SIM->SCGC5 |= (1<<11);
	SIM->SCGC5 |= (1<<12);


	//setando o mux com gpio
	PORTC->PCR[8]= (1 << 8); //Pino setado como GPIO
	PORTD->PCR[4] = (1 << 8); //Pino setado como GPIO


    //setando a direcao do gpio
    GPIOC->PDDR |= (1 << 8); // pino setado para SAIDA
    GPIOD->PDDR  &= ~(1 << 4); // pino setado para ENTRADA


    while(1) {
    	if(GPIOD->PDIR & (1 << 4)){
    		GPIOC->PDOR |= (1 << 8);
    	}else{
    		GPIOC->PDOR &= ~(1 << 8);
    	}


    }
    return 0 ;
}
