/*
 ============================================================================
 Name        : Link_List_HW2_2.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "fun.h"

int main(void) {
	p_list_t sorted_list;
	sorted_list 									= (p_list_t)malloc(sizeof(list_t));				// 創建list
	sorted_list->headnode 				= (p_node_t)malloc(sizeof(node_t));		// 創建headnode
	sorted_list->headnode->key1 	= 0;																// list長度
	sorted_list->headnode->key2 	= 0;																// mode 0 (主key1) 1 (主key2)
	sorted_list->headnode->next		= NULL;
	while(1){
		printf("1. 插入資料\n"
					"2. 刪除資料\n"
					"3. 搜尋資料\n"
					"4. 列印資料\n"
					"5. 主副交換\n");
		int order,delorder,key1=0,key2=0;
		printf("Order << ");
		scanf("%d",&order);
		switch(order){
		case 1:
			printf("給定新增的(key1,key2) pair，將此 pair 插入適當的位置:");
			scanf("%d %d",&key1,&key2);
			if(Insert(sorted_list,key1,key2) == 0)
			{
				printf("Same Node!!!\n");
			}
			break;
		case 2:
			printf(	"Delete:\n"
						"1. 指定刪除的(key1,key2) pair\n"
						"2. 指定欲刪除的 key1 (所有符合的皆要刪除)\n"
						"3. 指定欲刪除的 key2 (所以符合的皆要刪除)\n");
			printf("Order << ");
			scanf("%d",&delorder);
			if(delorder == 1)
			{
				printf("key1,key2 << ");
				scanf("%d %d",&key1,&key2);
			}
			else if(delorder == 2)
			{
				printf("key1 << ");
				scanf("%d",&key1);
			}
			else if(delorder == 3)
			{
				printf("key2 << ");
				scanf("%d %d",&key2);
			}

			if(Delete(sorted_list,key1,key2,delorder) == 0)
			{
				printf("No This Node!!!\n");
			}
			break;
		case 3:
			printf("給定(key1,key2)pair, 傳回位於第幾順位，若不存在，則傳回-1:");
			scanf("%d %d",&key1,&key2);
			if(Search(sorted_list,key1,key2) == -1)
			{
				printf("FALL!!!\n");
			}
			break;
		case 4:
			printf("依有續串列的順序，將資料顯示於螢幕上:\n");
			Print(sorted_list);
			break;
		case 5:
			printf("加分~ 主副交換:");
			if(sorted_list->headnode->key2 == 0)
			{
				sorted_list->headnode->key2 = 1;
				printf("主 key1 -> key2\n");
			}
			else
			{
				sorted_list->headnode->key2 = 0;
				printf("主 key2 -> key1\n");
			}
			sorted_list = Rule_Change(sorted_list);
			break;
		}
	}
	return EXIT_SUCCESS;
}
