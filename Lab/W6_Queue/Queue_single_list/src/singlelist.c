/*
 * singlelist.c
 *
 *  Created on: 2016年10月7日
 *      Author: dclab
 */

#include "singlelist.h"

void  isEmpty(p_queue_t quu)											// queue 空的
 {

 }
void  isFull (p_queue_t quu)   											// queue 滿的
 {

 }

void  deQueue(p_queue_t quu) 										// 移除一個node
 {
		if(quu->front == quu->rear){
			quu->headNode = NULL;
			quu->front = NULL;
			quu->rear = NULL;
		}
		p_node_t node;
		node = quu->headNode->next;

		free(quu->headNode);
		quu->headNode	= NULL;

		quu->front			= node;
		quu->headNode = node;
 }
void  enQueue(p_queue_t quu,int value)										// 添加一個node
 {
		if(quu->headNode == NULL){
				p_node_t node 	= malloc(sizeof(node_t));
				node->next 		= NULL;
				node->value 		=	value;
				quu->headNode = quu->front = quu->rear = node;
			}
			else{
				p_node_t node 	= malloc(sizeof(node_t));
				node->next 		= NULL;
				node->value 		=	value;
				quu->rear->next = node;
				quu->rear 			= node;
			}
 }

void  clear()												//清空queue
 {

 }
