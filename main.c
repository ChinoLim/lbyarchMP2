#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void compute_accelerations(double* input, int* output, int rows);

void generate_test_data(double* data, int rows) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < rows; ++i) {
        double Vi = (double)(rand() % 121); // 0 - 120 km/h
        double Vf = Vi + (double)(rand() % 81); // Vf >= Vi
        double T = 3.0 + (double)(rand() % 1801) / 100.0; // 3.0 to 21.0 sec
        data[i * 3 + 0] = Vi;
        data[i * 3 + 1] = Vf;
        data[i * 3 + 2] = T;
    }
}

int main() {
    int sizes[] = {10, 100, 1000, 10000};
    for (int s = 0; s < 4; ++s) {
        int rows = sizes[s];
        double* matrix = (double*) aligned_alloc(16, sizeof(double) * rows * 3);
        int* results = (int*) malloc(sizeof(int) * rows);

        generate_test_data(matrix, rows);

        double total_time = 0.0;
        for (int i = 0; i < 30; ++i) {
            struct timespec start, end;
            clock_gettime(CLOCK_MONOTONIC, &start);
            
            compute_accelerations(matrix, results, rows);
            
            clock_gettime(CLOCK_MONOTONIC, &end);
            double elapsed = (end.tv_sec - start.tv_sec) +
                             (end.tv_nsec - start.tv_nsec) / 1e9;
            total_time += elapsed;
        }

        printf("Size %d - Average time over 30 runs: %.6f seconds\n", rows, total_time / 30);

        // Output correctness check (first 5)
        printf("Sample output for size %d:\n", rows);
        for (int i = 0; i < (rows > 5 ? 5 : rows); ++i)
            printf("%d\n", results[i]);

        free(matrix);
        free(results);
    }
    return 0;
}
