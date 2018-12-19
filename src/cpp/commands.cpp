/*
 * commands.cpp
 *
 *  Created on: 19. dec. 2018
 *      Author: NielsDyrberg
 */

#include "../header/commands.h"

/*
 * Takes a pointer to a struct as an input, the function is used
 * for defining the dimensions of the matrix.
 */
void dimenssionerPaaMatrix(struct matrix *mat){
	int butNum[2] = {0,0};

	Serial.print("Antal raekke(r) i matricen? ");

	determineBut(butNum);
	mat->rows = numPad[butNum[0]-1][butNum[1]-1];
	Serial.println(mat->rows);

	Serial.print("Antal soejle(r) i matricen? ");
	determineBut(butNum);
	mat->colunms = numPad[butNum[0]-1][butNum[1]-1];
	Serial.println(mat->colunms);

	Serial.print("Dimentioner: ");
	Serial.print(mat->rows);
	Serial.print("X");
	Serial.println(mat->colunms);
}


/*
 * Is used for defining each index of the input matrix.
 * Defining starts at index 1,1 of the matrix.
 */
int newMatrix(struct matrix *mat){
	int butNum[2] = {0,0};

	Serial.println("Ny Matrix");

	Serial.println("Intast vaerdier, fra index 1,1");

	for(int i = 0; i < mat->rows; i++){
		for(int z = 0; z < mat->colunms; z++){
			determineBut(butNum);
			mat->matrix[i][z] = numPad[butNum[0]-1][butNum[1]-1];
			Serial.print((int)mat->matrix[i][z]);
			Serial.print(",");
		}
		Serial.println();
	}
	Serial.println("Matrix A gemt");
	return 0;
}

/*
 * Used for printing the matrix of the input struct.
 */
int printMatrix(struct matrix *mat){

	for(int i = 0; i < mat->rows; i++){
		for(int z = 0; z < mat->colunms; z++){
			Serial.print((int)mat->matrix[i][z]);
			Serial.print(",");
		}
		Serial.println();
	}
	return 0;
}


