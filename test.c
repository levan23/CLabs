/**
 * File:	Test1_Levan_Salia_145368.c
 * Author:	Levan Salia
 * Created:	08.03.2017
 * Edited:	08.03.2017
 * 
 * Description: Test 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define SIZE 50
#define DATA_FILE "071.txt"

typedef struct tracker{
	int ID;
	char username[MAX];
	double averageSpeed;
	double maximumSpeed;
	long int timeInSeconds;
	double  distance;
	char time[MAX];
}tracker;


int ReadData(tracker *info,FILE *pRead,int i);
void Output(tracker *info,int size);
char *inHours(long time);
int main(void){
	
	tracker info[MAX];
	int size=0;
	FILE *pRead = fopen(DATA_FILE,"r");
	if(pRead==NULL){
		perror("Error opening file");
		exit(1);
	}
	size=ReadData(info,pRead,size);
	Output(info,size);
	fclose(pRead);
	return 0;
}

int ReadData(tracker *info,FILE *pRead,int i){
	int v,hr,min,sec;
	while(fscanf(pRead,"%d %s %lf %lf %ld",&(info+i)->ID,(info+i)->username,&(info+i)->averageSpeed,&(info+i)->maximumSpeed,
		&(info+i)->timeInSeconds)==5){
		
		(info+i)->distance=(info+i)->averageSpeed*(info+i)->timeInSeconds/3600;
		
		hr=((info+i)->timeInSeconds)/3600;
		v=((info+i)->timeInSeconds)%3600;
		min=v/60;
		sec=v%60;
		sprintf((info+i)->time,"%d:%d:%d",hr,min,sec);
		//printf("%d %d %d %s\n",hr,min,sec,(info+i)->time);
		i++;
	}
	return i;
}

void Output(tracker *info,int size){
	int i;
	double totalTime;
	double totalKilometers;
	FILE *pWrite = fopen("Output.txt","w");
	if(pWrite==NULL){
		perror("Error creating file");
		exit(1);
	}
	for(i=0;i<size;i++){
		if((info+i)->averageSpeed<30 && (info+i)->maximumSpeed<45
			&& (info+i)->distance<35.00){
				printf("ID: %d Average:%.2lf Maximum:%.2lf Total:%.2f Time: %s\n",(info+i)->ID,(info+i)->averageSpeed,(info+i)->maximumSpeed,
				(info+i)->distance,(info+i)->time);
				fprintf(pWrite,"ID: %d Average:%.2lf Maximum:%.2lf Total:%.2f Time: %s\n",(info+i)->ID,(info+i)->averageSpeed,(info+i)->maximumSpeed,
				(info+i)->distance,(info+i)->time);
				totalTime+=(info+i)->timeInSeconds;
				totalKilometers=(info+i)->distance;
		}
	}
	fprintf(pWrite,"Total Time: %.2lf hours\nTotal Kilometers driven: %.2lf\n",totalTime/3600,totalKilometers);
	printf("Total Time: %.2lf hours\nTotal Kilometers driven: %.2lf\n",totalTime/3600,totalKilometers);
	
	fclose(pWrite);
}


