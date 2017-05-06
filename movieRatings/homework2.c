/**
 * File:	Homework2_Levan_Salia_145368.c
 * Author:	Levan Salia
 * Created:	04.05.2017
 * Edited:	04.05.2017
 * 
 * Description: Homework2
 */
#include <stdio.h>
#include <stdlib.h>
#include "homework2.h"
#include <string.h>

#define LINE_LEN 100
#define SIZE 20

int main(void){
	int movieCount,ratingCount,i;
	movie *movies;
	rating *ratings;
	
	movies = readMovies(&movieCount);
	ratings = readRatings(&ratingCount);
	
	
	for(i=0;i<ratingCount;i++){
		free((ratings+i)->reviewerName);
		free((ratings+i)->status);
	}
	
	free(movies);
	free(ratings);
	
	return 0;
}

movie *readMovies(int *movieCount){
	int i=0;
	char line[LINE_LEN];
	
	FILE *pRead = fopen("movies.txt","r");
	if(pRead==NULL){
		perror("Error opening specified file");
		exit(1);
	}
	
	movie *movies = NULL, *TempPontr = NULL;
	
	while(fgets(line,LINE_LEN,pRead)!= NULL){
		TempPontr = (movie*)realloc(movies,sizeof(movie)*(i+1));
		
		if(TempPontr == NULL){
			perror("no more memory");
			exit(1);
		}else{
			movies = TempPontr;
			
			(movies+i)->movieCode = atoi(strtok(line,"-"));
			(movies+i)->name = strtok(NULL,"-");
			(movies+i)->year = atoi(strtok(NULL, "-"));
			(movies+i)->length = atoi(strtok(NULL, "-"));
			(movies+i)->director = strtok(NULL, "-");
			printf("%d %s %d %d %s\n",(movies+i)->movieCode,(movies+i)->name,(movies+i)->year,(movies+i)->length,(movies+i)->director);
			
		}
		i++;
	}
	
	*movieCount = i;
	fclose(pRead);
	
	return movies;
}

rating *readRatings(int *ratingCount){
	int i=0;
	char line[LINE_LEN];
	
	FILE *pRead = fopen("ratings.txt","r");
	if(pRead==NULL){
		perror("Error opening specified file");
		exit(1);
	}
	rating *ratings = NULL, *TempPontr = NULL;
	
	while(fgets(line,LINE_LEN,pRead)!= NULL){
		TempPontr= (rating*)realloc(ratings,sizeof(rating*)*(i+1));
		
		if(TempPontr == NULL){
			perror("no more memory");
			exit(1);
		}else{
			ratings = TempPontr;
			(ratings+i)->reviewerName = (char*)calloc(SIZE,sizeof(char));
			(ratings+i)->status = (char*)calloc(SIZE,sizeof(char));
			
			
			(ratings+i)->reviewId = atoi(strtok(line,"-"));
			(ratings+i)->movieCode = atoi(strtok(NULL,"-"));
			(ratings+i)->reviewerName = strtok(NULL,"-");
			(ratings+i)->status = strtok(NULL,"-");
			(ratings+i)->movieRating = atof(strtok(NULL,"-"));
			
			printf("%d %d %s %s %.1f\n",(ratings+i)->reviewId,(ratings+i)->movieCode,(ratings+i)->reviewerName,(ratings+i)->status,(ratings+i)->movieRating);
			
		}
		i++;
	}
	
	
	*ratingCount = i;
	fclose(pRead);
	
	return ratings;
}
