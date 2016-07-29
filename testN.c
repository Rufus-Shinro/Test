#include "myInclude.h"

int testN(n)
{
	int i,sum = 0;
	for(i=0;i<n;i++)
		sum++;
	return sum;
}

int testNN(n)
{
	int i,j,sum = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sum++;
	return sum;
}

int testNNN(n)
{
	int i,j,sum = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n*n;j++)
			sum++;
	return sum;
}

int testNNm2(n)
{
	int i,j,sum = 0;
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			sum++;
	return sum;
}

int testNNNm2(n)
{
	int i,j,k,sum = 0;
	for(i=0;i<n;i++)
		for(j=0;j<i*i;j++)
			for(k=0;k<j;k++)
				sum++;
	return sum;
}

int testNNNmn(n)
{
	int i,j,k,sum = 0;
	for(i=1;i<n;i++)
		for(j=1;j<i*i;j++)
			if(j%i == 0)
				for(k=0;k<j;k++)
					sum++;
	return sum;
}

int main(int argc, char *argv[])
{
	int n,result;
	clock_t start,finish;
	double duration;

	if(argc != 2)
	{
		printf("usage: ./a.out n");
		return -1;
	}
	
	n = atoi(argv[1]);

	start = clock();
	result = testN(n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("testN: %d\n\tstart : %lu\t finish : %lu\t duration : %f\n",result,start,finish,duration);

	start = clock();
	result = testNN(n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("testNN: %d\n\tstart : %lu\t finish : %lu\t duration : %f\n",result,start,finish,duration);

	start = clock();
	result = testNNN(n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("testNNN: %d\n\tstart : %lu\t finish : %lu\t duration : %f\n",result,start,finish,duration);

	start = clock();
	result = testNNm2(n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("testNNm2: %d\n\tstart : %lu\t finish : %lu\t duration : %f\n",result,start,finish,duration);

	start = clock();
	result = testNNNm2(n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("testNNNm2: %d\n\tstart : %lu\t finish : %lu\t duration : %f\n",result,start,finish,duration);

	start = clock();
	result = testNNNmn(n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("testNNNmn: %d\n\tstart : %lu\t finish : %lu\t duration : %f\n",result,start,finish,duration);
	
	return 0;
}
