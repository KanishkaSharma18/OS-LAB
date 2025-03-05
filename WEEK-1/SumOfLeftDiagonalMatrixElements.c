 // Write a program in C to find the sum of the left diagonals of a matrix.

#include<stdio.h>

int main() {
    int n, m, sum = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &n, &m);

    if (n != m) {
        printf("Matrix must be square to have a left diagonal.\n");
        return 1;
    }
    int arr[n][m];

    printf("Enter matrix elements: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i][i];

    printf("Sum of left diagonal elements: %d\n", sum);

    return 0;
}
