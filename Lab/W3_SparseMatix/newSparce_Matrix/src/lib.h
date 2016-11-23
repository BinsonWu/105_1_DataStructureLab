/*
 * lib.h
 *
 *  Created on: 2016年9月21日
 *      Author: dclab
 */

#ifndef LIB_H_
#define LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct {
	int row;
	int col;
	int value;
} sparse;
void createSparseA(sparse a[]);     /* define出A的稀疏矩陣  */

void makeSparseMatrix(sparse matrix[],sparse sparse_matrix[]);/*  正常轉稀疏矩陣   */

void printSparseMatrix(sparse sparse_matrix[]); /*  印出稀疏矩陣  */

//////////    下面為第二題要用的function   ////////////
void transposeMatrix(sparse a[], sparse b[]); /* 將a矩陣轉置並放到b矩陣結構*/

int COMPARE(int a, int b); /*  比較前後項大小. */

void storesum(sparse d[], int *totald, int row, int column, int *sum);
/* 在乘法內的function，將row i 及column j 乘完的值存起來 */

void printMatrix(sparse matrix[]);  /* 印出普通矩陣 */

void mutiply(sparse a[], sparse b[], sparse d[]); /* 矩陣相乘. */

#endif /* LIB_H_ */
