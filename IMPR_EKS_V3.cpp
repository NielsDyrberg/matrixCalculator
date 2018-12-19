/*
 * detButton.cpp
 *
 *  Created on: 7. nov. 2018
 *      Author: NielsDyrberg
 *  Description:
 *  	The code is for calculating the relationship between
 *  	two matrices.
 *  	First the user has to define matrix 'A' and 'B',
 *  	afterwards the console will print 'A+B', 'A-B' and
 *  	'A*B'
 */

#include "src/header/IMPR_EKS_V3.h"

//Analog input pin for each row
unsigned char r1 = A4; //Sand
unsigned char r2 = A1; //Brun
unsigned char r3 = A2; //Grå
unsigned char r4 = A3; //Gul
unsigned char r5 = A5; //Blå
unsigned char r6 = A6; //Grøn


void setup() {
	Serial.begin(9600);

	pinMode(r1, INPUT_PULLUP);
	pinMode(r2, INPUT_PULLUP);
	pinMode(r3, INPUT_PULLUP);
	pinMode(r4, INPUT_PULLUP);
	pinMode(r5, INPUT_PULLUP);
	pinMode(r6, INPUT_PULLUP);

	Serial.println("");
	Serial.println("");
	Serial.println("Hello old friend");
}



void loop() {
	struct matrix matA;
	struct matrix matB;
	struct matrix answer;

	Serial.println("Definer dimenssioner paa matrix A");
	dimenssionerPaaMatrix(&matA);

	Serial.println("Definer vaerdier i matrix A");
	newMatrix(&matA);

	Serial.println("Definer dimenssioner paa matrix B");
	dimenssionerPaaMatrix(&matB);

	Serial.println("Definer vaerdier i matrix B");
	newMatrix(&matB);

	Serial.println("De to matricer er:");
	Serial.println("Matrix A");
	printMatrix(&matA);
	Serial.println("Matrix B");
	printMatrix(&matB);

	if(addApB(&matA, &matB, &answer) == 0){
		Serial.println("Mat A + Mat B er:");
		printMatrix(&answer);
	}

	if(subAmB(&matA, &matB, &answer) == 0){
		Serial.println("Mat A - Mat B er:");
		printMatrix(&answer);
	}

	if(mulAtB(&matA, &matB, &answer) == 0){
		Serial.println("Mat A * Mat B er:");
		printMatrix(&answer);
	}
	delay(2000);
}
