/**
 * File:         qsort_basecode.c
 * Author:       Risto Heinsar
 * Modified:     25.02.2017
 * Created:      10.02.2015
 *
 * Description:  Base code for qsort and file division lab task.
 */
#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"


/**
 * Start off by moving the prototypes, structures and macros to the header file.
 * After that's done, create another code file and start implementing functions.
 * You can add more functions if you need to.
 *
 * Graded moments:
 *      1) Basic calculations that return the answer and print the result in
 *         main() function.
 *      2) Sorting of the basic arrays using qsort
 *      3) Sorting of the structures based on price using qsort
 */


int main(void)
{
    unsigned option;
	int ha=1;
    /* initialized variables to be used with functions */
    float num1 = 4.7f;
    float num2 = 5.2f;
    int numArr1[] = {15, 25, 3, 19, 22, 17, -54, 0, 9};
    float numArr2[] = {76.40f, 11.2f, 235.4f, 76.50f, 341.6f};
    product prices[] = {{0.55f, "Milk"}, {0.89f, "Yogurt"}, {4.19f, "Cucumber"},
                        {1.09f, "Orange"}, {0.50f, "Bread"}, {0.99f, "Juice"}};


    while (ha==1)
    {
        printf("\n\nSelect your action!\n\n");
        printf("1. Add        (num1 + num2)\n");
        printf("2. Subtract   (num1 - num2)\n");
        printf("3. Multiply   (num1 * num2)\n");
        printf("4. Divide     (num1 / num2)\n");
        printf("5. Exponent   (num1 ^ num2)\n");
        printf("6. Sort integers (numArr1)\n");
        printf("7. Sort decimals (numArr2)\n");
        printf("8. Sort structures\n");
        printf("0. Exit\n");
        scanf("%u", &option);
        switch (option)
        {
            case 1:
                printf("%.2f+%.2f = %.2f\n",num1,num2,Add(num1,num2));
                break;
            case 2:
                printf("%.2f-%.2f = %.2f\n",num1,num2,Subtract(num1,num2));
                break;
            case 3:
                printf("%.2f*%.2f = %.2f\n",num1,num2,Multiply(num1,num2));
                break;
            case 4:
                printf("%.2f/%.2f = %.2f\n",num1,num2,Divide(num1,num2));
                break;
            case 5:
                printf("%.2f^%d = %.2f\n",num1,(int)num2,Exponent(num1,num2));
                break;
            case 6:
				qsort(numArr1,sizeof(numArr1)/sizeof(int),sizeof(int),ComparFuncInt);
                printf("Sorted integers:\n");
                for(int i=0;i<sizeof(numArr1)/sizeof(int);i++){
					printf("%d\n",numArr1[i]);
				}
                break;
            case 7:
                qsort(numArr2,sizeof(numArr2)/sizeof(float),sizeof(float),ComparFuncFloat);
                printf("Sorted Floats:\n");
                for(int i=0;i<sizeof(numArr2)/sizeof(float);i++){
					printf("%.2f \n",numArr2[i]);
				}
				break;
            case 8:
                qsort(prices,sizeof(prices)/sizeof(product),sizeof(product),ComparFuncStruct);
                printf("Sorted stuct:\n");
                for(int i=0;i<sizeof(prices)/sizeof(product);i++){
					printf("%.2lf\t%s\n",(prices+i)->price,(prices+i)->name);
				}
                break;
            case 0:
                // Exit
                ha=0;
                break;
            default:
                printf("Only selections from 1 to 7 and 0 are accepted\n");
        }
    }
    return 0;
}

