#include "myInclude.h"

bool isEven(int x)
{
	return !(x % 2);
}

long myPow(int base, int power)
{
	if(power == 0)
		return 1;
	else if(isEven(power))
		return myPow(base * base, power / 2);
	else
		return myPow(base * base, power / 2) * base;
}

int main(int argc, char *argv[])
{
	int m,n;
	long result;

	if(argc != 3)
	{
		printf("usage: ./a.out m n (m^n)");
		return -1;
	}

	m = atoi(argv[1]);
	n = atoi(argv[2]);

	result = myPow(m,n);
	printf("%d^%d = %ld\n",m,n,result);

	return 0;
}
