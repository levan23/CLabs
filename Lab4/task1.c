#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 20
#define INPUT_FILE1 "products.txt"
#define INPUT_FILE2 "warehouse.txt"


typedef struct product{
	int code;
	char name[20];
	float sales;
	int num;
}product;

typedef struct warehouse{
	int code;
	int stock;
	int num;
}warehouse;

void sort(product products[], int number,warehouse warehouses[]);
void findProd(product *p1,warehouse *p2, int number);
int main(void){
	int i=0;
	int j=0;
	int prodSum=0;
	int index=0;
	product products[MAX];
	warehouse warehouses[MAX];
	
	FILE *fp1 = fopen(INPUT_FILE1, "r");
	
	if(fp1==NULL){
		perror("Error opening file");
		exit(1);
	}
	while(fscanf(fp1,"%d %s %f",&products[i].code,products[i].name,&products[i].sales)==3){
		prodSum++;
		i++;
	}
	fclose(fp1);
	FILE *fp2 = fopen(INPUT_FILE2, "r");
	if(fp1==NULL){
		perror("Error opening file2");
		exit(1);
	}
	i=0;
	while(fscanf(fp2,"%d %d",&warehouses[i].code,&warehouses[i].stock)==2){
		i++;
	}
	fclose(fp2);
	
	i=0;
	sort(products,prodSum,warehouses);
	findProd(products,warehouses,prodSum);
	printf("Sorted\n");
	for(i=0;i<prodSum;i++){
		printf("%s %d %.2f\n",products[i].name,warehouses[i].stock,products[i].sales);
	}
	
	
	
	return 0;
}

void sort(product products[], int number,warehouse warehouses[]){
	int i,j;
	for(i=0;i<number;i++){
		for(j=i+1;j<number;j++){
			if(strcmp(products[i].name,products[j].name)>0){
				products[number+1]=products[i];
				products[i]=products[j];
				products[j]=products[number+1];
				warehouses[number+1]=warehouses[i];
				warehouses[i]=warehouses[j];
				warehouses[j]=warehouses[number+1];
			}
		}
	}
	/**
	for(i=0;i<number;i++){
		printf("%s\n",products[i].name);
	}
	* */
	printf("Now everything is sorted... BOOM\n");
}


void findProd(product *p1,warehouse *p2, int number){
	printf("products that run out of stock\n");
	int i;
	for(i=0;i<number;i++){
		if(((p1+i)->sales)>((p2+i)->stock)/3){
			printf("%s %d %.2f %d\n",(p1+i)->name,(p1+i)->code,(p1+i)->sales,(p2+i)->stock);
			
		}
	}
}
	
