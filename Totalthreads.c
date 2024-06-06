#include<omp.h>
#include<stdio.h>
int main()
{
        int tid;
        omp_set_num_threads(8);

        #pragma omp parallel

        {
                tid=omp_get_thread_num();

                printf("hello world from %d of  %d\n",tid,omp_get_num_threads());
        }
        return 0;
}

