/*
 * calculate.cpp
 *
 *  Created on: 19. dec. 2018
 *      Author: NielsDyrberg
 */

#include "../header/calculate.h"

/*
 * Adds matrix 'A' to matrix 'B' and stores the answer in
 * matrix 'answer'
 */
int addApB(struct matrix *matA, struct matrix *matB, struct matrix *answer){

	if(matA->colunms != matB->colunms and matA->rows != matB->rows){
		Serial.println("Det kan ikke lade sig goere!");
		Serial.println("Dimentionerne skal vaere ens");
		return 1;
	}else{
		answer->colunms = matA->colunms;
		answer->rows = matA->rows;

		for(int i = 0; i < answer->rows; i++){
			for(int z = 0; z < answer->colunms; z++){
				answer->matrix[i][z] = matA->matrix[i][z] + matB->matrix[i][z];
			}
		}
	}

	return 0;
}

/*
 * Subtracts matrix 'B' from matrix 'A' and stores the answer in
 * matrix 'answer'
 */
int subAmB(struct matrix *matA, struct matrix *matB, struct matrix *answer){

	if(matA->colunms != matB->colunms and matA->rows != matB->rows){
		Serial.println("Det kan ikke lade sig goere!");
		Serial.println("Dimentionerne skal vaere ens");
		return 1;
	}else{
		answer->colunms = matA->colunms;
		answer->rows = matA->rows;

		for(int i = 0; i < answer->rows; i++){
			for(int z = 0; z < answer->colunms; z++){
				answer->matrix[i][z] = matA->matrix[i][z] - matB->matrix[i][z];
			}
		}
	}

	return 0;
}

/*
 * Multiplies matrix 'A' times matrix 'B' and stores the answer in
 * matrix 'answer'
 */
int mulAtB(struct matrix *matA, struct matrix *matB, struct matrix *answer){

	if(matA->colunms != matB->rows){
		Serial.println("Det kan ikke lade sig goere!");
		Serial.println("Antallet af soejler i A skal vaere ens med raekker i B");
		return 1;
	}else{
		answer->rows = matA->rows;
		answer->colunms = matB->colunms;

		for(int i = 0; i < answer->rows; i++){
			for(int z = 0; z < answer->colunms; z++){
				int tmpAns = 0;
				for(int m = 0; m < matA->colunms; m++){
					tmpAns += matA->matrix[i][m]*matB->matrix[m][z];
				}
				answer->matrix[i][z] = tmpAns;
			}
		}
	}
	return 0;
}


