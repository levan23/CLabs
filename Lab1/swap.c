/**
 * File:           swap.c
 * Author:         Risto Heinsar
 * Created:        19.08.2014
 * Last edit:      31.01.2017
 *
 * Description:    Partial lab code. Swaps the two numbers using pointers.
 */
 
#include <stdio.h>

void swap(int *a,int *b);
int getNumber(char a);

int main(void)
{
    int x = getNumber('x');
    int y = getNumber('y');
    //int x = 10;
    //int y=150;
    printf("Original values:\t  x=%2d and y=%2d\n", x, y);
//	int *xp=&x;
	//int *yp=&y;
    // Call your function to swap the numbers
	swap(&x,&y);
    // here we should see the switched values
    printf("New: \t\t\t  x=%2d and y=%2d\n", x, y);
    return 0;
}

void swap(int *a,int *b){
	//printf("SUB : \t  x=%2d and y=%2d\n", *a, *b);
	int temp=*a;
	*a=*b;
	*b=temp;
	//printf("SUB AFTER: \t  x=%2d and y=%2d\n", *a, *b);
}

int getNumber(char a){
	int num;
	printf("Value of %c: ",a);
	scanf("%d",&num);
	printf("\n");
	return num;
}

/**
 * Description:    Swaps the two values passed using pointers
 *
 * Parameters:     a - int pointer, first value
 *                 b - int pointer, second value
 *
 * Notes:          Write this function yourself!
 *
 * Return:         none
 */
 
 
