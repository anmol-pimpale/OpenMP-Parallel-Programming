#include<stdio.h>
#include<omp.h>
int main()
{
	
 if(omp_in_parallel())
	{
		printf("main thread is in a parallel region.\n");
	}
  else
  {
	  printf("main thread is not in parallel region\n");
  }
#pragma omp parallel

  if(omp_in_parallel())
  {
	  printf("thread %d is in parallel region\n",omp_get_thread_num());
  }
  else
  
  {
	  printf("thraed %d is in not in parallel region\n",omp_get_thread_num());
  }
	return 0;
}
