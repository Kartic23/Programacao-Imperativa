#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_greater_than (const int*a , int n,int x, int *result)
{
	assert(n > 0);
	int b = 0;
	for (int i = 0; i < n ; i++ )
		if (a[i] > x)
			result[b++] = a[i];
	return b;
}

void test_ints_greater_than (void)
{
	int a[1000];
	int terminator = -1 ;
	int n = ints_get_until (terminator, a);
	int x;
	int b;
	int result[1000];
	while (scanf("%d" , &x) != EOF)
	b = ints_greater_than (a,n,x,result);
	ints_println_special (result,b);
}

int main(void)
{
	test_ints_greater_than ();
    return 0;
}