#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 5

int main(void){
	FILE *pRead=fopen("grades.txt","r");
	char *pch;
	
	char input[100];
	if(pRead==NULL){
		perror("grades.txt");
		exit(1);
	}
	while(fgets(input,LIMIT,pRead)){
		//int sum=0;
		pch=strtok(input," ");
		//printf("%s\t",pch);
		
		while(pch!=NULL){
			pch=strtok(NULL," ");
			printf("%s\t",pch);
			//sum+=(int)*pch;
		}
		//printf("Sum is: %d\n",sum);
		
	}
	fclose(pRead);
	
	return 0;
}
