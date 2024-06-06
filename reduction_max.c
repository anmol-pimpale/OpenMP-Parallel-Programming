#include<stdio.h>
#include<omp.h>

int main(){
        int array[]={44,55,66,23,45,67,89,89,200,500};
        int max = array[0];
#pragma omp parallel for reduction(max:max) num_threads(4)
        for(int i=0;i<10;i++){
                int thread_id = omp_get_thread_num();
                if (array[i] > max) {
                    max = array[i];
                }
                printf("Thread : %d, Iteration: %d, Maximum Value: %d\n", thread_id, i, max);
        }
        printf("Maximum Value: %d\n",max);
        return 0;
}
