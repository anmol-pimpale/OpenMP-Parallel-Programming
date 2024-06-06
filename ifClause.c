#include<stdio.h>
#include<omp.h>
int main()
{
	
#pragma omp parallel if(omp_in_parallel())
	{
		printf("The thread %d is executing inside parallel region\n",omp_get_thread_num());
	}
	return 0;
}
