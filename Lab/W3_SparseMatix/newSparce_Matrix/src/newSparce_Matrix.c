/*
 ============================================================================
 Name        : newSparce_Matrix.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "lib.h"

int main(void) {
	sparse Sparse_Matrix_A[4];
	createSparseA(Sparse_Matrix_A);						//	創造已知A稀疏矩陣
	/*第1題 輸入正常轉稀疏*/
		int P,Nzero;
		int M	=	3;
		int N	=	3;
		int i,j;
		printf("Please Input P,Nzero :");
		scanf("%d %d",&P,&Nzero);
		sparse Matrix_B[N*P+1];
		Matrix_B[0].row		= N;
		Matrix_B[0].col		= P;
		Matrix_B[0].value	= Nzero;
		int n=1;
		for(i=0;i<N;i++){
			for(j=0;j<P;j++){
				Matrix_B[n].row 		= i;
				Matrix_B[n].col 		= j;
				scanf("%d",&Matrix_B[n].value);
				n++;
			}
		}
		sparse Sparse_Matrix_B[Nzero+1];														//	宣告稀疏B
		makeSparseMatrix(Matrix_B,Sparse_Matrix_B);									//	正常B轉稀疏B
		printf("B's Sparse Matrix:\nRow      Col      Value\n");
		printSparseMatrix(Sparse_Matrix_B);
		/*第2題 稀疏矩陣乘法*/
		sparse Sparse_Matrix_C[M*P+1];															// 宣告矩陣乘法的結果
		for(i=0;i<M*P+1;i++){
			Sparse_Matrix_C[i].row		= -1;
			Sparse_Matrix_C[i].col		= -1;
			Sparse_Matrix_C[i].value	= -1;
		}
		Sparse_Matrix_C[0].row		= M;
		Sparse_Matrix_C[0].col		= P;
		Sparse_Matrix_C[0].value	= 0;
		mutiply(Sparse_Matrix_A,Sparse_Matrix_B,Sparse_Matrix_C);
		printf("\nC:\n");
		printSparseMatrix(Sparse_Matrix_C);
		printf("\nA*B:\n");
		printMatrix(Sparse_Matrix_C);
	return EXIT_SUCCESS;
}
