// Write a program in C to find the second-largest element in an array.

#include <stdio.h>

int findSecondlargest(int arr[], int n) {
    int largest = arr[0], secondlargest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondlargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondlargest && arr[i] != largest) {
            secondlargest = arr[i];
        }
    }

    return secondlargest;
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
    int second = findSecondlargest(arr, n);

    if (second == -1) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element is: %d\n", second);
    }

    return 0;
}
