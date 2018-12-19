/*
 * IMPR_EKS.h
 *
 *  Created on: 7. nov. 2018
 *      Author: NielsDyrberg
 */

#ifndef SRC_IMPR_EKS_H_
#define SRC_IMPR_EKS_H_

#include <Arduino.h>

#include "detButton.h"
#include "commands.h"
#include "calculate.h"


extern unsigned char r1;
extern unsigned char r2;
extern unsigned char r3;
extern unsigned char r4;
extern unsigned char r5;
extern unsigned char r6;

extern int butNum[2];

#define MATRIX_LIMIT 9
struct matrix {
	int matrix[MATRIX_LIMIT][MATRIX_LIMIT];
	int rows;
	int colunms;
};









#endif /* SRC_IMPR_EKS_H_ */
