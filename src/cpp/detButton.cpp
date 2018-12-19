/*
 * detButton.cpp
 *
 *  Created on: 4. dec. 2018
 *      Author: NielsDyrberg
 */

#include "../header/detButton.h"

//Make butNum into a number
int numPad[5][6] = {
		{NULL, NULL, NULL, NULL, NULL, NULL},
		{9, NULL, NULL, NULL, NULL, NULL},
		{6, 7, 8, NULL, NULL, NULL},
		{3, 4, 5, NULL, NULL, NULL},
		{0, 1, 2, NULL, NULL, NULL}
};

//Determines which row the button press is
void determineRow(float *volt, int *row){

	if(*volt > 0.97 and *volt < 1.17){
		*row = 1;
		delay(450);
	}else if(*volt > 1.80 and *volt < 2.00){
		*row = 2;
		delay(450);
	}else if(*volt > 2.73 and *volt < 2.93){
		*row = 3;
		delay(450);
	}else if(*volt > 3.50 and *volt < 3.70){
		*row = 4;
		delay(450);
	}else if(*volt > 4.07 and *volt < 4.27){
		*row = 5;
		delay(450);
	}else{
		Serial.print("Error: ");
		Serial.println(*volt);
		delay(1000);
	}
}

//Determines which column the button press is
void determineCol(float *volt, int *col){

	float messure;

	for(int i = 1; i < 7; i++){
		switch(i){
			case 1:
				messure = analogRead(r1);
				*volt = messure*(5.0/1023.0);

				if(*volt < 4.5)
					*col = 1;
				break;
			case 2:
				messure = analogRead(r2);
				*volt = messure*(5.0/1023.0);
				if(*volt < 4.5)
					*col = 2;
				break;
			case 3:
				messure = analogRead(r3);
				*volt = messure*(5.0/1023.0);
				if(*volt < 4.5)
					*col = 3;
				break;
			case 4:
				messure = analogRead(r4);
				*volt = messure*(5.0/1023.0);
				if(*volt < 4.5)
					*col = 4;
				break;
			case 5:
				messure = analogRead(r5);
				*volt = messure*(5.0/1023.0);
				if(*volt < 4.5)
					*col = 5;
				break;
			case 6:
				messure = analogRead(r6);
				*volt = messure*(5.0/1023.0);
				if(*volt < 4.5)
					*col = 6;
				break;
			default:
				break;
		}
		if(*col != 0){
			i = 8;
		}
	}
}

/*
 * Function that determines row and column of the pressed button
 * by calling the funktions determineBut() and determineRow().
 * It waits until there is a button press
 */
void determineBut(int *but){
	int rowNum = 0;
	int colNum = 0;
	float volt = 0.00;


	while(colNum == 0){
		determineCol(&volt, &colNum);
	}
	determineRow(&volt, &rowNum);

	but[0] = rowNum;
	but[1] = colNum;

}
