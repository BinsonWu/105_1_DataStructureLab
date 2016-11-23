/*
 * fun.c
 *
 *  Created on: 2016年11月5日
 *      Author: dclab
 */

#include "fun.h"

p_fib_t CreateFIB(){
	p_fib_t FIB 												= (p_fib_t)malloc(sizeof(fib_t));
	FIB->headnode 										= (p_node_t)malloc(sizeof(node_t));
	FIB->headnode->value 							= 2;
	FIB->headnode->next 							= (p_node_t)malloc(sizeof(node_t));		// 第一個
	FIB->headnode->next->value				= 0;
	FIB->headnode->next->next					= (p_node_t)malloc(sizeof(node_t));		// 第二個
	FIB->headnode->next->next->value		=1;
	FIB->headnode->next->next->next		= FIB->headnode->next;							// 第二個的下一個指向第一個
	return FIB;
}

void take(p_fib_t FIB,int order){
	if(FIB->headnode->value >= order){
		printFIB(FIB,order);
		printf("create 0 nodes.\n");
	}
	else{
		p_node_t pre,temp;
		pre		= FIB->headnode;
		temp 	= FIB->headnode->next;
		int create_n_node;
		create_n_node = order - FIB->headnode->value;
		while(temp->next != pre){
			//printf("value:%d\n",temp->value);
			pre 		= temp;
			temp 	= temp->next;
		}
		while(FIB->headnode->value < order ){
			p_node_t New_Node;
			New_Node 					= (p_node_t)malloc(sizeof(node_t));
			New_Node->value 		= temp->next->value + temp->value;
			temp->next 				= New_Node;
			New_Node->next 		= temp;
			temp 							= New_Node;
			FIB->headnode->value++;
		}
		printFIB(FIB,order);
		printf("create %d nodes.\n",create_n_node);
	}
}

void printFIB(p_fib_t FIB,int order){
	p_node_t temp;
	temp = FIB->headnode->next;
	int count=2;
	printf("[");
	while(temp->next->next != temp && count < order){
		printf("%lld,",temp->value);
		temp = temp->next;
		count++;
	}
	printf("%lld,%lld]\n",temp->value,temp->next->value);
}
