//Write a program in C to find the sum of rows and columns of a matrix.

#include<stdio.h>

int main() {
    int n, m;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &n, &m);

    int arr[n][m];

    printf("Enter matrix elements: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int rowSum[n], colSum[m];

    for (int i = 0; i < n; i++) {
        rowSum[i] = 0;
    }
    for (int j = 0; j < m; j++) {
        colSum[j] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Sum of row %d: %d\n", i + 1, rowSum[i]);
    }

    for (int j = 0; j < m; j++) {
        printf("Sum of column %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}

