#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define INPUT_FILE "data_short.txt"


#define MAX 20
#define MAX_NUMBER 220

typedef struct employee{
	int id;
	char first[MAX];
	char last[MAX];
	char city[MAX];
}employee;

typedef struct place{
	char member[MAX_NUMBER][20];
	char name[20];
	int size;
}place;

void sort(employee staff[],int number);
void partialSearch(place cities[],int number);
int strcmpi(char* s1, char* s2);

int main(void){
	employee staff[MAX_NUMBER];
	place cities[MAX_NUMBER];
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
		printf("City %s has %d members\n",cities[i].name,cities[i].size+1);
	}
	*/
	
	printf("Enter city name: ");
	scanf("%s",choice);
	int index=-1;
	for(i=0;i<numberOfCities;i++){
		if(strcmpi(choice,cities[i].name)==0){
			index=i;
			break;
		}
	}
	if(index>=0){
		printf("City %s has %d members\n",cities[index].name,cities[index].size+1);
		for(i=0;i<cities[index].size;i++){
			printf("%s ",cities[index].member[i]);
		}
	}else{
		printf("City %s could not be found\n",choice);
	}
	
	partialSearch(cities,numberOfCities);
	return 0;
	
}

void sort(employee staff[],int number){
	
}
void partialSearch(place cities[],int number){
	char choice[MAX];
	int i;
	int count=0;
	printf("Partial search allowed\n");
	printf("Enter city name: ");
	scanf("%s",choice);
	for(i=0;i<number;i++){
		if(strstr(cities[i].name,choice)!=NULL){
			printf("City %s has %d members\n",cities[i].name,cities[i].size+1);
			count++;
		}
	}
	printf("Match from total: %d/%d\n",count,number);
}
int strcmpi(char* s1, char* s2){
    int i;
     
    if(strlen(s1)!=strlen(s2))
        return -1;
         
    for(i=0;i<strlen(s1);i++){
        if(toupper(s1[i])!=toupper(s2[i]))
            return s1[i]-s2[i];
    }
    return 0;
}
