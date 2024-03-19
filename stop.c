#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

void ints_println_basic_1(const int *a, int n)
{
  if (n > 0)
  {
    printf("%d\n", a[0]);
    for (int i = 1; i < n; i++)  // i = 1
      printf("%d\n", a[i]);
  }
  printf("\n");
}

int ints_stop_1 (int k, int x)
{
	int result;
	if (k%10 == x && k >= 0)
	{
		result = 1;
	}
	else if (k <= 0)
	{
		result = 0;
	}
	else
	{
		result = ints_stop_1 (k/10, x);
	}
	return result;
}

int ints_stop (const int*a, int n ,int x, int*d)
{
	int m = 0;
	int k;
	int b = 0;
	int result = 0;
	for (int i = 0 ; i < n ; i++)
	{
		k = a[i];
		result = ints_stop_1(k,x);
		if (result == 1)
		{
			b = b + 1;
		    d[m++]= a[i];
		}
	}
	return b;
}

void test_stop (void)
{
	int x;
	scanf ("%d", &x);
	int a[1000];
	int d[1000];
	int n = ints_get (a);	
	int b = ints_stop (a,n,x,d);
	printf("%d\n", b);
	ints_println_basic_1(d,b);
}

int main (void)
{
	test_stop ();
	return 0;
}