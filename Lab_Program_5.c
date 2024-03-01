#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of the matrix:\n");
    int zeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    if (zeroCount > (rows * cols) / 2) {
        printf("The given matrix is sparse.\n");

        // Generate sparse matrix
        printf("Sparse Matrix:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    printf("%d %d %d\n", i, j, matrix[i][j]);
                }
            }
        }
    } else {
        printf("The given matrix is not sparse.\n");
    }

    return 0;
}

