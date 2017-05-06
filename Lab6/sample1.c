#include <stdio.h>
#include <stdlib.h>

int ComparFunc(const void *a,const void *b);
int main(void){
	int i,nums[]={40,10,100,90,20,25};
	int numCount = sizeof(nums)/sizeof(int);
	qsort(nums,(size_t)numCount,sizeof(int),ComparFunc);
	for(i=0;i<numCount;printf("%3d\n",nums[i]),i++);
	//printf("%d\n",numCount);
	
	
	return 0;
}

int ComparFunc(const void *a,const void *b){
	if(*(int*)a > *(int*)b)return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else return 0;
}
//only for interegrs 
/**
 * int ComparFunc(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
*/
