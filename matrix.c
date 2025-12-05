#include <stdio.h>

void inputMatrix(int matrix[10][10], int rows, int cols);
void displayMatrix(int matrix[10][10], int rows, int cols);
void addMatrix(int A[10][10], int B[10][10], int result[10][10], int r, int c);
void multiplyMatrix(int A[10][10], int B[10][10], int result[10][10], int r1, int c1, int c2);
void transposeMatrix(int A[10][10], int result[10][10], int r, int c);

int main() {
    int A[10][10], B[10][10], result[10][10];
    int r1, c1, r2, c2, choice;

    while (1) {
        printf("\n===== MATRIX OPERATIONS MENU =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting Program. Thank you!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("\nEnter rows and columns of matrices: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter Matrix B:\n");
                inputMatrix(B, r1, c1);

                addMatrix(A, B, result, r1, c1);

                printf("\nResult (A + B):\n");
                displayMatrix(result, r1, c1);

                break;

            case 2:
                printf("\nEnter rows & columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter rows & columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2) {
                    printf("\nMultiplication not possible! (Columns of A must equal rows of B)\n");
                    break;
                }

                printf("Enter Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter Matrix B:\n");
                inputMatrix(B, r2, c2);

                multiplyMatrix(A, B, result, r1, c1, c2);

                printf("\nResult (A × B):\n");
                displayMatrix(result, r1, c2);

                break;

            case 3:
                printf("\nEnter rows and columns of Matrix: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter Matrix:\n");
                inputMatrix(A, r1, c1);

                transposeMatrix(A, result, r1, c1);

                printf("\nTranspose of Matrix:\n");
                displayMatrix(result, c1, r1);

                break;

            default:
                printf("Invalid choice! Please choose between 1–4.\n");
        }
    }

    return 0;
}

void inputMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[10][10], int B[10][10], int result[10][10], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrix(int A[10][10], int B[10][10], int result[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
}

void transposeMatrix(int A[10][10], int result[10][10], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            result[j][i] = A[i][j];
}
