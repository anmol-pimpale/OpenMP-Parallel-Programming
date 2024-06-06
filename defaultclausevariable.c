#include<stdio.h>
#include<omp.h>
int main(){

	int x=10;
	int y=20;
	
#pragma omp parallel default(none) shared(y) private(x)
	{       
		int z=omp_get_thread_num();
	
		x=omp_get_thread_num();
		printf("thread %d x=%d,y=%d,z=%d \n",omp_get_thread_num(),x,y,z);
	}
	return 0;
}
