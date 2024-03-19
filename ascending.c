#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_ascending (const int*a , int n)
{
	int d[1000];
	int result = a[0];
	int m = 1;
	d[0] = a[0];
    for (int i = 1; i < n ; i++)
    {
          if (result <= a[i])
          	{
          		result = a[i];
          		d[m++] = a[i];
          	}
    }
    ints_println_special (d,m);
    return 0;
}

void test_ints_ascending (void)
{
	int a[1000];
    int n = ints_get_until (-1 ,a);	
    ints_ascending (a,n);	
}

int main (void )
{
	test_ints_ascending();
	return 0;
}