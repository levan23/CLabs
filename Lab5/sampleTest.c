#include <stdio.h>
#include <stdlib.h>
#include <date.h>

#define MAX_DATE 6
#define MAX 10
#define SIZE 50 
#define DATA_FILE "001.txt" 
typedef struct tracker{
	char[MAX_DATE] date;
	char[10] feeling;
	int run;
	int walk;
	int stand;
	int sit;
	int lay;
}tracker;

int main(void){
	tracker info[SIZE];
	FILE *pRead = fopen(DATA_FILE,"r");
	if(pRead==NULL){
		perror("Error opening file");
		exit(1);
	}
	
	//methods here
	
	
	return 0;
}

void ReadData(tracker *info,FILE *pRead){
	int i=0;
	while(fscanf(
