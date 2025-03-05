//Write a program in C to delete an element at a desired position from an array.

#include<stdio.h>

int main() {
    int n, pos;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {

        for (int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("Array after deletion: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
