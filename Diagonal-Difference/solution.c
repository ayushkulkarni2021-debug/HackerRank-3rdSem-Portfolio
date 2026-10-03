#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int primaryDiagonal = 0;
    int secondaryDiagonal = 0;

    for (int i = 0; i < arr_rows; i++) {
        primaryDiagonal += arr[i][i];
        secondaryDiagonal += arr[i][arr_columns - 1 - i];
    }

    return abs(primaryDiagonal - secondaryDiagonal);
}