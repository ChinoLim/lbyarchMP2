#include <stdio.h>
#include <time.h>

int main(){
    int rows;
    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0 || rows > 10000) {
        printf("Invalid row count.\n");
        return 1;
    }

    double input[10000][3];  // Maximum of 10000 rows
    double output[10000];

    printf("Enter Vi, Vf, and T for each row (e.g. 0.0, 62.5, 10.1):\n");

    for (int i = 0; i < rows; i++) {
        if (scanf("%lf, %lf, %lf", &input[i][0], &input[i][1], &input[i][2]) != 3) {
            printf("Invalid input at row %d.\n", i + 1);
            return 1;
        }
    }
    
    long start = clock();
    for (int i = 0; i < rows; i++) {
        double vi = input[i][0];
        double vf = input[i][1];
        double t  = input[i][2];

        if (t == 0) {
            output[i] = 0;
        } else {
            double acceleration = ((vf - vi) * (5.0 / 18.0)) / t;
            output[i] = acceleration;
        }
    }

    printf("\nResults:\n\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %.4lf m/s^2\n", i + 1, output[i]);
    }
    long end = clock();
    double elapsed = ((double)(end - start)/CLOCKS_PER_SEC) * 1e3;

    printf("Time Elapsed: %.2lf milliseconds\n", elapsed);

    return 0;
}