#include <stdio.h>
#include <stdlib.h>
#include "generator_base.h"
#include <string.h>
#include <time.h>

#define MAX 25
#define studentMin 145300
#define studentMax 146000
int main(void)
{
	srand ( time(NULL) );
    int firstNamePoolSize, lastNamePoolSize;
    char *firstNames[] = FIRST_NAME_POOL;
    char *lastNames[] = LAST_NAME_POOL;
	int auto_increment=0;

    // Find the counts for the pool sizes, these numbers may differ!
    // Size of the pointer array divided by the size of a single pointer.
    firstNamePoolSize = sizeof(firstNames) / sizeof(char*);
    lastNamePoolSize = sizeof(lastNames) / sizeof(char*);
	
    printf("The database contains %d first names and %d last names\n",
        firstNamePoolSize, lastNamePoolSize);


    // ask the user for how many elements are needed and assign memory to them
    int N;
	printf("How many records are needed?\n");
	scanf("%d",&N);
	student *students;
	students = (student*)calloc(N,sizeof(student));
	
	// Allocate memory
	if(students==NULL){
		printf("Not enough memory\n");
		exit(1);
	}
	
	for(int i=0;i<N;i++){
		(students+i)->name = (char*)calloc(MAX,sizeof(char));
		(students+i)->surname = (char*)calloc(MAX,sizeof(char));
		if((students+i)->name ==NULL || (students+i)->surname==NULL){
			printf("Not enough memory for names");
			exit(1);
		}
	}
	
    // start your generation code here
	for(int i=0;i<N;i++){
		strcpy((students+i)->name,*(firstNames+(GetRand(0,firstNamePoolSize))));
		strcpy((students+i)->surname,*(lastNames+(GetRand(0,lastNamePoolSize))));
		(students+i)->index=auto_increment++;
		(students+i)->grade=GetRand(0,100);
		(students+i)->studentCode=GetRand(studentMin,studentMax);
		
	}

	
    // don't forget to sort the array
	
	qsort(students,N,sizeof(student),ComparFunc);

    // and then output it to the destination file
   FILE *pWrite = fopen("Output.txt","w");
    if(pWrite==NULL){
		perror("Error creating file");
		exit(1);
	}
	
	
	for(int i=0;i<N;i++){
		fprintf(pWrite,"%s %s: %d %d\n",(students+i)->surname,(students+i)->name,(students+i)->studentCode,(students+i)->grade);
		
	}
	printf("Added to file\n");
	fclose(pWrite);
	
    // When done, free everything you allocated memory for!
    
    for(int i=0;i<N;i++){
		free((students+i)->name);
		free((students+i)->surname);
	}
	free(students);
    return 0;
}

int ComparFunc(const void *a,const void *b){
	student *pa = (student*)a;
	student *pb = (student*)b;
	return strcmp(pa->surname,pb->surname);
}

/**
 * Description:    Generates a random number in range provided, ends inclusive
 *
 * Parameters:     numMin, integer, minimum value
 *                 numMax, integer, maximum vale
 *
 * Return:         integer, generated random number
 */
int GetRand(int numMin, int numMax)
{
    return (rand() % (numMax - numMin)) + numMin;
}
