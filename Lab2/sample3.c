#include <stdio.h>

#define LIMIT 5

int main(void){
	FILE *fp=fopen("writtenNums.txt","w");
	int i=0;
	
	for(i=0;i<LIMIT;i++){
		fprintf(fp,"Output: %d\n",i);
	}
	fclose(fp);
	
	return 0;
}
