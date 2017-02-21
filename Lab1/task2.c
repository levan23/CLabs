#include <stdio.h>
//void finder(int *arr);



int main(void){
	
	int array[10];
	int i,N;
	int *smallest,*greatest;
	int *parray;
	parray=array;
	
	printf("enter number of elements\n");
	scanf("%d",&N);

	printf("enter %d elements of array\n",N);
	
	for(i=0;i<N;i++){
		scanf("%d",parray+i);
	}
	
	for(i=0;i<N;i++){
		printf("%d -> %p\n",*(parray+i),(parray+i));
	}
	smallest = array;
	greatest = array;
	
	for(i=0;i<N;i++){
		if(*(parray+i)<*smallest){
			smallest=(parray+i);
		}
		if(*(parray+i)>*greatest){
			greatest=(parray+i);
		}
	}
	printf("Greatest %d -> %p\n",*greatest,greatest);
	printf("Smallest %d -> %p\n",*smallest,smallest);
	
	return 0;
}
/*
void finder(int[] array){
	*helper=array;
	for(int i=0;i<sizeof(array);i++){
		if((helper+i)<
	
	
}
* */
