/*
 * fin.c
 *
 *  Created on: 2016年11月5日
 *      Author: dclab
 */

#include "fun.h"

int Insert(p_list_t sorted_list,int key1,int key2){
	p_node_t temp,newnode,Temp_Ori_Next;
	newnode 			= (p_node_t)malloc(sizeof(node_t));
	newnode->key1 = key1;
	newnode->key2 = key2;
	newnode->next	= NULL;
	if(sorted_list->headnode->next == NULL)					// 第一個node
	{
		sorted_list->headnode->next = newnode;
		sorted_list->headnode->key1++;
		return 1;
	}

	temp = sorted_list->headnode;									// 因為用next去比所以等於headnode
	int targetkey1,targetkey2;											// 要找的key1 key2 可能等於可能大於等於自己
	if(sorted_list->headnode->key2 == 0)						// mode 0
	{
		//printf("mode 0\n");
		while( temp->next->key1 < newnode->key1)		// 現在node->next跟newnode比，key1比他小代表newnode在更後面。
		{
			temp = temp->next;
			if(temp->next == NULL)										//	考慮到插在最後一個，temp->next = NULL，temp->next->key1會當掉
			{
				break;
			}
		}
		if(temp->next != NULL)
		//	考慮到跑完第一個while已經在最後一個，temp->next = NULL，temp->next->key2會當掉
		{
			targetkey1 =  temp->next->key1;
			if(targetkey1 == newnode->key1)							// 若temp->next->key1大於自己代表自己一定插這邊，故只考慮=自己。
			{
				while( temp->next->key2 < newnode->key2 && temp->next->key1 == targetkey1)
				// 現在node->next跟newnode比，key2比他小代表newnode在更後面，且它的key1不能動。
				{
					temp = temp->next;
					if(temp->next == NULL)									//	考慮到插在最後一個，temp->next = NULL，temp->next->key1會當掉
					{
						break;
					}
				}
			}
		}
		// node一樣回傳失敗
		if(temp->next != NULL)											//	考慮到插在最後一個，temp->next = NULL，temp->next->key1會當掉
		{
			if(temp->next->key1 ==  newnode->key1 && temp->next->key2 == newnode->key2)
			{
				return 0;
			}
		}
		// 結束代表newnode在temp跟temp->next中間
		//( temp->next->key1 >=  newnode->key1 && temp->next->key2 > newnode->key2)。
		Temp_Ori_Next 	= temp->next;
		temp->next 		= newnode;
		newnode->next 	= Temp_Ori_Next;
		sorted_list->headnode->key1++;
		return 1;
	}
	else																				// mode 1
	{
		//printf("mode 1\n");
		while( temp->next->key2 < newnode->key2)		// 現在node->next跟newnode比，key1比他小代表newnode在更後面。
		{
			temp = temp->next;
			if(temp->next == NULL)										//	考慮到插在最後一個，temp->next = NULL，temp->next->key1會當掉
			{
				break;
			}
		}
		if(temp->next != NULL)
		//	考慮到跑完第一個while已經在最後一個，temp->next = NULL，temp->next->key2會當掉
		{
			//printf("targetkey2:%d\n",targetkey2);
			targetkey2 =  temp->next->key2;
			if(targetkey2 == newnode->key2)							// 若temp->next->key2大於自己代表自己一定插這邊，故只考慮=自己。
			{
				while( temp->next->key1 < newnode->key1 && temp->next->key2 == targetkey2)
				// 現在node->next跟newnode比，key1比他小代表newnode在更後面，且它的key2不能動。
				{
					temp = temp->next;
					if(temp->next == NULL)									//	考慮到插在最後一個，temp->next = NULL，temp->next->key1會當掉
					{
						break;
					}
				}
			}
		}
		// node一樣回傳失敗
		if(temp->next != NULL)											//	考慮到插在最後一個，temp->next = NULL，temp->next->key1會當掉
		{
			if(temp->next->key1 ==  newnode->key1 && temp->next->key2 == newnode->key2)
			{
				return 0;
			}
		}
		// 結束代表newnode在temp跟temp->next中間
		//( temp->next->key1 >=  newnode->key1 && temp->next->key2 > newnode->key2)。
		Temp_Ori_Next 	= temp->next;
		temp->next 		= newnode;
		newnode->next 	= Temp_Ori_Next;
		sorted_list->headnode->key1++;
		return 1;
	}
}
int Delete(p_list_t sorted_list,int key1,int key2,int delorder)
{
	p_node_t temp,Bedelete;
	if(sorted_list->headnode->next == NULL)
	{
		return 0;
	}
	temp = sorted_list->headnode;
	switch(delorder)
	{
	case 1:			// 指定刪除的(key1,key2) pair
		if(temp->next != NULL)
		{
			while(temp->next->key1 != key1 || temp->next->key2 != key2)
			{
				temp = temp->next;
				if(temp->next == NULL)
				{
					return 0;
				}
			}
			Bedelete = temp->next;
			temp->next = temp->next->next;
			free(Bedelete);
			sorted_list->headnode->key1++;
		}
		break;
	case 2:			// 指定欲刪除的 key1 (所有符合的皆要刪除)
		while(temp->next->key1 == key1)
		{
			Bedelete 		= temp->next;
			temp->next = temp->next->next;
			free(Bedelete);
			sorted_list->headnode->key1++;
			if(temp->next == NULL)
			{
				break;
			}
		}
		break;
	case 3:			// 指定欲刪除的 key2 (所以符合的皆要刪除)
		while(temp->next->key2 == key2)
		{
			Bedelete 		= temp->next;
			temp->next = temp->next->next;
			free(Bedelete);
			sorted_list->headnode->key1++;
			if(temp->next == NULL)
			{
				break;
			}
		}
		break;
	}
	return 1;
}

int Search(p_list_t sorted_list,int key1,int key2)
{
	p_node_t temp;
	int count=0;
	if(sorted_list->headnode->next == NULL)
	{
		return 0;
	}
	temp = sorted_list->headnode;

	if(temp->next != NULL)
	{
		while(temp->next->key1 != key1 || temp->next->key2 != key2)
		{
			temp = temp->next;
			count++;
			if(temp->next == NULL)
			{
				return -1;
			}
		}
	}
	return count;
}

void Print(p_list_t sorted_list){
	p_node_t temp;
	temp = sorted_list->headnode->next;
	printf("length:%d\n",sorted_list->headnode->key1);
	//printf("mode:%d\n",sorted_list->headnode->key2);
	printf("sorted_list:");
	while(temp != NULL)
	{
		printf("(%d,%d) ",temp->key1,temp->key2);
		temp = temp->next;
	}
	printf("\n");
}

p_list_t Rule_Change(p_list_t sorted_list){
	p_list_t new_sorted_list;
	new_sorted_list = (p_list_t)malloc(sizeof(list_t));
	p_node_t newheadnode,temp;
	newheadnode 						= (p_node_t)malloc(sizeof(node_t));
	newheadnode->key1 				= 0;
	newheadnode->key2 				= sorted_list->headnode->key2;
	newheadnode->next				= NULL;
	new_sorted_list->headnode 	= newheadnode;

	temp = sorted_list->headnode->next;
	while(temp != NULL)
	{
		Insert(new_sorted_list,temp->key1,temp->key2);
		temp = temp->next;
	}
	return new_sorted_list;
}
