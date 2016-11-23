/*
 * function.c
 *
 *  Created on: 2016年8月11日
 *      Author: dclab
 */

#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/*
1 是蘋果 2 是香蕉 3 芭樂
吃到自己最喜歡的水果開心度依序+3 +2 +1
則問3人開心度加起來最高是多少
(	因為只求最高開心度總數，
	沒求每人都要分到，
	故從每個人第一喜歡的水果開始分，
	有就給他沒有就找下個，
	找到水果分完或是大家都吃飽了即可。)
 */

int getMaxHappyPoint(Person per[3],Fruit fru[3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			int fruNum;						//	紀錄第j個人第i個喜歡的水果數量
			int perNum;						//	紀錄第j個人吃的下的水果數量
			fruNum = fru[per[j].favorite[i]-1].num;
			perNum = per[j].num;
				if(fruNum>0 && perNum > 0){
					/*計算吃完後水果剩幾個，人還可以再吃幾個*/
					/*開心度 依 favorite[0]+3, favorite[1]+2,favorite[2]+1*/
					if(fruNum >= perNum){
						per[j].hpypt 		+=  (3-i)*perNum;
						fruNum 				-= perNum;
						perNum 				 = 0;
					}
					else{
						per[j].hpypt 		+= (3-i)*fruNum;
						perNum 				 = perNum - fruNum;
						fruNum 				 = 0;
					}
					fru[per[j].favorite[i]-1].num	=	fruNum;
					per[j].num								=	perNum;					// 回傳結果
				}
			}
	}
	return per[0].hpypt+per[1].hpypt+per[2].hpypt;
}

void func(){
	int i;
	Person per[3];
	Fruit	 fru[3];
	/*初始化開心度為零，設定每個人可以吃的水果數量，以及喜好順序。*/
	for(i=0;i<3;i++){
		per[i].hpypt = 0;
		printf("(Fruit 1 is Apple. Fruit 2 is Banana. Fruit 3 is Guava.)\n");
		printf("Please input Person(%d)'s num and favorite Fruit sequence : ",i+1);
		scanf("%d%d%d%d",&per[i].num,&per[i].favorite[0],&per[i].favorite[1],&per[i].favorite[2]);
	}
	/*設定這種水果有多少個*/
	printf("Please input Apple's, Banana's, Guava's num : ");
	scanf("%d%d%d",&fru[0].num,&fru[1].num,&fru[2].num);
	printf("MaxHappyPoint : %d\n",getMaxHappyPoint(per,fru));
}
