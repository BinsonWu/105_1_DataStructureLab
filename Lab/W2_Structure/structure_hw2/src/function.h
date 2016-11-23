/*
 * function.h
 *
 *  Created on: 2016年8月11日
 *      Author: dclab
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <string.h>

typedef struct{
	int favorite[3];					//	食物愛好順序
	int num;								//	能吃幾個水果
	int hpypt;
}Person;

typedef struct{
	int num;								//	水果有幾個
}Fruit;

int getMaxHappyPoint(Person per[3],Fruit fru[3]);
void func();

#endif /* FUNCTION_H_ */
