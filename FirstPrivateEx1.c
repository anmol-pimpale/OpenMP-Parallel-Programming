#include<stdio.h>
#include<omp.h>
int main(){
	int shared_var = 5;
#pragma omp parallel firstprivate(shared_var)
	{
		shared_var += omp_get_thread_num();
		printf("thread %d shared_var =%d\n",omp_get_thread_num(),shared_var);
	}
	printf("outside parallel region shared_var = %d\n",shared_var);

	return 0;
}
