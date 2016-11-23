/*
 ============================================================================
 Name        : stack.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "lib.h"
#include <string.h>

int main(void) {
	element stack_1[MAX1];
	element stack_2[MAX2];
	initStack(stack_1,MAX1);
	initStack(stack_2,MAX2);
	int top[1];
	int nth=1;
	/*** 第一題 ***/
	top[0] = -1;
	char order[4];
	int number;
	printf("Input NEXT to next topic.\n");
	while(nth==1){
		memset(order,'\0',4);
		printf("Please Input PUSH or POP and What Number U want.\n");
		scanf("%s",order);
		if(order[1]=='U'){
			scanf("%d",&number);
			if(push(stack_1,top,number) == 1){
				listAll(stack_1,top);
			}
			else{
				printf("FULL\n");
			}
		}
		else if(order[1]=='O'){
			if(pop(stack_1,top) == 1){
				listAll(stack_1,top);
			}
			else{
				printf("EMPTY\n");
			}
		}
		else if(order[0]=='N'){
			nth++;
		}
	}
	/*** 第二題 ***/
	int i;
	printf("NO.2\n");
	top[0] = -1;
	char order_2[15];
	while(nth==2){
		memset(order_2,'\0',15);
		initStack(stack_2,MAX2);
		printf("Input :\n");
		scanf("%s",order_2);
		for(i=0;i<15;i++){
			if(order_2[i]=='\0'){
				if(stack_2[1].value != -1){
					printf("Input ERROR\n");
					break;
				}
				printf("Ans: %d\n",stack_2[top[0]].value);
				top[0]=-1;
				break;
			}
			if(order_2[i]-'0' >= 0 && order_2[i]-'0' <= 9){
				push(stack_2,top,order_2[i]-'0');
			}
			else{
				int p1,p2;
				p2 = stack_2[top[0]].value;
				pop(stack_2,top);
				if(stack_2[0].value == 0){
					printf("Input ERROR\n");
					break;
				}
				p1 = stack_2[top[0]].value;
				pop(stack_2,top);
				if(order_2[i]=='+'){
					push(stack_2,top,p1+p2);
				}
				else if(order_2[i]=='-'){
					push(stack_2,top,p1-p2);
				}
				else if(order_2[i]=='*'){
					push(stack_2,top,p1*p2);
				}
				else if(order_2[i]=='/'){
					push(stack_2,top,p1/p2);
				}
				//printf("%d\n",stack_2[top[0]].value);
			}
		}
	}
	top[0]=-1;
	return EXIT_SUCCESS;
}
