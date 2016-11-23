/*
 ============================================================================
 Name        : BST.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "fun.h"

int main(void) {
	p_bst_t bst;

	 int root;
	 bst = (p_bst_t)malloc(bst_t);
	 scanf("%d",&root);
	 bst->root = (p_bst_t)malloc(sizeof(bst_t));

	 printf("1.Add\n"
			 	 "2.Ser\n"
			 	 "3.Rev\n"
			 	 "4.Free\n");

	return EXIT_SUCCESS;
}
