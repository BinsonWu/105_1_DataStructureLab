/*
 * lib.h
 *
 *  Created on: 2016年9月23日
 *      Author: dclab
 */

#ifndef LIB_H_
#define LIB_H_

#include <stdio.h>
#include <stdlib.h>
#define MAX1 4
#define MAX2 15
typedef struct {
	int value;
} element;
void initStack(element *stack,int size);
int IsFull(int top);
int IsEmpty(int top);
int push(element *stack, int *top, int value) ;
int pop(element *stack, int *top) ;
void listAll(element *stack, int *top);

#endif /* LIB_H_ */
