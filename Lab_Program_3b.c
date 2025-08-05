//recursive binary search
#include <stdio.h>

int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;  
        } else if (arr[mid] < key) {
            return recursiveBinarySearch(arr, mid + 1, high, key);  // Search in right half
        } else {
            return recursiveBinarySearch(arr, low, mid - 1, key);  // Search in left half
        }
    }

    return -1; 
}

int main() {
    int arr[] = {2, 4, 7, 12, 18, 24, 31, 40, 55};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    int result = recursiveBinarySearch(arr, 0, size - 1, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
