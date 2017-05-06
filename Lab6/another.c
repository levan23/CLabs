#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"

float Add(float x,float y){
	return x+y;
}

float Subtract(float x, float y){
	return x-y;
}

float Multiply(float x, float y){
	return x*y;
}

float Divide(float x, float y){
	return x/y;
}

float Exponent(float x, int y){
	float result=1;
	for(int i=0;i<y;i++){
		result*=x;
	}
	return result;
}

int ComparFuncInt(const void *x, const void *y){
	return *(int*)x-*(int*)y;
}

int ComparFuncFloat(const void *x, const void *y){
	if(*(int*)x>*(int*)y) return 1;
	else if(*(int*)x<*(int*)y) return -1;
	else return 0;
}

int ComparFuncStruct(const void *x, const void *y){
	
	product *px = (product *)x;
	product *py = (product *)y;
	
	if(px->price>py->price) return 1;
	else if(px->price<py->price) return -1;
	else return 0;
}
	
