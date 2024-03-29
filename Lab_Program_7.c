#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a non-zero element in the sparse matrix
typedef struct Node {
    int row, col, value;
    struct Node* next;
} Node;

// Sparse matrix structure
typedef struct {
    int rows, cols;
    Node** rowsArray;
} SparseMatrix;

// Function to create a new sparse matrix
SparseMatrix* createSparseMat(int rows, int cols) {
    SparseMatrix* mat = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->rowsArray = (Node**)calloc(rows, sizeof(Node*));
    return mat;
}

// Function to set the value at the specified row and column
void setValue(SparseMatrix* mat, int row, int col, int value) {
    if (row >= 0 && row < mat->rows && col >= 0 && col < mat->cols) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = mat->rowsArray[row];
        mat->rowsArray[row] = newNode;
    } else {
        printf("Invalid row or column index\n");
    }
}

// Function to get the value at the specified row and column
int getValue(SparseMatrix* mat, int row, int col) {
    Node* current = mat->rowsArray[row];
    while (current != NULL) {
        if (current->col == col) {
            return current->value;
        }
        current = current->next;
    }
    return 0; // Default value for non-existing elements
}

// Function to add the specified value to the existing value at the specified row and column
void addValue(SparseMatrix* mat, int row, int col, int value) {
    Node* current = mat->rowsArray[row];
    while (current != NULL) {
        if (current->col == col) {
            current->value += value;
            return;
        }
        current = current->next;
    }
    // If the element does not exist, create a new node with the specified value
    setValue(mat, row, col, value);
}

// Function to remove the value at the specified row and column
void removeValue(SparseMatrix* mat, int row, int col) {
    Node* current = mat->rowsArray[row];
    Node* prev = NULL;
    while (current != NULL) {
        if (current->col == col) {
            if (prev == NULL) {
                mat->rowsArray[row] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to get the number of rows in the sparse array
int getNumRows(SparseMatrix* mat) {
    return mat->rows;
}

// Function to get the number of columns in the sparse array
int getNumCols(SparseMatrix* mat) {
    return mat->cols;
}

// Function to calculate the transpose of the sparse array
SparseMatrix* transpose(SparseMatrix* mat) {
    SparseMatrix* transposedMat = createSparseMat(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        Node* current = mat->rowsArray[i];
        while (current != NULL) {
            setValue(transposedMat, current->col, current->row, current->value);
            current = current->next;
        }
    }
    return transposedMat;
}

// Function to multiply each element of the sparse array by the specified scalar factor
void multiplyScalar(SparseMatrix* mat, int factor) {
    for (int i = 0; i < mat->rows; i++) {
        Node* current = mat->rowsArray[i];
        while (current != NULL) {
            current->value *= factor;
            current = current->next;
        }
    }
}

// Function to add another sparse array to this sparse array element-wise
void add(SparseMatrix* mat, SparseMatrix* otherMat) {
    if (mat->rows != otherMat->rows || mat->cols != otherMat->cols) {
        printf("Matrix dimensions do not match for addition\n");
        return;
    }

    for (int i = 0; i < mat->rows; i++) {
        Node* current = otherMat->rowsArray[i];
        while (current != NULL) {
            addValue(mat, i, current->col, current->value);
            current = current->next;
        }
    }
}

// Function to multiply this sparse array by another sparse array (matrix multiplication)
SparseMatrix* multiply(SparseMatrix* mat, SparseMatrix* otherMat) {
    if (mat->cols != otherMat->rows) {
        printf("Matrix dimensions do not match for multiplication\n");
        return NULL;
    }

    SparseMatrix* resultMat = createSparseMat(mat->rows, otherMat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < otherMat->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat->cols; k++) {
                sum += getValue(mat, i, k) * getValue(otherMat, k, j);
            }
            setValue(resultMat, i, j, sum);
        }
    }
    return resultMat;
}

// Function to convert the sparse array to a dense array representation
int** toDenseArray(SparseMatrix* mat) {
    int** denseArray = (int**)malloc(mat->rows * sizeof(int*));
    for (int i = 0; i < mat->rows; i++) {
        denseArray[i] = (int*)malloc(mat->cols * sizeof(int));
        for (int j = 0; j < mat->cols; j++) {
            denseArray[i][j] = getValue(mat, i, j);
        }
    }
    return denseArray;
}

// Function to print the sparse matrix
void printSparseMat(SparseMatrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        Node* current = mat->rowsArray[i];
        while (current != NULL) {
            printf("(%d, %d, %d) ", current->row, current->col, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the sparse matrix
void freeSparseMat(SparseMatrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        Node* current = mat->rowsArray[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(mat->rowsArray);
    free(mat);
}

// Example usage
int main() {
    SparseMatrix* mat1 = createSparseMat(3, 4);
    setValue(mat1, 0, 0, 1);
    setValue(mat1, 0, 2, 2);
    setValue(mat1, 1, 1, 3);
    setValue(mat1, 2, 3, 4);

    printf("Sparse Matrix 1:\n");
    printSparseMat(mat1);

    printf("\nValue at (1, 1): %d\n", getValue(mat1, 1, 1));

    addValue(mat1, 1, 1, 2);
    printf("\nAfter adding 2 to (1, 1):\n");
    printSparseMat(mat1);

    removeValue(mat1, 0, 0);
    printf("\nAfter removing (0, 0):\n");
    printSparseMat(mat1);

    printf("\nTranspose of Sparse Matrix 1:\n");
    SparseMatrix* transposedMat = transpose(mat1);
    printSparseMat(transposedMat);
    freeSparseMat(transposedMat);

    multiplyScalar(mat1, 2);
    printf("\nAfter multiplying by 2:\n");
    printSparseMat(mat1);

    SparseMatrix* mat2 = createSparseMat(4, 3);
    setValue(mat2, 0, 1, 1);
    setValue(mat2, 1, 0, 2);
    setValue(mat2, 2, 2, 3);
    setValue(mat2, 3, 1, 4);

    printf("\nSparse Matrix 2:\n");
    printSparseMat(mat2);

    add(mat1, mat2);
    printf("\nAfter adding Sparse Matrix 2 to Sparse Matrix 1:\n");
    printSparseMat(mat1);

    SparseMatrix* mat3 = multiply(mat1, mat2);
    printf("\nResult of multiplication (Matrix 1 * Matrix 2):\n");
    printSparseMat(mat3);
    freeSparseMat(mat3);

    int** denseArray = toDenseArray(mat1);
    printf("\nDense Array representation of Sparse Matrix 1:\n");
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            printf("%d ", denseArray[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    freeSparseMat(mat1);
    freeSparseMat(mat2);
    for (int i = 0; i < mat1->rows; i++) {
        free(denseArray[i]);
    }
    free(denseArray);

    return 0;
}
