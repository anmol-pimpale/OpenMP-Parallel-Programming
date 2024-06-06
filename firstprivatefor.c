#include <stdio.h>
#include <omp.h>

int main() {
    int a = 10;

#pragma omp parallel for num_threads(4) firstprivate(a)
    int b=0;
    for (int i = 0; i < 10; i++) {
        printf("a value for thread %d is %d\n", omp_get_thread_num(), a);
        a++;
    }

    printf("a (outside parallel region) = %d\n", a);
    return 0;
}
