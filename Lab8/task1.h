#ifndef GENERATOR
#define GENERATOR


//structs
typedef struct person{
	int id;
	char *name;
	char *surname;
	int age;
}person;

//functions

int GetRand(int numMin, int numMax);
int ComparFunc(const void *a,const void *b);

#endif
