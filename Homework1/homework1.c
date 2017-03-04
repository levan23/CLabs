/**
 * File:	HW_I_Levan_Salia_145368.c
 * Author:	Levan_Salia
 * Created:	04.03.2017
 * Edited:	04.03.2017
 * 
 * Description: Solution for Homework N1
 */

#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "data.txt"
#define LIMIT 20
#define SIZE 10

typedef struct person{
	char first[LIMIT];
	char last[LIMIT];
	int phone;
	int win;
	int lose;
	double ratio;
}person;

void ReadData(person *persons,FILE *fp);
void Output(person *persons,int average);
int calculateAverage(person *persons);

int main(void){
	//int i=0;
	int average;
	person persons[SIZE];
	FILE *pRead= fopen(DATA_FILE,"r");
	if(pRead==NULL){
		perror("Error opening file2");
		exit(1);
	}
	ReadData(persons,pRead);
	average=calculateAverage(persons)/SIZE;
	Output(persons,average);
	
	fclose(pRead);
	
	return 0;
	
}

/**
 * This Method just reads the data from file "data.txt" and stores them in structure
 * Also calculates win-loss ratio of each person
 */
void ReadData(person *persons,FILE *fp){
	int i=0;
	while(fscanf(fp,"%s %s %d %d %d", (persons+i)->first,(persons+i)->last,&(persons+i)->phone,&(persons+i)->win,&(persons+i)->lose)==5){
		((persons+i)->ratio)=((double)(persons+i)->lose)/(persons+i)->win;
		i++;
	}
}
int calculateAverage(person *persons){
	int i;
	int sum=0;
	for(i=0;i<SIZE;i++){
		sum+=(persons+i)->win-(persons+i)->lose;
	}
	
	return sum;
}

/**
 * This method sorts persons based on their number of loses in the decending order
 * And after that outputs only those persons, whose profit is more than average
 * Output is stored in file : "Output.txt"
 */
void Output(person *persons,int average){
	int i,j;
	FILE *pWrite=fopen("Output.txt","w");
	person temp;
	for(i=0;i<SIZE;i++){
		for(j=i+1;j<SIZE;j++){
			if((persons+i)->lose<(persons+j)->lose){
				temp=*(persons+i);
				*(persons+i)=*(persons+j);
				*(persons+j)=temp;
			}
		}
	}
	for(i=0;i<SIZE;i++){
		if(((persons+i)->win-(persons+i)->lose)>average){
			fprintf(pWrite,"%s %s\t Phone: %d Win: %d Lose: %d Win-Lose ratio: %.3f\n",(persons+i)->first,(persons+i)->last,
					(persons+i)->phone,(persons+i)->win,(persons+i)->lose,(persons+i)->ratio);
			 printf("%s %s\t Phone: %d Win: %d Lose: %d Win-Lose ratio: %.3f\n",(persons+i)->first,(persons+i)->last,
					(persons+i)->phone,(persons+i)->win,(persons+i)->lose,(persons+i)->ratio);
		}
	}
	fclose(pWrite);
}
