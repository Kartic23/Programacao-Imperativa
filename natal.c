#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_vinho (const int*a , int n, int x)
{
	int c = 0;
	int d = 0;
	for (int i = 0 ; i < n ; i++ )
	{
		c = a[i]/x;
		d = d + c;
	}
	printf("%d\n", d);
	return 0;
}

void test_ints_vinho (void)
{
	int a[1000];
	int x;
	scanf("%d" , &x);
    int n = ints_get(a);
    ints_vinho (a,n,x);
}

int main (void)
{
	test_ints_vinho();
	return 0;
}