#include<stdio.h>
#include<math.h>
#include<assert.h>
#include "our_ints.h"

int ints_bitonica_1(const int *a, int n)
{
  int result = 0;
  assert (n >= 2);
  for (int i = 1 ; i < n-1 ; i++)
  {
    if ((a[i-1] < a[i] && a[i] > a[i+1]) || (a[i-1] > a[i] && a[i] < a[i+1]))
    {
      result++;
    }
  }
  return result;
}

int ints_bitonica (const int*a , int n)
{
	int result = ints_bitonica_1 (a,n);
	if (result == 1 || result == 0)
	{
		printf("bitonico\n");
	}
	else
	{
		printf("desordenado\n");
	}
	return 0;
}

void test_ints_bitonica (void)
{
	int a[1000];
	int n = ints_get(a);
	ints_bitonica (a,n);
}

int main(void)
{
	test_ints_bitonica();
	return 0;
}