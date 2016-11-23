/*
 ============================================================================
 Name        : single_list.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "singlelist.h"

int main(void) {
	p_queue_t quu;
	quu = malloc(sizeof(queue_t));
	quu->headNode = NULL;
	quu->front = NULL;
	quu->rear = NULL;
	quu->size = 5;
	int order;
	int value;

	while(1){
		printf("(1)Add node\n(2)Remove node\n(3)clear\nOrder->");
			scanf("%d",&order);
			switch(order){
			case 1:
				printf("input:");
				scanf("%d",&value);
				enQueue(quu,value);
				break;
			case 2:
				deQueue(quu);
				break;
			case 3:
				clear(quu);
				break;
			default :
				printf("Wrong Order!!!\n");
				break;
			}
			p_node_t node;
			node = quu->headNode;
			while(node != NULL){
				printf("%d ",node->value);
				node=node->next;
			}
			printf("\n");
	}

	return EXIT_SUCCESS;
}
