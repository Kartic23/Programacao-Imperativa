#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_digits_sum_1 (int k)
{
	return k < 10 ? k : (k%10) + ints_digits_sum_1(k/10);
}

int ints_digits_sum (const int*a , int n)
{
	int m = 0;
	int d[1000];
	int k;
	for (int i = 0 ; i < n ; i++)
		if (a[i] < 10 )
		{
		   d[m++] = a[i];
		}
	    else
	    {
	    	k = a[i];
		    d[m++] = ints_digits_sum_1(k);
	    }
    ints_println_special (d,m);
	return 0;
}

void test_ints_digits_sum (void)
{
	int a[1000];
	int terminator = -1 ;
	int n = ints_get_until (terminator, a);
	ints_digits_sum (a,n);
}

int main(void)
{
    test_ints_digits_sum ();
    return 0;
}