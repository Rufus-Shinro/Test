#include "myInclude.h"

int bi,ei,max = 0;

void method1(int *data, int n)
{
	int i,j,temp;
	
	for(i=0;i<n;i++)
	{
		temp = 0;
		for(j=i;j<n;j++)
		{
			temp += data[j];
			if(temp > max)
			{
				max = temp;
				bi = i;
				ei = j;
			}
		}
	}
}

int max3(int x, int y, int z)
{
	return (x > y ? (x > z ? x:z):(y > z ? y:z));
}

int method2(int *data, int left, int right)
{
	int i,center,temp,maxLeftSum,maxRightSum,maxLeftBorderSum=0,maxRightBorderSum=0;

	if(left == right)
		return data[left] > 0 ? data[left]:0;
	
	center = (left + right)/2;	
	maxLeftSum = method2(data,left,center);
	maxRightSum = method2(data,center+1,right);

	temp = 0;
	for(i=center;i>left;i--)
	{
		temp += data[i];
		if(temp > maxLeftBorderSum)
			maxLeftBorderSum = temp;
	}
	temp = 0;
	for(i=center+1;i<right;i++)
	{
		temp += data[i];
		if(temp > maxRightBorderSum)
			maxRightBorderSum = temp;
	}

	return max3(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum);
}

void method3(int *data, int n)
{
	int i,temp=0;
	max = 0;
	for(i=0;i<n;i++)
	{
		temp += data[i];
		if(temp > max)
			max = temp;
		if(temp < 0)
			temp = 0;
	}
}

int main(int argc, char *argv[])
{
	int i, n, flen, *data = NULL;
	char data_path[50] = {0};
	FILE *fp = NULL;
	clock_t start,finish;
	double duration;

	sprintf(data_path,"%s%s",DATA_DIR,UNRANGED_NATURAL_DATA);
	
	fp = fopen(data_path,"r");
	if(fp == NULL)
	{
		printf("fopen failed\n");
		return -1;
	}
	fseek(fp,0,SEEK_END);
	flen = ftell(fp);
	n = flen / 4;
	printf("file len = %d\n",flen);
	data = (int *)malloc(flen);
	rewind(fp);
	for(i=0;i<n;i++)
	{
		if( fread(data+i,sizeof(int),1,fp) <= 0)
			break;
	//	printf("%d ",data[i]);
	}
	printf("\n");
	n = i;
	printf("total %d numbers\n",n);

	printf("Method1:\n");
	max = 0;
	start = clock();	
	method1(data,n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	//printf("Max subsequence:");
	//for(i=bi;i<=ei;i++)
	//	printf("%d ",data[i]);
	printf("\nSum:%d\n",max);
	printf("Time start: %lu\t finish: %lu\t duration: %f\n",start,finish,duration);

	printf("Method2:\n");
	start = clock();
	max = method2(data,0,n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("\nSum:%d\n",max);
	printf("Time start: %lu\t finish: %lu\t duration: %f\n",start,finish,duration);

	printf("Method3:\n");
	start = clock();
	method3(data,n);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("\nSum:%d\n",max);
	printf("Time start: %lu\t finish: %lu\t duration: %f\n",start,finish,duration);
	fclose(fp);	
}
