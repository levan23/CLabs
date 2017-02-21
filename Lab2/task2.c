#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <limits.h>
#include <stdbool.h>

#define MAX 20
#define MAX_SIZE 200000
#define INPUT_FILE "data_short.txt"
//#define INPUT_FILE "data_long.txt"

struct employee{
	int ID;
	char first[MAX];
	char last[MAX];
	char city[MAX];
};

struct place{
	char members[MAX_SIZE][MAX];
	char name[MAX];
	int size;
};

int main(void){
	
	struct employee staff[MAX_SIZE];
	struct place cities[MAX_SIZE];
	int numberOfCities;
	numberOfCities=0;
	int i=0;
	
	//read
	FILE *fp = fopen(INPUT_FILE,"r");
	if(fp==NULL){
		perror("File was not found");
		exit(-1);
	}
	while(fscanf(fp,"%d %s %s %s",&(staff+i)->ID,(staff+i)->first,(staff+i)->last,(staff+i)->city)==4){
		int j,index;
		index=0;
		bool result;
		result=false;
		for(j=0;j<numberOfCities;j++){
			if(strcmp(cities[j].name,staff[i].city)==0){
				result=true;
				index=j;
			}
		}
		if(result==true){
				strcpy(cities[index].members[(cities[index].size)],staff[i].first);
				cities[index].size++;
			}
		else{
				strcpy(cities[numberOfCities].name,staff[i].city);
				cities[numberOfCities].size=0;
				strcpy(cities[numberOfCities].members[(cities[numberOfCities].size)],staff[i].first);
				cities[numberOfCities].size++;
				numberOfCities++;
			}
			i++;
		}
	
	
	//output
	int b;
	for(b=0;b<numberOfCities;b++){
		printf("City %s has %d members\n",cities[b].name,cities[b].size);
	}
	
	return 0;
}
/*
void ReadFromFile(struct employee e, struct place p){
	
	FILE *fp = fopen(INPUT_FILE,"r");
	if(fp==NULL){
		perror("File was not found");
		exit(-1);
	}
	while(fscanf(fp,"%d %s %s %s",&e[i].ID,name,surname,ccc)==4){
		
		
		
			
}
**/
