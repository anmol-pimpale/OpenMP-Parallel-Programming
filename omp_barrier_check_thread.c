#include<stdio.h>
#include<omp.h>
#define N 100
int main(){
	int a[N];
	int sum= 0;
#pragma omp parallel num_threads(N)
	{
		int i= omp_get_thread_num();
		a[i]=i+1;
                #pragma omp barrier
                if(omp_get_thread_num() ==0)
		{     
			printf("thread id:%d\n",omp_get_thread_num());
			for(int j=0;j<N;j++){
				sum += a[j];
			}
		}
	}
	printf("sum =%d\n",sum);
	return 0;
}
