#include<omp.h>
#include<stdio.h>
#define N 10
int main(){
    omp_set_num_threads(5);
    int suma = 1;
    int sumb = 1;
    int i = 1;
    #pragma omp parallel firstprivate(i)
    {
        #pragma omp sections reduction(+: suma)
        {
            #pragma omp section
            {
                for(i=1 ; i <= N; i++){
                    suma+= i;
            }
            printf("Sum by section 1 = %d\n", suma);
            }
            #pragma omp section
            {
                for( i=1; i <= N; i++){
                    sumb*= i;
                }
            printf("Sum by section 2 = %d\n", sumb);
            }
        }
    }
}
