//4. Write a program in C to count the total number of duplicate elements in an array.

#include<stdio.h>

int main() {
    int n, count = 0;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == -1) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1;
                break;
            }
        }
    }

    printf("Number of duplicate elements in the array: %d\n", count);

    return 0;
}
