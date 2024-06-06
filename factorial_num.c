#include <stdio.h>
#include <omp.h>

long long int factorial(int n) {
    long long int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(int argc, char** argv) {
    int n = 20; 
    long long int partial_Sum, total_Sum = 0;

    #pragma omp parallel private(partial_Sum)
    {
        partial_Sum = 1;
        #pragma omp for
        for (int i = 1; i <= n; i++) {
            #pragma omp atomic
            partial_Sum *= i;
        }

        #pragma omp barrier

        #pragma omp critical
        {
            total_Sum += partial_Sum;
        }
    }

    printf("The factorial of %d is: %lld\n", n, total_Sum);

    return 0;
}
