//iterative binary search
#include <stdio.h>

int iterativeBinarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;  // Key found
        } else if (arr[mid] < key) {
            low = mid + 1;  // Discard left half
        } else {
            high = mid - 1;  // Discard right half
        }
    }

    return -1; 
}

int main() {
    int arr[] = {2, 4, 7, 12, 18, 24, 31, 40, 55};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    int result = iterativeBinarySearch(arr, size, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}


