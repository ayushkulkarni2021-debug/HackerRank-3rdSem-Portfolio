#include <stdio.h>
#include <stdlib.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int alice = 0;
    int bob = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            alice++;
        }
        else if (a[i] < b[i]) {
            bob++;
        }
    }

    *result_count = 2;

    int* result = malloc(2 * sizeof(int));

    result[0] = alice;
    result[1] = bob;

    return result;
}