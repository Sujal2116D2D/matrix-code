#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    int *arr1D1 = NULL, *arr1D2 = NULL;
    int **arr2D1 = NULL, **arr2D2 = NULL, **resultMatrix = NULL;
    int size1D = 0, num_elements1D = 0;
    int rows = 0, cols = 0;
    int arraysReady = 0;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Input 1-D arrays\n");
        printf("2. Input 2-D arrays\n");
        printf("3. Perform array operations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter size of 1-D arrays: ");
                scanf("%d", &size1D);
                printf("Enter number of elements to input: ");
                scanf("%d", &num_elements1D);

                if (num_elements1D > size1D || num_elements1D <= 0) {
                    printf("Invalid number of elements.\n");
                    break;
                }

                arr1D1 = (int*)malloc(size1D * sizeof(int));
                arr1D2 = (int*)malloc(size1D * sizeof(int));
                if (!arr1D1 || !arr1D2) {
                    printf("Memory allocation failed.\n");
                    break;
                }
 printf("\nNow input the first 1-D array:\n");
                for (int i = 0; i < num_elements1D; i++) {
                    printf("arr1D1[%d] = ", i);
                    scanf("%d", &arr1D1[i]);
                }
                printf("\nNow input the second 1-D array:\n");
                for (int i = 0; i < num_elements1D; i++) {
                    printf("arr1D2[%d] = ", i);
                    scanf("%d", &arr1D2[i]);
                }

                arraysReady = 1;
                break;
            }

            case 2: {
                printf("Enter number of rows and columns for 2-D arrays: ");
                scanf("%d %d", &rows, &cols);

                arr2D1 = (int**)malloc(rows * sizeof(int*));
                arr2D2 = (int**)malloc(rows * sizeof(int*));
                resultMatrix = (int**)malloc(rows * sizeof(int*));
                for (int i = 0; i < rows; i++) {
                    arr2D1[i] = (int*)malloc(cols * sizeof(int));
                    arr2D2[i] = (int*)malloc(cols * sizeof(int));
                    resultMatrix[i] = (int*)calloc(cols, sizeof(int));
                }
 printf("\nNow input the first 2-D array:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("arr2D1[%d][%d] = ", i, j);
                        scanf("%d", &arr2D1[i][j]);
                    }
                }
                printf("\nNow input the second 2-D array:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("arr2D2[%d][%d] = ", i, j);
                        scanf("%d", &arr2D2[i][j]);
                    }
                }

                arraysReady = 1;
                break;
            }

            case 3: {
                if (!arraysReady) {
                    printf("Please input arrays first.\n");
                    break;
                }

                int op;
                printf("\nOperations Menu:\n");
                printf("1. Add 1-D arrays\n");
                printf("2. Subtract 1-D arrays\n");
                printf("3. Multiply 1-D arrays (element-wise)\n");
                printf("4. Add 2-D arrays\n");
                printf("5. Subtract 2-D arrays\n");
                printf("6. Multiply 2-D arrays (element-wise)\n");
                printf("7. Matrix multiplication (2-D)\n");
                printf("Enter your operation choice: ");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        for (int i = 0; i < num_elements1D; i++)
                            printf("Result[%d] = %d\n", i, arr1D1[i] + arr1D2[i]);
                        break;
                    case 2:
                        for (int i = 0; i < num_elements1D; i++)
                            printf("Result[%d] = %d\n", i, arr1D1[i] - arr1D2[i]);
                        break;
                    case 3:
                        for (int i = 0; i < num_elements1D; i++)
                            printf("Result[%d] = %d\n", i, arr1D1[i] * arr1D2[i]);
                        break;
                    case 4:
                        for (int i = 0; i < rows; i++)
                            for (int j = 0; j < cols; j++)
                                printf("Result[%d][%d] = %d\n", i, j, arr2D1[i][j] + arr2D2[i][j]);
                        break;
                    case 5:
                        for (int i = 0; i < rows; i++)
                            for (int j = 0; j < cols; j++)
                                printf("Result[%d][%d] = %d\n", i, j, arr2D1[i][j] - arr2D2[i][j]);
                        break;
                    case 6:
                        for (int i = 0; i < rows; i++)
                            for (int j = 0; j < cols; j++)
                                printf("Result[%d][%d] = %d\n", i, j, arr2D1[i][j] * arr2D2[i][j]);
                        break;
                    case 7:
                        for (int i = 0; i < rows; i++) {
                            for (int j = 0; j < cols; j++) {
                                resultMatrix[i][j] = 0;
                                for (int k = 0; k < cols; k++)
                                    resultMatrix[i][j] += arr2D1[i][k] * arr2D2[k][j];
                                printf("Result[%d][%d] = %d\n", i, j, resultMatrix[i][j]);
                            }
                        }
                        break;
                    default:
                        printf("Invalid operation choice.\n");
                }
                break;
            }

            case 4:
                printf("Exiting program. 👋\n");

                free(arr1D1);
                free(arr1D2);

                for (int i = 0; i < rows; i++) {
                    free(arr2D1[i]);
                    free(arr2D2[i]);
                    free(resultMatrix[i]);
                }
                free(arr2D1);
                free(arr2D2);
                free(resultMatrix);

                exit(0);

            default:
                printf("Invalid main menu choice.\n");
        }
    }

    return 0;
}