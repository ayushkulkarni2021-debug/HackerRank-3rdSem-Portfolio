#include <stdio.h>
#include <stdlib.h>

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int** arr = malloc(n * sizeof(int*));
    int* sizes = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = NULL;
    }

    int lastAnswer = 0;

    int* result = malloc(queries_rows * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            arr[idx] = realloc(arr[idx], (sizes[idx] + 1) * sizeof(int));
            arr[idx][sizes[idx]] = y;
            sizes[idx]++;
        }
        else if (type == 2) {
            lastAnswer = arr[idx][y % sizes[idx]];
            result[*result_count] = lastAnswer;
            (*result_count)++;
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

    free(arr);
    free(sizes);

    return result;
}