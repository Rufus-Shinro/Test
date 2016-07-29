#include "myInclude.h"

int comp(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

/*
	generate numbers interactive
*/
int main(int argc, char* argv[])
{
	int i, n = 0,upper = 0, *data = NULL;
	char natural[10]={0}, ranged[10]={0}, data_path[50]={0};
	bool nat = FALSE, ran = FALSE;
	FILE *fp = NULL;

	printf("Please input how many numbers you want to generate:");
	scanf("%d",&n);
	
	printf("Please input upper limit:");
	scanf("%d",&upper);

	//setbuf(stdin,NULL);
	rewind(stdin);
	printf("Do you need natural:");
	scanf("%s",natural);
	if(!memcmp(natural,"1",1) || !memcmp(natural,"y",1) || !memcmp(natural,"Y",1))
	{
		sprintf(natural,"%s","natural");
		nat = TRUE;
	}
	else
	{
		sprintf(natural,"%s","integer");
		nat = FALSE;
	}

	rewind(stdin);
	printf("Do you need the data ranged:");
	scanf("%s",ranged);
	if(!memcmp(ranged,"1",1) || !memcmp(ranged,"y",1) || !memcmp(ranged,"Y",1))
	{
		sprintf(ranged,"%s","ranged");
		ran = TRUE;
	}
	else
	{
		sprintf(ranged,"%s","unranged");
		ran = FALSE;
	}

	data = (int*)malloc(n*sizeof(int));
	srand((unsigned)time(NULL));

	sprintf(data_path,"%s%s%s%s%s",DATA_DIR,ranged,"_",natural,".data");
	printf("generating %d %s %s numbers to %s\n",n,ranged,natural,data_path);
	if(nat)
	{
		for(i=0;i<n;i++)
		{
			data[i] = rand()%(2*upper) - upper;
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			data[i] = rand()%upper;
		}
	}

	if(ran)
		qsort(data,n,sizeof(int),comp);

	if(access(DATA_DIR,F_OK) != 0)
	{
		printf("access: ./data not exist\n");
		if( 0 != mkdir("data",0777))
		{
			printf("mkdir data failed\n");
			return -1;
		}
		printf("maked dir:%s\n",DATA_DIR);
	}
	if((fp = fopen(data_path,"w"))==NULL)
	{
		printf("fopen %s failed\n",data_path);
		return -1;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",data[i]);
		fwrite(&data[i],sizeof(int),1,fp);
	}
	fclose(fp);
}
