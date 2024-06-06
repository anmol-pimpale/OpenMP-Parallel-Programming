#include<omp.h>
#include<stdio.h>
int main()
{
        int x=0;
        omp_set_num_threads(300);
#pragma omp parallel
  {
        #pragma omp critical
	{	
            x=x+1;
	}
  }	   
	printf("x= %d\n",x);

return 0;   
}

