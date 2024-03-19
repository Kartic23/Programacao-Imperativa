#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_less_than (const int *a , int n, int k ,int *result)
{
	int r = 0;
	for (int i = 0; i < n ; i++ )
		if (a[i] < k)
			result[r++] = a[i];
	return r;
}

void test_ints_less_than (void)
{
	int a[1000];
	int terminator = -1 ;
	int n = ints_get_until (terminator, a);
	int k;
	int result[1000];
	int r;
	scanf("%d" , &k);
	r = ints_less_than (a,n,k,result);
	ints_println_special (result,r);
}

int main(void)
{
	test_ints_less_than();
    return 0;
}
