/*
 *file    Blink_RGB.c
 *author: Erick Correia Silva
 *date: 17/04/2022
 *brief: blink the on-board LED
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


	//habilitando clock do port b e port d
	SIM->SCGC5 |= (1<<10);
	SIM->SCGC5 |= (1<<12);


	//setando o mux com gpio
	PORTD->PCR[1] = (1 << 8); //Pino setado como GPIO LED BLUE
    PORTB->PCR[18] = (1 << 8); //Pino setado como GPIO LED RED
    PORTB->PCR[19] = (1 << 8); //Pino setado como GPIO lED GREEN

    //setando a direcao do gpio
    GPIOD->PDDR = (1 << 1); // pino setado para saida
    GPIOB->PDDR = (1 << 18); // pino setado para saida
    GPIOB->PDDR = (1 << 19); // pino setado para saida


    while(1) {
    	// Escrevendo 1 na saida do pino
    	GPIOD->PDOR |= (1 << 1);
    	GPIOB->PDOR |= (1 << 18);
    	GPIOB->PDOR |= (1 << 19);

    	// delay
        for(int i = 0; i < 400000; i++);



    	// Escrevendo 0 na saida do pino
    	GPIOD->PDOR &= ~(1 << 1);
    	GPIOB->PDOR &= ~(1 << 18);
        GPIOB->PDOR &= ~(1 << 19);

        // delay
        for(int i = 0; i < 400000; i++);




    }
    return 0 ;
}
