/*
 ============================================================================
 Name        : Link_List_HW2.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "fun.h"

int main(void) {
	p_fib_t FIB;
	FIB = CreateFIB();
	int order;
	while(scanf("%d",&order)){
		take(FIB,order);
	}
	return EXIT_SUCCESS;
}
