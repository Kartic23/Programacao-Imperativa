#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int ints_anos_seguidos (const int*a ,int n)
{
	int result = 0;
	while (result < n - 1  && a[result] > a[result+1] )
	{
		result++;
	}
	return result+1;
}

int ints_recessao (const int*a , int n, int*indices, int*anos_seguidos)
{
	int i = 0;
	int m = 0;
	int anos = 0;
	while ( i < n )	
	{
		anos = ints_anos_seguidos (a+i,n-i);
		if (anos  >= 3)
		{
			indices[m] = i;
			anos_seguidos[m++]= anos;
		}
		i = i + anos;
	}
	return m;
}

void test_recessao (void)
{
	int a[1000];
	int indices[1000];
	int anos_seguidos[1000];
	int n = ints_get (a);
	int m = ints_recessao (a,n,indices,anos_seguidos);
	printf("%d\n", m );
	ints_print_two (indices,anos_seguidos,m);
}

int main (void)
{
	test_recessao ();
	return 0;
}