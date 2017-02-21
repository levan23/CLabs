/**
 * File:        pointer.c
 * Author:      Risto Heinsar
 * Created:     23.01.2015
 * Last edit:   31.01.2016
 *
 * Description: Some samples of dereferencing, using double pointers, arrays
 *              and more.
 *              Note that %p format expects (void *) type, but the pointers are
 *              of type (int *) or (int **). The type casts should be included
 *              for better compatibility in real life situations, but were
 *              skipped on here for readability.
 */
#include <stdio.h>

#define LEN 5

int main(void)
{
    int num = 5;
    int numArr[LEN] = {5, 4, 3, 2, 3};
    int *p, **pp, *pa, *pb;
    int i;

    p = &num;
    pp = &p;
    printf("The number:\t%d\t", num);
    printf("is stored at:\t%p\n", &num);
    printf("Dereferenced:\t%d\tPointer adr:\t%p\tPoints to: %p\n\n", *p, &p, p);
    printf("Dereferencing double pointer:\t%d\n"
           "Double pointer is stored at:\t%p"
           "\tand points to:\t%p\n", **pp, &pp, pp);
    printf("When dereferenced once we see the address \t%p\n\n", *pp);

    printf("Array members and their access\n");
    pb = pa = numArr;
    for (i = 0; i < LEN; i++, pa++)
    {
        printf("Num: %d  deref: %d  deref_v2: %d  pa points to: %p  pb points to: %p\n",
               numArr[i], *pa, *(pb + i), pa, pb);
    }
    return 0;
}
