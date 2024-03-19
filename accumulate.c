#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"


int ints_accumulate_1 (const int*a, int i)
{
	return i == 0 ? a[i] : a[i] + ints_accumulate_1(a ,i-1);
}

int ints_accumulate (const int*a , int n)
{
	int d[1000];
	int m = 1;
	for (int i = 0  ; i < n ; i++)
		d[m++] = ints_accumulate_1(a,i);
	    d[0] = 0;
	ints_println_special (d,m);
	return 0;
}


void test_ints_accumulate (void)
{
	int a[1000];
    int terminator = -1;
    int n = ints_get_until (terminator ,a);	
    ints_accumulate (a,n);
}

int main(void)
{
	test_ints_accumulate();
	return 0;
}