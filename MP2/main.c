#include <stdio.h>
#include <time.h>

extern void acceleration(double* input, int* output, int rows);

int main() {
    int rows;
    printf("Enter number of rows: ");
    if (scanf_s("%d", &rows) != 1 || rows <= 0 || rows > 10000) {
        printf("Invalid row count.\n");
        return 1;
    }

    double input[10000][3];  // Maximum of 10000 rows
    int output[10000];

    printf("Enter Vi, Vf, and T for each row (e.g. 0.0, 62.5, 10.1):\n");

    for (int i = 0; i < rows; i++) {
        if (scanf_s("%lf, %lf, %lf", &input[i][0], &input[i][1], &input[i][2]) != 3) {
            printf("Invalid input at row %d.\n", i + 1);
            return 1;
        }
    }

    long start = clock();
    acceleration(&input[0][0], output, rows);

    printf("\nResults:\n\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %d m/s^2\n", i + 1, output[i]);
    }
    long end = clock();
    double elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1e3;

    printf("Time Elapsed: %.2lf milliseconds\n", elapsed);

    return 0;
}