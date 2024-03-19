#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h" 

int ints_min_1(int result_1 , int k)
{
    if (result_1 > k)
      result_1 = k;
  return result_1;
}


int ints_maradona_1 (const int*d , int m, int*b)
{
	int p = 0;
	int k;
	int result_1 = 0;
	int g;
	for (int i = 0 ; i < m ; i++)
	{
		k = d[i];
		int result = ints_count (d,m,k);
		if ( p < result ) 
		{
			p = result;
			result_1 = d[i];
		}
		else if (p == result)
		{
			g = ints_min_1(result_1,k);
			result_1 = g;
			p = result;
		}
	}
	b[0] = result_1;
	b[1] = p;
	printf("%d %d\n", b[0], b[1]);
	return 0;
}


int ints_maradona (const int*a, int n, int*b)
{
	int d[1000];
	int k;
	int m = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if (a[i] >= 100)
		{
			k = a[i]/100;
			d[m++] = k;
		}
		else 
		{
			d[m++] = 0;
		}
	}
	ints_maradona_1 (d,m,b);
	return 0;
}


void test_maradona (void)
{
	int a[1000];
	int b[1000];
	int n = ints_get (a);
	ints_maradona (a,n,b);	
}



int main (void)
{
	test_maradona ();
	return 0;
}
