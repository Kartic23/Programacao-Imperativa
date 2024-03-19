#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int ints_comprimento_total (const int* d , int k)
{
	return k == 0 ? 0 : d[0] + ints_comprimento_total(d+1, k-1);
}

int ints_comprimento (const int*a ,int n)
{
	int comprimento = 0;
	while  ( comprimento < n-1 && a[comprimento+1] > a[comprimento])
	{
		comprimento++;
	}
	return comprimento;
}

int ints_rampa (const int*a, int n, int x ,int *d)
{
	int i = 0;
	int k = 0;
	int comprimento = 0;
	while (i < n )
	{
		comprimento = ints_comprimento (a + i ,n - i);
		if (comprimento >= x)
		{
			d[k++] = comprimento;
		}
		i = i + comprimento + 1;
	}
	return k;
}

void test_ints_rampa (void)
{
	int x;
	scanf ("%d", &x);
	int a[1000];
	int d[1000];
	int n = ints_get (a);
	int k = ints_rampa (a,n,x,d);
	int total = ints_comprimento_total (d,k);
	printf("%d %d\n", k , total);
}

int main (void)
{
	test_ints_rampa();
	return 0;
}