/*
 * fun.h
 *
 *  Created on: 2016年10月19日
 *      Author: dclab
 */

#ifndef FUN_H_
#define FUN_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	struct node* lchild;
	struct node* rchild;
	int key;
}node_t,*p_node_t;
//一般型態的節點，以及指標型態的節點。內含 key 值，子樹的位址。

typedef struct{
	p_node_t root;

}bst_t,*p_bst_t;

//一般結構型態的二元樹，以及指標型態的二元樹。

p_node_t CreateNode(int);
//傳入 KEY 值，建立一個新的節點，然後回傳位址。

void CreateBst(p_bst_t bst,int value);
//建立一個新的二元樹，配置好記憶體，完成初始化，傳入 root 節點，然後回傳位址。

bool Add(p_node_t,int);
//在二元樹中，插入特定 KEY 值的節點。回傳表示成功失敗與否。

p_node_t Search(p_node_t,int);
//在二元樹中尋找，符合特定 key 值的節點，符合的話回傳節點位址，不符合的話，回傳 NULL。

p_node_t ModifySearch(p_node_t,int);
//修改過的 search，回傳可以接節點的位址

bool Remove(p_node_t,int);//在二元樹中，刪除某個特定 key 值的節點。回傳表示成功失敗與否。

void ListPreorder(p_node_t);//以 preorder 方式，將二元樹中的 key 值及位址印出。

void FreeBst(p_node_t);//將二元樹刪除並釋放記憶體

void preorder(p_node_t root);//為了方便測試，附上 preorder 程式碼


#endif /* FUN_H_ */
