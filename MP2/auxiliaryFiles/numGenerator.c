#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10000
#define MIN_ROWS 1
#define OUTPUT_FILE "data.txt"

// Generate a random double between min and max
double random_double(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int main() {
    int rows;
    srand((unsigned int)time(NULL));
    // User input for number of rows
    printf("Enter number of rows to generate (1 to 10000): ");
    if (scanf("%d", &rows) != 1 || rows < MIN_ROWS || rows > MAX_ROWS) {
        printf("Invalid input. Please enter a number between 1 and 10000.\n");
        return 1;
    }

    FILE* file = fopen(OUTPUT_FILE, "w");
    if (!file) {
        perror("Failed to open output file");
        return 1;
    }
    fprintf(file, "%d", rows);

    // Generate random numbers
    for (int i = 0; i < rows; i++) {
        double v_initial = random_double(0.0, 499.9999); //From 0 to <500
        double v_final = random_double(v_initial, 500.0); //From v_initial to 500 --- always positively accelerating
        double time = random_double(0.0001, 60); //>0 to 60
        
        fprintf(file, "\n%.2f, %.2f, %.2f", v_initial, v_final, time);

    }
    fclose(file);
    printf("Numbers generated in '%s'\n", OUTPUT_FILE);
    return 0;
}