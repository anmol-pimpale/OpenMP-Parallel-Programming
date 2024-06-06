#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
    int n = 100; 
    int partial_Sum, total_Sum = 0;

    #pragma omp parallel private(partial_Sum)
    {
        partial_Sum = 0;
        #pragma omp for
        for(int i = 1; i <= n; i++){
            partial_Sum += i;
        }

        #pragma omp barrier

        #pragma omp critical
        {
            total_Sum += partial_Sum;
        }
    }

    printf("The sum of the first %d natural numbers is: %d\n", n, total_Sum);

    return 0;
}
