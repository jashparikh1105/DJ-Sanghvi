#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    double t1, t2, t3;
    int ar[10000], n, i, s, f = 0;
    int num_searches = 100;

    for (i = 0; i < 10000; i++)
        ar[i] = rand() % 10000;

    s = ar[0]; // Best Case
    printf("\nJash Parikh, C065, 60004220080\n");
    printf("\nBest Case - Searching for element %d", s);
    t1 = clock();
    if (ar[0] == s)
        printf("\nSearch Successful. Element Found.");
    else
        printf("\nSearch Unsuccessful. Element not Found.");
    t2 = clock();
    t3 = (t2 - t1) / (double)CLOCKS_PER_SEC;
    printf("\nTime taken for Best Case: %f seconds \n", t3);

    // Worst Case
    s = -1;
    printf("\nWorst Case - Searching for element %d", s);
    t1 = clock();
    for (i = 0; i < 10000; i++) {
        if (ar[i] == s) {
            f = 1;
            break;
        }
    }
    if (f == 1)
        printf("\nSearch Successful. Element Found.");
    else
        printf("\nSearch Unsuccessful. Element not Found.");
    t2 = clock();
    t3 = (t2 - t1) / (double)CLOCKS_PER_SEC;
    printf("\nTime taken for Worst Case: %f seconds \n", t3);

    // Average Case
    s = rand() % 10000;
    printf("\nAverage Case - Searching for element %d", s);
    f = 0;
    t1 = clock();
    for (i = 0; i < 10000; i++) {
        if (ar[i] == s) {
            f = 1;
            break;
        }
    }
    if (f == 1)
        printf("\nSearch Successful. Element Found.");
    else
        printf("\nSearch Unsuccessful. Element not Found.");
    t2 = clock();
    t3 = (t2 - t1) / (double)CLOCKS_PER_SEC;
    printf("\nTime taken for Average Case: %f seconds \n", t3);
}
