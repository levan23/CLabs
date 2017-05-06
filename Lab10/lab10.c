#include <stdio.h>
#include <stdlib.h>

int sum(int n);
int power(int n,int y);
int fibonacci(int n);
int multiply(float x,float y);
int main(void){
	int fact,x,y;
	printf("put number\n");
	scanf("%d",&fact);
	printf("Sum of %d: %d\n",fact,sum(fact));
	
	printf("X: \n");
	scanf("%d",&x);
	printf("y\n");
	scanf("%d",&y);
	printf("Power of %d to %d : %d\n",x,y,power(x,y));
	
	int fibNum;
	printf("Say fibonacci number ! : \n");
	scanf("%d",&fibNum);
	
	printf("Fibonacci of %d: ",fibNum);
	for(int i=0;i<fibNum;i++){
		printf(" %d ",fibonacci(i));
	}
	
	
	
	return 0;
}

int sum(int n){
	if(n<=0)return 0;
	if(n==1){
		return 1;
	}
	return n+sum(n-1);
}

int power(int n,int y){
	if(y==1)return n;
	return n*power(n,y-1);
}

int fibonacci(int n){
	if(n==0)return 0;
	if(n==1)return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}

int multiply(float x,float y){
		
		return 0;
	}
