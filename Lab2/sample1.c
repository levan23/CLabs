#include <stdio.h>

int main(void){
	FILE *fp;
	int temp;
	//char inputFile[]={"numbers.txt"};
	fp=fopen("numbers.txt","r");
	while(fscanf(fp,"%d",&temp) !=EOF){
		printf("Got: %d\n",temp);
	}
	fclose(fp);
	
	return 0;
}
