/*
 * fun.h
 *
 *  Created on: 2016年11月5日
 *      Author: dclab
 */

#ifndef FUN_H_
#define FUN_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *next;
	int key1;
	int key2;
}node_t,*p_node_t;

typedef struct list{
	p_node_t headnode;
}list_t,*p_list_t;

int Insert(p_list_t sorted_list,int key1,int key2);

int Delete(p_list_t sorted_list,int key1,int key2,int delorder);

int Search(p_list_t sorted_list,int key1,int key2);

void Print(p_list_t sorted_list);

p_list_t Rule_Change(p_list_t sorted_list);
#endif /* FUN_H_ */
