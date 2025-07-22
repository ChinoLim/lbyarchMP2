#include <stdio.h>

extern void acceleration(double* input, int* output, int rows);

int main() {
    int rows;
    printf("Enter number of rows: ");
    if (scanf_s("%d", &rows) != 1 || rows <= 0 || rows > 100) {
        printf("Invalid row count.\n");
        return 1;
    }

    double input[100][3];  // Maximum of 100 rows
    int output[100];

    printf("Enter Vi, Vf, and T for each row (e.g. 0.0, 62.5, 10.1):\n");

    for (int i = 0; i < rows; i++) {
        if (scanf_s("%lf, %lf, %lf", &input[i][0], &input[i][1], &input[i][2]) != 3) {
            printf("Invalid input at row %d.\n", i + 1);
            return 1;
        }
    }

    acceleration(&input[0][0], output, rows);

    printf("\nResults:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %d m/s^2\n", i + 1, output[i]);
    }

    return 0;
}