#include <stdio.h>

int main(void){
	FILE *fp=fopen("numbers.txt","r");
	int used,quota;
	
	while(fscanf(fp,"%d %d",&used,&quota)==2){
		printf("User is using %d, quota was %d\n",used,quota);
	}
	fclose(fp);
	
	return 0;
}
