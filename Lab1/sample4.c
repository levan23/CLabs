#include  <stdio.h>

int main(void){
	
	int array[] = {5,3,7,3,5};
	int *p = array;
	int i;
	
	printf("%p\n",p);
	printf("%p\n\n",array);
	
	for(i=0;i<5;i++){
		printf("%p, %d\n",(p+i),*(p+i));
	}
	
	return 0;
}
