#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"


int ints_find_triple (const int*a , int n)
{
	int d[1000];
	int m = 0;
	int k = 0;
	for (int i = 0; i < n-2 ; i++)
	{
		if (a[i] == a[i+1])
		{
			if (a[i] == a[i+2])
			{
				k = i;
				d[m++] = i;
				k = ints_min (d,m);	
			}
			else
			{
				k = -1;
			}
		}
		else
		{
			k = -1;
		}
	}
	printf("%d\n", k);
	return 0;
}

void test_ints_find_triple (void)
{
	int a [1000];
    int n = ints_get_until (-1 ,a);	
    ints_find_triple (a,n);	
}

int main(int argc, char **argv)
{
	our_ints_unit_tests();
	int x = 'J';
	if (argc > 1)
		x = *argv[1];
	else if (x =='J')
		test_ints_find_triple ();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	else 
		printf("%s: Invalid option.\n", argv[1]);
  return 0;
}