#include <stdio.h>
#include <math.h>

int main() {
    int rows;
    printf("Enter number of rows: ");
    if (scanf_s("%d", &rows) != 1 || rows <= 0 || rows > 100) {
        printf("Invalid input.\n");
        return 1;
    }

    double input[100][3];

    for (int i = 0; i < rows; i++) {
        printf("Enter Vi, Vf, T for row %d (comma-separated): ", i + 1);
        if (scanf_s("%lf, %lf, %lf", &input[i][0], &input[i][1], &input[i][2]) != 3) {
            printf("Invalid input format.\n");
            return 1;
        }
    }

    printf("\nOutput (Acceleration in m/s^2, rounded to int):\n");
    for (int i = 0; i < rows; i++) {
        double Vi = input[i][0] * 1000.0 / 3600.0;
        double Vf = input[i][1] * 1000.0 / 3600.0;
        double T = input[i][2];

        double acceleration = (Vf - Vi) / T;
        int rounded = (int)round(acceleration);

        printf("%d\n", rounded);
    }

    return 0;
}
