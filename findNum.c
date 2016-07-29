#include "myInclude.h"

int k;

//binary search
int method1(int *data,int left,int right)
{
	int center;

	if(left == right)
		return data[left] == k ? left:-1;

	center = (left + right) /2;
	if(k == data[center])
		return center;
	else if(k > data[center])
		return method1(data,center+1,right);
	else
		return method1(data,left,center-1);
	
}

//line search
int method2(int *data, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(data[i] == k)
			return i;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int *data=NULL,i,n,flen;
	clock_t start,finish;
	double duration;
	char data_path[50]={0};
	FILE *fp=NULL;

	if(argc != 2)
	{
		printf("usage: find_num x\n");
		return -1;
	}

	k = atoi(argv[1]);

	sprintf(data_path,"%s%s",DATA_DIR,RANGED_INTEGER_DATA);
	fp = fopen(data_path,"r");
	if(fp == NULL)
	{
		printf("fopen failed\n");
		return -1;
	}

	fseek(fp,0,SEEK_END);
	flen = ftell(fp);
	rewind(fp);
	data = (int *)malloc(flen);
	n = flen/4;

	for(i=0;i<n;i++)
	{
		fread(data+i,sizeof(int),1,fp);
		//printf("%d ",data[i]);
	}

	start = clock();
	i = method1(data,0,n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	if(i != -1)
		printf("find %d at index: %d\n",k,i);
	else
		printf("can`t find k\n");
	printf("binary search\nstart: %lu\tfinish %li\tduration: %f\n",start,finish,duration);

	start = clock();
	i = method2(data,n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	if(i != -1)
		printf("find %d at index: %d\n",k,i);
	else
		printf("can`t find k\n");
	printf("line search\nstart: %lu\tfinish %li\tduration: %f\n",start,finish,duration);

	fclose(fp);
}
