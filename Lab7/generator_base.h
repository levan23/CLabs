#ifndef GENERATOR
#define GENERATOR

#define FIRST_NAME_POOL {"Ants", "Kadri", "Artur", "Urmas", "Mart", "Toomas",\
    "Mihhail", "Yana", "Taavi", "Edgar", "Keit", "Ivari", "Sven", "Hanno",\
    "Kristen", "Anne", "Urve", "Heimar", "Andres", "Juhan", "Rainer", "Ain",\
    "Maris", "Eiki", "Valdo", "Mihkel", "Marika", "Jevgeni", "Mailis", "Rein",\
    "Helir-Valdor", "Heidy"}
#define LAST_NAME_POOL {"Toom", "Padar", "Sulling", "Savisaar", "Helme",\
    "Ratas", "Ligi", "Paet", "Kruuse", "Talvik", "Simson", "Laaneots",\
    "Pentus-Rosimannus", "Mikser", "Pevkur", "Michal", "Stalnuhhin", "Tiidus",\
    "Lenk", "Herkel", "Parts", "Vakra", "Lutsepp", "Lauri", "Nestor",\
    "Randpere", "Raud", "Anvelt", "Tuus-Laul", "Ossinovski", "Reps", "Ratas",\
    "Seeder", "Purga"}

/* add your structure declaration here */
typedef struct student{
	char *name;
	char *surname;
	int index;
	int studentCode;
	int grade;
}student;

/* function prototypes */
int GetRand(int numMin, int numMax);
int ComparFunc(const void *a,const void *b);



#endif
