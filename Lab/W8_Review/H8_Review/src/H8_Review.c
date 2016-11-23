/*
 ============================================================================
 Name        : H8_Review.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "dbllklistlib.h"

int main(void) {
		p_queue_t quu;
		quu = malloc(sizeof(queue_t));
		Create(quu);
		int order;																// 輸入指令
		int nth,value;															// 第幾個，紀錄node的值
		order=0;
		while(order != -1){
			printf("(1)Add node\n"
						"(2)Remove node\n"
						"(3)Insert node to behind nth\n"
						"(4)Delete nth node\n"
						"(5)clear\n"
						"Order->");
			scanf("%d",&order);
			switch(order){
				case 1:
					printf("value:");
					scanf("%d",&value);
					if(enQueue(quu,value)==0)
						printf("Full\n");
					break;
				case 2:
					if(deQueue(quu)==0)
						printf("Empty\n");
					break;
				case 3:
					printf("nth value:");
					scanf("%d %d",&nth,&value);
					if(InsertNode(quu,nth,value) == 0)
						printf("Error Node\n");
					break;
				case 4:
					printf("nth:");
					scanf("%d",&nth);
					if(DeleteNode(quu,nth) == 0)
						printf("Error Node\n");
					break;
				case 5:
					clear(quu);
					printf("Clear Queue!!!\n");
					break;
				case -1:
					printf("End!!!\n");
					break;
				default :
					printf("Wrong Order!!!\n");
					break;
			}
			p_node_t node;
			node = quu->headNode->next;
			printf("Queue:(");
			while(node != NULL && order != -1)
			{
				printf("%d ",node->value);
				node=node->next;
			}
			printf(")\n");
		}
	return EXIT_SUCCESS;
}
