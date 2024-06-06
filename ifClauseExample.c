#include<stdio.h>
#include<omp.h>
int main()
{
	int n =50;
#pragma omp parallel if(n>100)
	{
		printf("The thread %d is executing inside parallel region\n",omp_get_thread_num());
	}
	return 0;
}
