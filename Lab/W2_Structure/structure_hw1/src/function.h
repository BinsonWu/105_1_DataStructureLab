/*
 * function.h
 *
 *  Created on: 2016年8月11日
 *      Author: dclab
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

typedef struct{
	float h;		//	身高
	float w;		//	體重
	float a;		//	年齡
	float s;		//	性別，男為1，女為0。
}Person;

float getBMI();
float getBodyFatRate();

void func();

#endif /* FUNCTION_H_ */
