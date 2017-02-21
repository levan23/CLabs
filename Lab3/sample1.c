#include <stdio.h>
#include <string.h>

struct employee{
	int employeeCode;
	char firstName[15];
	float wage;
};

int main(void){
	struct employee manager;
	manager.employeeCode=75;
	manager.wage=14.23;
	strcpy(manager.firstName,"Levan");
	printf("Employee %d, %s makes %2.2f in an hour\n",
		manager.employeeCode,manager.firstName,manager.wage);
	return 0;
	
}
