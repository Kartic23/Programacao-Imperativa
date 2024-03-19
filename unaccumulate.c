#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"


int ints_unaccumulate (const int*a , int n)
{
	int d[1000];
	int m = 0;
	for (int i = 0 ; i < n-1 ; i++)
	{
		d[m++] = a[i+1] - a[i];
	}
	ints_println_special (d,m);
	return 0;
}

void test_ints_unaccumulate (void)
{
    int a[1000];
    int n = ints_get_until (-1 ,a);	
    ints_unaccumulate (a,n);	
}

int main(void)
{
	test_ints_unaccumulate();
	return 0;
}