/*
 * lib.c
 *
 *  Created on: 2016年9月23日
 *      Author: dclab
 */
#include "lib.h"

void initStack(element *stack,int size){
	int i;
	for(i=0;i<size;i++){
		stack[i].value	=	-1;
	}
}
int IsFull(int top){
	if(top+1==MAX1){
		return 1;
	}else{
		return 0;
	}
}
int IsEmpty(int top){
	if(top==-1){
			return 1;
		}else{
			return 0;
		}
}
int push(element *stack, int *top, int value) {
	if(IsFull(top[0]) == 1){
		return 0;
	}
	top[0]++;
	stack[top[0]].value = value;
	return 1;
}
int pop(element *stack, int *top) {
	if(IsEmpty(top[0]) == 1){
		return 0;
	}
	stack[top[0]].value = 1;
	top[0]--;
	return 1;
}
void listAll(element *stack, int *top){
	int i;
	for(i=0;i<=top[0];i++){
		printf("%d ",stack[i].value);
	}
	printf("\n");
}
