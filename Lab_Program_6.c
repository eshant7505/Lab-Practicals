#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a node in the sparse matrix
struct Node {
    int row, col, value;
    struct Node* next;
};

// Function to check if the matrix is sparse
int isSparse(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int countNonZero = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                countNonZero++;
            }
        }
    }

    // If more than 20% of elements are non-zero, it is not sparse
    return (countNonZero <= 0.2 * rows * cols);
}

// Function to convert a matrix to a sparse matrix using linked list
struct Node* createSparseMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    struct Node* head = NULL;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->row = i;
                newNode->col = j;
                newNode->value = matrix[i][j];
                newNode->next = head;
                head = newNode;
            }
        }
    }

    return head;
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Node* head) {
    printf("Sparse Matrix:\n");
    while (head != NULL) {
        printf("(%d, %d, %d)\n", head->row, head->col, head->value);
        head = head->next;
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isSparse(matrix, rows, cols)) {
        printf("The matrix is sparse.\n");
        struct Node* sparseMatrix = createSparseMatrix(matrix, rows, cols);
        displaySparseMatrix(sparseMatrix);
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}
