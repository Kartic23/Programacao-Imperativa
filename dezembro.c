#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"


double dezembro (const double*a, int n)
{
	int i = 0;
	int dias = 0;
	while (i < 31 )
	{
		if (a[i] <= 0)
		{
			dias++;
		}
		i++;
	}
	return dias;
}


double doubles_dezembro (const double*a, int n, int*b)
{
	int i = 0;
	int dias = 0;
	int anos = (n/31);
	int result = 0;
	while (i < n)
	{
		dias = dezembro (a + i , n - i);
		if (dias >= 3)
		{
			b[result] = anos;
			result++;
		}
		i = i + 31;
		anos--;
	}
	return result;
}

void test_doubles_dezembro (void)
{
	double a[1000];
	int b [1000];
	int n = doubles_get (a);
	int m = doubles_dezembro (a,n,b);
	if (m == 0)
	{
		printf("%d\n", m);
	}
	else
	{
		printf("%d %d\n", m , b[m-1]);
	}
}


int main (void)
{
	test_doubles_dezembro();
	return 0;
}