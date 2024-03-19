#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_take (const int*a , int n, int x , int *d)
{
	int b = 0;
	if(x < 0)
		b = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < x)
			d[b++] = a[i];
	}
	ints_println_special(d,b);
	return 0;;
}

void test_ints_take (void)
{
	int a[1000];
	int terminator = -1;
	int n = ints_get_until(terminator,a);
	int x;
	int d[1000];
	while (scanf ("%d" , &x) != EOF)
	ints_take(a,n,x,d);
}

int main(void)
{
	test_ints_take();
	return 0;
}