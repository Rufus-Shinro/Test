#include "myInclude.h"

int n = 1000, k = 500;

void swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

int method1(int *data)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=i;j>0;j--)
			if(data[j]>data[j-1])
				swap(&data[j-1],&data[j]);
	}
	return data[k-1];
}

int method2(int *data)
{
	int i,j;
	
	for(i=0;i<k;i++)
	{
		for(j=i;j>0;j--)
			if(data[j]>data[j-1])
				swap(&data[j-1],&data[j]);
	}
	for(i=k;i<n;i++)
	{
		memcpy(&data[k],&data[i],sizeof(int));
		for(j=k;j>0;j--)
			if(data[j]>data[j-1])
				swap(&data[j],&data[j-1]);
	}
	return data[k-1];
}

int main(int argc, char *argv[])
{
	int i,result,fd=0,*data=NULL,*data_tmp=NULL;
	double duration = 0;
	FILE *fp = NULL;
	time_t start,finish;

	if(argc > 3)
	{
		printf("invalid parameters\n");
		return -1;
	}

	if(argc == 3)
	{
		n = atoi(argv[1]);
		k = atoi(argv[2]);
	}

	data = (int*)malloc(n*sizeof(int));
	data_tmp = (int*)malloc(n*sizeof(int));

	if((fp=fopen("num.data","r")) == NULL)
	{
		printf("fopen failed\n");
		free(data);
		return -1;
	}

	for(i=0;i<n;i++)
		fread(data+i,sizeof(int),1,fp);
//	for(i=0;i<n;i++)
//		printf("%d ",data[i]);

	fclose(fp);

	memcpy(data_tmp,data,n*sizeof(int));

	//pop range
	start = clock();
	result = method1(data_tmp);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("start : %ld\tfinish: %ld\t duration:%f\n",start,finish,duration);
	printf("\tresult: %d\n",result);

	memcpy(data_tmp,data,n*sizeof(int));
	start = clock();
	result = method2(data_tmp);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("start : %ld\tfinish: %ld\t duration:%f\n",start,finish,duration);
	printf("\tresult: %d\n",result);
}
