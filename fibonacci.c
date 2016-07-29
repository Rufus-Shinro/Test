#include "myInclude.h"

int gn = 0;

int fib(int n)
{
	static int order = 1;
	int temp;
	if(n == 0 || n == 1)
		return 1;
	temp = fib(n-1) + fib(n-2);
	return temp;
}

int fib_fn(int n)
{
	int i,temp,x=1,y=1;
	for(i=2;i<=n;i++)
	{
		temp = y;
		y = y+x; 
		x = temp;	
	}
	return y;
}

int main(int argc, char *argv[])
{
	int opt,result = 0;
	clock_t start,finish;
	double duration = 0;

	if (argc != 3)
	{
		printf("./a.out method(1 for recursion; 2 for function) count\n");
		return -1;
	}
	opt = atoi(argv[1]);
	gn = atoi(argv[2]);

	if(opt == 1)
	{
		printf("recrusive:\n");
		start = clock();
		result = fib(gn);
		finish = clock();
		duration = (double)(finish - start)/CLOCKS_PER_SEC;
		printf("result:%d time = %f\n",result,duration);
	}
	else
	{
		printf("function:\n");
		start = clock();
		result = fib_fn(gn);
		finish = clock();
		duration = (double)(finish - start)/CLOCKS_PER_SEC;
		printf("result:%d time = %f\n",result,duration);
	}
	return 0;
}
