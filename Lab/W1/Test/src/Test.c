/*
 ============================================================================
 Name        : Test.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void) {
	int var;
	var = 5;
	printf("var : %d\n",var);
	prn_2time_var(var);
	return EXIT_SUCCESS;
}
