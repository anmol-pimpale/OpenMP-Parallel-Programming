#include<stdio.h>
#include<omp.h>
int main(){

	int x=10; //shared variable

	int y=20; //shared variable
	
#pragma omp parallel default(shared) private(x,y)
	{       
	/*	int z=omp_get_thread_num();*/ // this is also private 
	        printf("initial value of x =%d,y=%d \n",x,y);
		x=omp_get_thread_num();//private copy of x for each thread
		y += x;//private copy of y for each thread,each threads increament its private copy
		printf("thread %d x=%d,y=%d\n",omp_get_thread_num(),x,y);
	}
	printf("outside parallel region value of x=%d,y=%d\n",x,y);
	return 0;
}
