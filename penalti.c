#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int lado (int a, int b)
{
	return( a * b >= 0 ? 1 : 0 );
	//Se for para a direita ou para o meio, fica 1, mas se for para a esquerda fica 0//
}

int ints_lado (const int*a , int n)
{
	int result = 0;
	while (result < n-1 && lado (a[0] , a[result+1])) 
	{
        result++;
	}
    return result+1;
}


int ints_penalti (const int*a, int n, int *b)
{
	int i = 0;
	int m = 0;
	int result = 0;
	int k = 0;
	while ( i < n && k < n)
	{
		result = ints_lado(a + k , n - k);
		b[m++] = result;
		k = k + result;
		i++;
	}
	return m;
}

void test_ints_penalti (void)
{
	int a[1000];
	int b[1000];
	int n = ints_get (a);
	int m = ints_penalti (a,n,b);
	ints_println_basic (b,m);
}


int main (void)
{
	test_ints_penalti();
	return 0;
}