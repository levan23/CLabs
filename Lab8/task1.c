#include <stdio.h>
#include <stdlib.h>
#include "task1.h"
#include <string.h>

int main(void){
	
	int N,from,to,younger,older,choice;
	printf("how many to read?\n");
	scanf("%d",&N);
	printf("1- Younger\n2- Older\n3- Between\n");
	scanf("%d",&choice);
	
	
		
	//allocation
	person *persons;
	persons = (person*)calloc(N,sizeof(person));
	for(int i=0;i<N;i++){
		(persons+i)->name = (char*)calloc(20,sizeof(char));
		(persons+i)->surname = (char*)calloc(20,sizeof(char));
	}
	
	//read from file
	FILE *pRead = fopen("names.txt","r");
	if(pRead==NULL){
		perror("Error opening file");
		exit(1);
	}
	int i=0;
	while(fscanf(pRead,"%d %s %s %d",&(persons+i)->id,(persons+i)->name,(persons+i)->surname,&(persons+i)->age)==4){
		i++;
		if(i==N)break;
	}
	
	qsort(persons,N,sizeof(person),ComparFunc);
	//output
	if(choice==3){
		printf("From which age?\n");
		scanf("%d",&from);
		printf("Until which age?\n");
		scanf("%d",&to);
	for(int i=0;i<N;i++){
		if((persons+i)->age >from && (persons+i)->age <to){
			printf("%s %d\n",(persons+i)->surname,(persons+i)->age);
		}
	}
	}else if(choice==1){
		printf("Younger than?\n");
		scanf("%d",&younger);
		for(int i=0;i<N;i++){
		
		if((persons+i)->age<younger){
			printf("%s %d\n",(persons+i)->surname,(persons+i)->age);
		}
	}
	}else if(choice==2){
		printf("Older than?\n");
		scanf("%d",&older);
		for(int i=0;i<N;i++){
		
		if((persons+i)->age>older){
			printf("%s %d\n",(persons+i)->surname,(persons+i)->age);
		}}
	}else{
		printf("put correct number!!!!!\n");
	}
	
	
	
	//free
	for(int i=0;i<N;i++){
		free((persons+i)->name);
		free((persons+i)->surname);	
	}
	free(persons);
	fclose(pRead);
	return 0;
}

int GetRand(int numMin, int numMax)
{
    return (rand() % (numMax - numMin))+numMin;
}

int ComparFunc(const void *a,const void *b){
	person *pa = (person*)a;
	person *pb = (person*)b;
	
	if(strcmp(pa->surname,pb->surname)==0) return strcmp(pa->name,pb->name);
	else return strcmp(pa->surname,pb->surname);
}
