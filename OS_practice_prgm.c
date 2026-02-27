#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // Return index if found
    }
    return -1;  // Not found
}

// Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Element found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // Not found
}

int main() {
    int arr[100], n, key, i, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("\nChoose Search Method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = linearSearch(arr, n, key);
            if (result != -1)
                printf("Element found at index %d using Linear Search.\n", result);
            else
                printf("Element not found using Linear Search.\n");
            break;

        case 2:
            result = binarySearch(arr, n, key);
            if (result != -1)
                printf("Element found at index %d using Binary Search.\n", result);
            else
                printf("Element not found using Binary Search.\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
