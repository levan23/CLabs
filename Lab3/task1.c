
#include <stdio.h>
#include <stdlib.h>
#include "grades.h"

int main(void)
{
    char subjects[MAX_SUBJECTS][MAX_NAME];
    int gradeCounts[MAX_SUBJECTS], grades[MAX_SUBJECTS][MAX_GRADES];
    int totalSubjects;

    totalSubjects = ReadFile(subjects, gradeCounts, grades);
    OutputData(totalSubjects, subjects, gradeCounts, grades);
    return 0;
}

/**
 * Description:    Reads the content from a file into arrays. The first
 *                 index will define the subject row in each of the arrays.
 *                 e.g.
 *
 * Parameters:     courses - 2-dim array to populate with subject names
 *                 counts - array to populate with total number of grades
 *                               given in each of the subject
 *                 results - 2-dim array to populate with the grades
 *
 * Return:         integer, total subjects read from the file
 */
int ReadFile(char courses[][MAX_NAME], int *counts, int results[][MAX_GRADES])
{

    int i, j;
    FILE *fi = fopen(INPUT_FILE, "r");
    
    /* Check if input file was opened successfully */
    if (fi == NULL)
    {
        /* display the descriptive error message from stderr before exit */
        perror("Error opening file");
        exit(EXIT_FILE_OPEN_FAIL);
    }

    i = 0;

    /* Get the subject name and grade count first */
    while (fscanf(fi, "%s %d", courses[i], &counts[i]) == 2)
    {
        /* Now that we know the amount of grades there are, we can scan them */
        for (j = 0; j < counts[i]; j++)
        {
            fscanf(fi, "%d", &results[i][j]);
        }
        i++;
    }
    return i;
}

/**
 * Description:    Outputs the grade slips for each subject stored in the arrays
 *
 * Parameters:     courses - 2-dim array containing subject names
 *                 counts - array, number of grades for each subject
 *                 results - 2-dim array containing the grades
 *
 * Return:         none
 */
void OutputData(int totalSubjects, char courses[][MAX_NAME],
                int *counts, int results[][MAX_GRADES])
{
    int i, j;
    for (i = 0; i < totalSubjects; i++)
    {
        printf("Subject '%s' has %d grades: ", courses[i], counts[i]);
        for (j = 0; j < counts[i]; j++)
        {
            printf("%3d", results[i][j]);
        }
        printf("\n");
    }
}
