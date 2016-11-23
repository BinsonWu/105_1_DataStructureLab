/*
 * fun.h
 *
 *  Created on: 2016年11月5日
 *      Author: dclab
 */

#ifndef FUN_H_
#define FUN_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *next;
	long long int value;
}node_t,*p_node_t;

typedef struct fib{
	p_node_t headnode;
}fib_t,*p_fib_t;

p_fib_t CreateFIB();

void take(p_fib_t FIB,int order);

void printFIB(p_fib_t FIB,int order);

#endif /* FUN_H_ */
