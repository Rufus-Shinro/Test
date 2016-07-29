#include "myInclude.h"
/*
  greatest common divisor
*/
int gcd(int m, int n) 
{
	int mod;
	
	while(m % n)
	{
		mod = m % n;
		m = n;
		n = mod;
	}
//	printf("gcd = %d\n",n);

	return n;
}
