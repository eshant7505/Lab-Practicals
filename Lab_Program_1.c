//static
#include <stdio.h>

void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;  // Element not found
}

void insertElement(int arr[], int *size, int position, int element) {
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void deleteElement(int arr[], int *size, int position) {
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
void updateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            arr[i] += 5;
        } else {
            arr[i] *= 2;
        }
    }
}
int main() {
    int size, choice, element, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n1. Linear Search\n2. Insert Element\n3. Delete Element\n");
        printf("4. Reverse Array\n5. Update Array\n6. Display Array\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
  switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                position = linearSearch(arr, size, element);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 2:
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &size, position, element);
                printf("Element inserted successfully\n");
                break;

            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                if (position >= 0 && position < size) {
                    deleteElement(arr, &size, position);
                    printf("Element deleted successfully\n");
                } else {
                    printf("Invalid position\n");
                }
                break;

            case 4:
                reverseArray(arr, size);
                printf("Array reversed successfully\n");
                break;

            case 5:
                updateArray(arr, size);
                printf("Array updated successfully\n");
                break;

            case 6:
                displayArray(arr, size);
                break;

            case 0:
                printf(" leave the program. get out!\n");
                break;

            default:
                printf("Invalid choice. Please try again later.\n");
        }
    } while (choice != 0);


    return 0;
}