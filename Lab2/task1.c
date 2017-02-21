#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *pRead=fopen("numbers.txt","r");
	FILE *pEven=fopen("even.txt","w");
	FILE *pOdd=fopen("odd.txt","w");
	int temp;
	
	if(pRead==NULL){
		printf("File to read was not found\a\n");
		exit(1);
	}
	while(fscanf(pRead,"%d",&temp) !=EOF){
		if(temp%2==0){
			fprintf(pEven,"%d\n",temp);
		}
		else{
			fprintf(pOdd,"%d\n",temp);
		}
	}
	fclose(pRead);
	fflush(pEven);
	fflush(pOdd);
	fclose(pEven);
	fclose(pOdd);
	return 0;
}
