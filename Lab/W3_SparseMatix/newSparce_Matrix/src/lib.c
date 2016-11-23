/*
 * lib.c
 *
 *  Created on: 2016年9月21日
 *      Author: dclab
 */

#include "lib.h"

void createSparseA(sparse a[])     /* define出A的稀疏矩陣  */
{
	a[0].row		=	3;
	a[0].col		=	3;
	a[0].value	=	3;
	a[1].row		=	0;
	a[1].col		=	0;
	a[1].value	=	1;
	a[2].row		=	1;
	a[2].col		=	0;
	a[2].value	=	1;
	a[3].row		=	2;
	a[3].col		=	0;
	a[3].value	=	1;
}
void makeSparseMatrix(sparse matrix[], sparse sparse_matrix[])
/*  正常轉稀疏矩陣   */
{
		int N = matrix[0].row;				//	row
		int P = matrix[0].col;					//	column
		int i;											//	for loop
		sparse_matrix[0].row			=	N;
		sparse_matrix[0].col			=	P;
		sparse_matrix[0]	.value		=	matrix[0].value;
		int nth = 1;											//	第幾個非零元素
		for(i=1;i<N*P+1;i++){							//	正常矩陣每個元素
				if(matrix[i].value != 0){				//	賦值
					sparse_matrix[nth].row		=	matrix[i].row;
					sparse_matrix[nth].col		=	matrix[i].col;
					sparse_matrix[nth].value	=	matrix[i].value;
					nth++;
				}
		}
}
void printSparseMatrix(sparse sparse_matrix[]) /*  印出稀疏矩陣  */
{
		int i;
		/*** Output ***/
		for(i=1;i<sparse_matrix[0].value+1;i++){
			printf("%d             %d          %d\n",sparse_matrix[i].row,sparse_matrix[i].col,sparse_matrix[i].value);
		}
}

//////////    下面為第二題要用的function   ////////////
void transposeMatrix(sparse a[], sparse b[]) /* 將a矩陣轉置並放到b矩陣結構*/
{
		b[0].row 		= 	a[0].col;
		b[0].col 		= 	a[0].row;
		b[0].value 	= 	a[0].value;
		int i,j;
		int now=1;
		for(i=0;i<a[0].col;i++){
			for(j=1;j<a[0].value+1;j++){
				if(a[j].col == i){
					b[now].row 	=	a[j].col;
					b[now].col		=	a[j].row;
					b[now].value	=	a[j].value;
					now++;
				}
			}
		}
}
int COMPARE(int a, int b)/*  比較前後項大小. */
{
	return 0;
}
void storesum(sparse d[], int *totald, int row, int column, int *sum)
/* 在乘法內的function，將row i 及column j 乘完的值存起來 */
{

}
void printMatrix(sparse matrix[])  /* 印出普通矩陣 */
{
	int i,j;																//	for loop
	int nth=1;														//	陣列零存矩陣資料，固從陣列一開始。
	for(i=0;i<matrix[0].row;i++){							//	printf 0 or NotZero value
		for(j=0;j<matrix[0].col;j++){
			if(matrix[nth].row == i && matrix[nth].col==j){
				printf("%d ",matrix[nth].value);
				nth++;
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
void mutiply(sparse a[], sparse b[], sparse d[]) /* 矩陣相乘. */
{
	sparse b_t[b[0].value+1];					// 宣告B的轉置矩陣
	transposeMatrix(b,b_t);						// 將B矩陣轉置
	int i,j;
	int a_row = a[0].row;
	int b_t_row = b_t[0].row;
	int d_now=1;
	int now_row=0,now_col=0;
	for(i=1;i<a_row;i++){
		now_row = a[i].row;
		for(j=1;j<b_t_row;j++){
			now_col = b[j].row;
				if(a[i].col == b[j].col){
					if(d[1].value == -1){
						d[1].row		=	now_row;
						d[1].col		=	now_col;
						d[1].value	=	d[1].value	+	a[i].value*b[j].value;
						d[0].value++;
						printf("%d %d %d %d %d\n",1,now_row,now_col,d[d_now].value,d[0].value);
					}
					else{
						d_now=1;
						while(d[d_now].value != -1){
							if(d[d_now].row == now_row && d[d_now].col == now_col){
								d[d_now].value	=	d[d_now].value	+	a[i].value*b[j].value;
								break;
							}
							d_now++;
						}
						if(d[d_now].value == -1){
							d[d_now].row		=	now_row;
							d[d_now].col		=	now_col;
							d[d_now].value	=	d[d_now].value	+	a[i].value*b[j].value;
							d[0].value++;
							printf("%d %d %d %d %d\n",d_now,now_row,now_col,d[d_now].value,d[0].value);
						}
					}
				}
		}
	}
}
