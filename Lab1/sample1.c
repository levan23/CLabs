#include <stdio.h>

int main(void){
	
	int num;
	int *p;
	p=&num;
	scanf("%d",p);
	printf("*p = %d\n",*p);
	
	printf("num = %d\n",num);
	
	printf("p = %p\n",p);
	
	printf("&num = %p\n",&num);
	
	*p = 55;
	printf("%d\a",num);
	
	
	return 0;
	
}
	
