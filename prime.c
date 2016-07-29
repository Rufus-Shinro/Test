#include "myInclude.h"

int main(int argc, char *argv[])
{
	int i,j,n;
	if(argc != 2)
	{
		printf("usage: ./a.out x\n");
		return -1;
	}

	n = atoi(argv[1]);
	for(i=0;i<n;i++)
	{
		for(j=i-1;j>0;j--)
		{
			if(gcd(i,j) != 1)
				break;
		}
		if(j == 0)
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}
