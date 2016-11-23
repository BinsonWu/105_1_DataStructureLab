/*
 * singlelist.h
 *
 *  Created on: 2016年10月7日
 *      Author: dclab
 */

#ifndef SINGLELIST_H_
#define SINGLELIST_H_

#include <stdio.h>
#include <stdlib.h>

 typedef struct  node{
        struct node *next;
        int value;
 }node_t,*p_node_t;

 typedef struct queue{
	 p_node_t front;										// First
	 p_node_t rear;										// Final
	 p_node_t headNode;								// 第一個 node
       int   size;     								// size是指queue中最多node數量, size 訂5個
 }queue_t,*p_queue_t;

 //create( );   										// 裡面包含initial 及 size

void isEmpty(p_queue_t quu);											// queue 空的
void  isFull(p_queue_t quu);   											// queue 滿的

void  deQueue(p_queue_t quu); 										// 移除一個node
void enQueue(p_queue_t quu,int value);										// 添加一個node

void clear();												//清空queue

#endif /* SINGLELIST_H_ */
