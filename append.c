#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_append_1 (const int *a, int n , const int *b, int m, int *c)
{
	int k = 0;
	for (int i = 0 ; i < m ; i++)
		c[k++] = b[i];
	for (int i = 0 ; i < m ; i++)
	    c[k++] = a[i];
	ints_println_special (c,k);
	return 0;
}

int ints_append (const int *a, int n,const int *b, int m,int *c) 
{
	int k = 0;
	for (int i = 0 ; i < n ; i++)
		c [k++] = a [i];
	for (int i = 0 ; i < n ; i++)
	    c [k++] = b [i];
	ints_println_special (c,k);
	ints_append_1 (a,n, b,m,c);
	return 0;
}

void test_ints_append (void)
{
	int a[1000];
	int b[1000];
	int c[1000];
	int n = ints_get_until (-1, a);
	int m = ints_get_until (-1, b);
	ints_append (a,n,b,m,c);
}

int main(void)
{
	test_ints_append();
	return 0;
}