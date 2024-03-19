#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_drop_1 (const int*a , int n)
{
	ints_println_special (a,n);
	return 0;
}

int ints_drop (const int*a , int n, int x , int *d)
{
	if(x < 0)
		ints_drop_1 (a,n);
	else
	{
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (i >= x)
			d[b++] = a[i];
	}
	ints_println_special(d,b); 
	}
	return 0;
}

void test_ints_drop (void)
{
	int a[1000];
	int terminator = -1;
	int n = ints_get_until(terminator,a);
	int x;
	int d[1000];
	while (scanf ("%d" , &x) != EOF)
	ints_drop (a,n,x,d);
}

int main(int argc, char **argv)
{
	test_ints_drop();
    return 0;
}