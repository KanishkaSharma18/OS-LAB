// Write a program in C to find the second-smallest element in an array.

#include <stdio.h>

int findSecondSmallest(int arr[], int n) {
    int smallest = arr[0], secondSmallest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    return secondSmallest;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int secondSmallest = findSecondSmallest(arr, n);

    if (secondSmallest == -1) {
        printf("There is no second smallest element.\n");
    } else {
        printf("The second smallest element is: %d\n", secondSmallest);
    }

    return 0;
}
