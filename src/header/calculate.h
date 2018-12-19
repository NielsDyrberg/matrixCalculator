/*
 * calculate.h
 *
 *  Created on: 19. dec. 2018
 *      Author: NielsDyrberg
 */

#ifndef SRC_HEADER_CALCULATE_H_
#define SRC_HEADER_CALCULATE_H_

#include "IMPR_EKS_V3.H"

extern int addApB(struct matrix *matA, struct matrix *matB, struct matrix *answer);
extern int subAmB(struct matrix *matA, struct matrix *matB, struct matrix *answer);
extern int mulAtB(struct matrix *matA, struct matrix *matB, struct matrix *answer);

#endif /* SRC_HEADER_CALCULATE_H_ */
