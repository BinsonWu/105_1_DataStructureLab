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
 *	BMI	=	w	/h^2
 * 	BFR	=	1.2*BMI	+	0.23*Age		-5.4		-10.8*sex(男生是1,女生是0)
 */

float getBMI(Person nowPer){
	float BMI;
	BMI	=	nowPer.w/nowPer.h/nowPer.h;
	return BMI;
}
float getBodyFatRate(Person nowPer){
	float BFR;
	BFR	=	1.2*getBMI(nowPer)	+	0.23*nowPer.a	-5.4		-10.8*nowPer.s;
	return BFR;
}
void func(){
	int i,n;
	printf("Please input how many people : ");																		//	輸入幾個人
	scanf("%d",&n);
	Person per[n];

	for(i=0;i<n;i++){																													// 輸入每個人的data
		printf("Please input Person(%d)'s height(m), weight(kg), age, sex(0 or 1) : ",i+1);
		scanf("%f%f%f%f",&per[i].h,&per[i].w,&per[i].a,&per[i].s);
	}
	for(i=0;i<n;i++){																													// 輸出每個人的data
			printf("Person(%d)'s     BMI	: %f\n",i+1,getBMI(per[i]));
			printf("                           BFR	: %f\n",getBodyFatRate(per[i]));
		}
}
