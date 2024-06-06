#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 100
#define NUM_THREADS 4

int main() {
    int array[ARRAY_SIZE];
    int sum = 0;

   
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

   
    #pragma omp parallel num_threads(NUM_THREADS) reduction(+:sum)
    {
        int thread_id = omp_get_thread_num();
        int chunk_size = ARRAY_SIZE / NUM_THREADS;
        int start_index = thread_id * chunk_size;
        int end_index = start_index + chunk_size;

        
        if (thread_id == NUM_THREADS - 1) {
            end_index = ARRAY_SIZE;
        }

       
        for (int i = start_index; i < end_index; i++) {
            sum += array[i];
        }
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}

