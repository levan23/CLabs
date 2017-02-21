#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define INPUT_FILE "data_short.txt"


#define MAX 20
#define MAX_NUMBER 220

struct employee{
	int id;
	char first[MAX];
	char last[MAX];
	char city[MAX];
};

struct place{
	char member[210][20];
	char name[20];
	int size;
};

int main(void){
	struct employee staff[MAX_NUMBER];
	struct place cities[MAX_NUMBER];
	int i=0;
	int numberOfCities=0;
	char choice[MAX];
	
	//read
	FILE *fp = fopen(INPUT_FILE, "r");
	
	if(fp==NULL){
		perror("Error opening file");
		exit(1);
	}
	while(fscanf(fp,"%d %s %s %s", &staff[i].id,staff[i].first,staff[i].last,staff[i].city) == 4){
		
		int j;
		int index=-1;
		
		for(j=0;j<numberOfCities;j++){
			if(strcmp(cities[j].name,staff[i].city)==0){
				index=j;
			}
		}
	
		if(index>=0){
			strcpy(cities[index].member[cities[index].size],staff[i].first);
			cities[index].size++;
		}
		else{
			strcpy(cities[numberOfCities].name,staff[i].city);
			cities[numberOfCities].size=0;
			strcpy(cities[numberOfCities].member[cities[numberOfCities].size],staff[i].first);
			numberOfCities++;
			
		}
		i++;
	}
	fclose(fp);
	
	
	//output
	/**for(i=0;i<numberOfCities;i++){
		printf("City %s has %d members\n",cities[i].name,cities[i].size);
	}
	*/
	printf("Enter city name: ");
	scanf("%s",choice);
	int index=-1;
	for(i=0;i<numberOfCities;i++){
		if(strcmp(choice,cities[i].name)==0){
			index=i;
			break;
		}
	}
	if(index>=0){
		printf("City %s has %d members\n",cities[index].name,cities[index].size);
		for(i=0;i<cities[index].size;i++){
			printf("%s ",cities[index].member[i]);
		}
	}else{
		printf("City %s could not be found\n",choice);
	}
	
	return 0;
	
}
