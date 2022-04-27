#include "keypad.h"



static const unsigned char keymap[NO_OF_ROW][No_OF_COL] = {
{ '1', '2', '3', 'A'},
{ '4', '5', '6', 'B'},
{ '7', '8', '9', 'C'},
{ '*', '0', '#', 'D'},
};


void KEYPAD_Init(void){

SET_BIT((SYSCTL->RCGCGPIO),1); // Enable clock to PORTB
(KEYPAD_PORT)->CR  |= 0xFF;  // Allow settings for all pins of PORTA
(KEYPAD_PORT)->DEN |= 0xFF;  // Set PORTA as digital pins
(KEYPAD_PORT)->DIR |= 0xF0;  // Set the most 4 pins of PORTB as digital output (columns) and the least 4 pins as digital inputs (rows)
(KEYPAD_PORT)->PDR |= 0x0F;  // Enable pull down resistor on the least 4 pins of PORTB (rows)
}

uint8_t KEYPAD_Getkey(void){
	while(1){
		for(int i = 0; i < 4; i++)    //Scan columns loop
    {
			(KEYPAD_PORT)->DATA = (1U << (i+4));
			delayUs(1);
			for(int j = 0; j < 4; j++)  //Scan rows
      {
				if((BIT_IS_SET(((KEYPAD_PORT)->DATA),j)))
					return keymap[j][i];
			}
		}
	}
}