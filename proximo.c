#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int distancia (int*a, int n, int x)
{
	int result = 0;
	int d = 0;
	int l = 0;
	while (result < n )
	{
		l = l + a[result];
		if (l >= x)
			result = n;
		else
			d++;
	result++;
    }
    return d;
}

int proximo (int*a, int n , int x, int* b)
{
	int i = 0;
	int m = 0;
	while (i < n)
	{
		b[m++] = i;
		int k = distancia(a + i, n - i, x);
		i = i + k + 1; 
	}
	b[m] = n ;
	return m+1;
}


void test_proximo (void)
{
	int x;
	int a[1000];
	scanf("%d" , &x);
	int n = ints_get(a);
	int b[1000];
	int m = proximo(a,n,x,b);
	ints_println_special(b,m);
}

int main()
{
	test_proximo();
	return 0;
}