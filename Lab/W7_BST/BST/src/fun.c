/*
 * fun.c
 *
 *  Created on: 2016年10月19日
 *      Author: dclab
 */

#include "fun.h"

p_node_t CreateNode(int)
//傳入 KEY 值，建立一個新的節點，然後回傳位址。
{

	return 1;
}

void CreateBst(p_bst_t bst,int value)
//建立一個新的二元樹，配置好記憶體，完成初始化，傳入 root 節點，然後回傳位址。
{
	bst = (p_bst_t)malloc(sizeof(bst_t));
	bst->root = CreateNode(value);
}

bool Add(p_node_t,int)
//在二元樹中，插入特定 KEY 值的節點。回傳表示成功失敗與否。
{
	return 1;
}

p_node_t Search(p_node_t,int)
//在二元樹中尋找，符合特定 key 值的節點，符合的話回傳節點位址，不符合的話，回傳 NULL。
{
	return 1;
}

p_node_t ModifySearch(p_node_t,int)
//修改過的 search，回傳可以接節點的位址
{
	return 1;
}

bool Remove(p_node_t,int)//在二元樹中，刪除某個特定 key 值的節點。回傳表示成功失敗與否。
{
	return 1;
}

void ListPreorder(p_node_t)//以 preorder 方式，將二元樹中的 key 值及位址印出。
{

}

void FreeBst(p_node_t)//將二元樹刪除並釋放記憶體
{

}

void preorder(p_node_t root)
{//為了方便測試，附上 preorder 程式碼
	if (root) {
		printf("%d:(%p) ", root->key ,root);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
