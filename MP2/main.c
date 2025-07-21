#include <stdio.h>

extern int acceleration(double Vi, double Vf, double T);

int main() {
    int rows;
    printf("Enter number of rows: ");
    if (scanf_s("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid row count.\n");
        return 1;
    }

    double input[100][3];  // Supports up to 100 rows
    printf("Enter Vi, Vf, and T for each row (e.g. 0.0, 62.5, 10.1):\n");

    for (int i = 0; i < rows; i++) {
        if (scanf_s("%lf, %lf, %lf", &input[i][0], &input[i][1], &input[i][2]) != 3) {
            printf("Invalid input at row %d.\n", i + 1);
            return 1;
        }
    }

    printf("\nResults:\n");
    for (int i = 0; i < rows; i++) {
        int result = acceleration(input[i][0], input[i][1], input[i][2]);
        printf("Row %d: %d m/s^2\n", i + 1, result);
    }

    return 0;
}
