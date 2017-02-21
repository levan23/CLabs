/**
 * File:        grades.h
 * Author:      Risto Heinsar
 * Created:     08.02.2017
 *
 * Description: Contains constants and prototypes used in the grades sample
 */


/**
 * Avoid including the header more than once from multiple files
 * if GRADES_H are not defined (ifndef), define GRADES_H
 */

#ifndef GRADES
#define GRADES

/* array limits */
#define MAX_NAME 32
#define MAX_SUBJECTS 15
#define MAX_GRADES 20
/* data file */
#define INPUT_FILE "grades.txt"
/* custom exit code(s) */
#define EXIT_FILE_OPEN_FAIL -1

/**
 * if you choose to use this as your base code for task 1, it's recommended that
 * you place your structure declaratin for a SINGLE subject here! Right before
 * the function prototypes and after the constants.
 */

/* function prototypes */
int ReadFile(char courses[][MAX_NAME], int *counts, int grades[][MAX_GRADES]);
void OutputData(int totalSubjects, char courses[][MAX_NAME],
                int *counts, int grades[][MAX_GRADES]);


#endif // GRADES
