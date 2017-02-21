#include <stdio.h>

//just to understand/remember pointers
int main(void){
	
	int num = 25;
	int *p;
	p=&num;
	
	printf("num - %d\n",num);
	printf("Num address = %p\n",&num);
	
	printf("Pointer address = %p\n",&p);
	printf("Pointer value = %p\n",p);
	printf("Pointing value = %d\n",*p);
	*p=55;
	
	
	printf("After *p = %d\n",*p);
	
	printf("After num= %d\n",num);
	return 0;
}
