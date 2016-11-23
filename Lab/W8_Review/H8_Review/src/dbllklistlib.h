/*
 * dbllklistlib.h
 *
 *  Created on: 2016年10月16日
 *      Author: dclab
 */

#ifndef DBLLKLISTLIB_H_
#define DBLLKLISTLIB_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct  node{
		struct node *pre;
        struct node *next;
        int value;
 }node_t,*p_node_t;

 typedef struct queue{
	 p_node_t front;																	// First
	 p_node_t rear;																	// Final
	 p_node_t headNode;															// 第一個 node
     int   size;     																		// size是指queue中最多node數量, size 訂5個
 }queue_t,*p_queue_t;

void Create(p_queue_t quu);												// Initial Queue
int isEmpty(p_queue_t quu);												// queue 空的
int isFull(p_queue_t quu);   													// queue 滿的

int deQueue(p_queue_t quu); 											// 移除一個node，並回傳是否移除成功
int enQueue(p_queue_t quu,int value);								// 添加一個node，並回傳是否添加成功

void clear(p_queue_t quu);													// 清空queue

int InsertNode(p_queue_t quu,int nth,int value);				// 新增到第N個的next，第N個為NULL則回傳失敗
int DeleteNode(p_queue_t quu,int nth);							// 刪除第N個，第N個為NULL則回傳失敗

#endif /* DBLLKLISTLIB_H_ */
