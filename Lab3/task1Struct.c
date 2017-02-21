#include <stdio.h>
#include <stdlib.h>
#include "grades.h"

#define MAX_NAME 32
#define MAX_SUBJECTS 15
#define MAX_GRADES 20

#define INPUT_FILE "grades.txt"

typedef struct subjects{
	char name[MAX_NAME];
	int sumOfGrades;
	int grades[MAX_GRADES];
	int numberOfGrades;
	float average;
	
} subjects;

int main(void){
	
	subjects all[MAX_SUBJECTS];
	
	//Read from file
	FILE *fp = fopen(INPUT_FILE, "r");
	
	if(fp==NULL){
		perror("Error opening file");
		exit(1);
	}
	int numberOfSubjects;
	int i=0;
	int j=0;
	while(fscanf(fp,"%s %d",all[i].name, &all[i].numberOfGrades)==2){
		all[i].sumOfGrades=0;
		for(j=0;j<all[i].numberOfGrades;j++){
			fscanf(fp,"%d", &all[i].grades[j]);
			all[i].sumOfGrades+=all[i].grades[j];
		}
		all[i].average=(float)all[i].sumOfGrades/all[i].numberOfGrades;
		i++;
	}
	numberOfSubjects=i;
	
	//Output 
	for(i=0;i<numberOfSubjects;i++){
		printf("Subject %s has %d grades: ",all[i].name,all[i].numberOfGrades);
		for(j=0;j<all[i].numberOfGrades;j++){
			printf("%3d", all[i].grades[j]);
		}
		printf("\tAverage score is: %.2f",all[i].average);
		printf("\n");
	}
	
	return 0;
}


	
	
