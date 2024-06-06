#include<stdio.h>
#include<omp.h>
int main(){

	int x= 2;
       #pragma omp parallel private(x)
          {
		printf("value of x inside parallel rgeion =%d \n",x);
		x=omp_get_thread_num();
	        printf("Thread %d has private x=%d at address %p\n", omp_get_thread_num(), x,&x);
			
       	}
	  printf("value of x outside parallel region =%d\n",x);
	return 0;
}
