#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 1000000

int main() {
    int i, array[ARRAY_SIZE];
    long long sum = 0;

    // Initialize the array with random values
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10;
    }

    // Calculate the sum of the array in parallel
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }

    printf("Sum of the array: %lld\n", sum);

    return 0;
}
