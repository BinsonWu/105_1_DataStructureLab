/*
 * dbllklistlib.c
 *
 *  Created on: 2016年10月16日
 *      Author: dclab
 */

#include "dbllklistlib.h"

void Create(p_queue_t quu)												// Initial Queue
{
	quu->headNode = (p_node_t)malloc(sizeof(node_t));
	quu->headNode->value=0;
	quu->headNode->pre=NULL;
	quu->headNode->next=NULL;
	quu->front = NULL;
	quu->rear = NULL;
	quu->size = 5;
}

int  isEmpty(p_queue_t quu)											// queue 空的
 {
	if(quu->headNode->value == 0)
	{
		//printf("EMPTY\n");
		return 1;
	}
	else
	{
		//printf("NOT EMPTY\n");
		return 0;
	}
 }
int  isFull (p_queue_t quu)   											// queue 滿的
 {
	if(quu->headNode->value == quu->size)
	{
		//printf("FULL\n");
		return 1;
	}
	else
	{
		//printf("NOT FULL\n");
		return 0;
	}
 }

int  deQueue(p_queue_t quu) 										// 移除一個node，並回傳是否移除成功
 {
		if(isEmpty(quu) == 1){												// 若Queue為空的
			return 0;																	// 回傳0代表失敗
		}
		// 代表Queue有東西
		p_node_t node;
		node = quu->front->next;											// node=第二個node
		free(quu->front);														// 把第一個node free掉
		quu->headNode->next 	= node;								// headNode->next 	變第二個node
		quu->front						= node;								// front 						變第二個node
		if(node != NULL)															// 若node為NULL做此操作會當掉
		{
			node->pre						= quu->headNode;			// 第二個的前一個指向headNode
		}
		quu->headNode->value--;
		return 1;																		// 回傳1代表成功
 }
int  enQueue(p_queue_t quu,int value)							// 添加一個node，並回傳是否新增成功
 {
		if(isFull(quu) == 1)
		{
			return 0;
		}
		if(isEmpty(quu) == 1){																			// 第一個Node
				quu->headNode->next 	= (p_node_t)malloc(sizeof(node_t));	// headNode->next為第一個node
				p_node_t node;
				node = quu->headNode->next;
				node->pre 			= quu->headNode;												// 前一個是headNode
				node->next 		= NULL;																// 下一個是空的
				node->value 		= value;																// 值為傳進來的value
				quu->front 			= quu->rear 			= node;								// front,rear指向第一個node
				quu->headNode->value++;															// 多一個node
			}
			else{
				quu->rear->next	= (p_node_t)malloc(sizeof(node_t));				// 新增一個node到rear的下一個
				p_node_t node;
				node = quu->rear->next;
				node->pre 			= quu->rear;														// 前一個為現在的rear
				node->next 		= NULL;																// 因為自己是最後一個，下一個為空
				node->value 		=	value;																// 值為傳進來的value
				quu->rear 			= node;																// 將rear指向現在的最後一個
				quu->headNode->value++;															// 多一個node
			}
		return 1;
 }

void  clear(p_queue_t quu)												//清空queue
 {
		p_node_t node;
		node = quu->front;
		while(node!=NULL)
		{
			deQueue(quu);
			node = node->next;
		}
 }


int InsertNode(p_queue_t quu,int nth,int value)			// 新增到第N個的next，第N個為NULL則回傳失敗
{
	if(quu->headNode->value < nth-1 || nth < 1)							// 代表沒有此node
	{
		return 0;																					// 回傳失敗
	}
	else if(quu->headNode->value == nth-1)									// 代表新增到最後一個
	{
		return enQueue(quu,value);												// 回傳enQueue是否成功
	}
	if(nth == 1)
	{
		p_node_t OriFirstNode;
		OriFirstNode = quu->headNode->next;										// 本來的第一個
		p_node_t node= (p_node_t)malloc(sizeof(node_t));					// 新增一個node
		node->pre 						= quu->headNode;									// 前一個是headNode
		node->next 					= OriFirstNode;										// 下一個是本來的第一個
		node->value 					= value;													// 值為傳進來的value
		quu->front 						= node;													// front指向第一個node
		OriFirstNode->pre			= node;													// 本來第一個的pre變成node
		quu->headNode->next 	= node;													// quu->headNode->next變成node
		quu->headNode->value++;															// 多一個node
		return 1;
	}
	// 首先找到要進行操作的node
	int counter=0;
	p_node_t nthnode;
	nthnode = quu->front;																// nthnode 等於第一個node
	counter = 1;																				// counter設為1
	while(counter != nth)																// 找到要的那個停下來
	{
		nthnode = nthnode->next;														// 變成下個node
		counter++;
	}
	p_node_t nthnodepre;
	nthnodepre = nthnode->pre;														// 我們要的node的pre存起來
	p_node_t node 		= (p_node_t)malloc(sizeof(node_t));		// 新增一個我們要加進去的node
	node->pre				= nthnodepre;												// 新node的前一個為第nthpre
	node->next				= nthnode;													// 新node的下一個為第nth
	node->value			= value;														// 值為輸入的value
	nthnodepre->next	= node;														// nthnodepre	下一個變成	node
	nthnode->pre			= node;														// nthnode		前一個變成	node
	quu->headNode->value++;														// 多一個node
	return 1;
}
int DeleteNode(p_queue_t quu,int nth)							// 刪除第N個，第N個為NULL則回傳失敗
{
	if(quu->headNode->value < nth || nth < 1)					// 代表沒有此node
	{
		return 0;																		// 回傳失敗
	}
	else if(nth == 1)																// 代表刪除第一個
	{
		return deQueue(quu);												// 回傳enQueue是否成功
	}
	// 首先找到要進行操作的node
	int counter=0;
	p_node_t nthnode;
	nthnode = quu->front;																// nthnode 等於第一個node
	counter = 1;																				// counter設為1
	while(counter != nth)																// 找到要的那個停下來
	{
		nthnode = nthnode->next;														// 變成下個node
		counter++;
	}
	p_node_t nthprenode,nthnextnode;											// 第nth個node的pre,next存起來
	nthprenode	= nthnode->pre;
	nthnextnode	= nthnode->next;
	free(nthnode);																			// free掉第nth個node
	// nth的前後node互接
	nthprenode->next	= nthnextnode;
	if(nthnextnode != NULL)															// 若nthnextnode為NULL做此操作會當掉
	{
		nthnextnode->pre	= nthprenode;
	}
	quu->headNode->value--;
	return 1;
}
