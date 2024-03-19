#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int count_while_descending (const int*a, int m)
{
	int result = 0;
	while ( result < n-1 && a[result] > a[result+1])
	{
		result++;
	}
	return result;
}

int count_while_ascending (const int*a, int m)
{
	int result = 0;
	while ( result < n-1 && a[result] < a[result+1])
	{
		result++;
	}
	return result;
}


void test_ (void)
{
	int a[1000];
	double a[1000];
	int n = ints_get (a);
	int m = doubles_get(a);
	ints_println_special (a,n);
	doubles_println_special (a,n);
}

int main (void)
{
	test_ ();
	return 0;
}