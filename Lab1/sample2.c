#include <stdio.h>

int main(void){
	double pi = 3.14;
	double *p=&pi;
	printf("the pointer hold an address: %p\n",p);
	printf("pi variable is located at: \t\t %p\n",&pi);
	printf("Dereferencing p we can access the value behind it\t %lg\n",*p);
	
	return 0;
	
}
