#ifndef KEYPAD_H_
#define KEYPAD_H_


#include  "TM4C123.h"
#include  "common_macros.h"
#include  "systick.h"


/******************************************************************************
                          DEFINITIONS
******************************************************************************/	

/* Keypad configurations for number of rows and columns */
#define No_OF_COL 4
#define NO_OF_ROW 4


#define KEYPAD_PORT_C  GPIOC
#define KEYPAD_PORT_E  GPIOE

/*********************************************************************************************
R0 -----> PE0
R1 -----> PE1
R2 -----> PE2
R3 -----> PE3             Connetions For Keypad
C0 -----> PC4
C1 -----> PC5
C2 -----> PC6
C3 -----> PC7
**********************************************************************************************/


/***************************************************************************
                         FUNCTION PROTOTYPES
***************************************************************************/



/**************************************************************************
           This function is to initalize the keypad
***************************************************************************/

void KEYPAD_Init(void);

/***************************************************************************
           THIS FUNCTION IS USED TO RETURN PRESSED KEY 
****************************************************************************/

uint8_t KEYPAD_Getkey(void);





#endif