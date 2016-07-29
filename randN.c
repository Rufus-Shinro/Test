#include "myInclude.h"

bool isElementExist(int *data,int index,int value)
{
	int i;

	for(i=0;i<index;i++)
	{
		if(value == data[i])
			return TRUE;
	}
	return FALSE;
}

void method1(int *data, int n)
{
	int i,temp;

	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		temp = rand()%n;
		while(isElementExist(data,i,temp))
			temp = rand()%n;
		data[i] = temp;
	}
	return ;
}

bool isLocationSet(char *data_flag, int index)
{
	if(data_flag[index] == 0)
	{
		data_flag[index] = 1;
		return FALSE;
	}
	return TRUE;
}

void method2(int *data, char *data_flag, int n)
{
	int i,temp;

//	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		temp = rand()%n;
		while(isLocationSet(data_flag,temp))
			temp = rand()%n;
		data[i] = temp;
	}
	return ;
}

void swap(int *x,int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void method3(int *data, int n)
{
	int i,temp;

//	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
		data[i] = i;
	for(i=0;i<n;i++)
	{
		temp = rand()%n;
		swap(&data[i],&data[temp]);
	}
	return ;
}

int main(int argc, char *argv[])
{
	int i,n,*data = NULL;
	char *data_flag = NULL;
	clock_t start,finish;
	double duration;

	if(argc != 2)
	{
		printf("usage; ./a.out n\n");
		return -1;
	}

	n = atoi(argv[1]);
	data = (int *)malloc(n*sizeof(int));
	data_flag = (char *)malloc(n);
	memset(data_flag,0,n);

	start = clock();
	method1(data,n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("method1:\n\tstart: %lu\tfinish: %lu\t duration: %f\n",start,finish,duration);
	for(i=0;i<n;i++)
		printf("%d ",data[i]);
	printf("\n");

	start = clock();
	method2(data,data_flag,n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("method2:\n\tstart: %lu\tfinish: %lu\t duration: %f\n",start,finish,duration);
	for(i=0;i<n;i++)
		printf("%d ",data[i]);
	printf("\n");

	start = clock();
	method3(data,n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("method3:\n\tstart: %lu\tfinish: %lu\t duration: %f\n",start,finish,duration);
	for(i=0;i<n;i++)
		printf("%d ",data[i]);
	printf("\n");

	free(data);
	free(data_flag);
	return 0;
}
