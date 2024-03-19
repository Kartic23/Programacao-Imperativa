#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int count_ascending (const int*a, int n)
{
	int result = 0;
	while ( result < n-1 && a[result] < a[result+1])
	{
		result++;
	}
	return result;
}


int exemplo (const int*a, int n, int x, int*d)
{
	int i = 0;
	int m = 0;
	int contagem = 0; 
	while (i < n)
	{
		contagem = count_ascending (a + i , n - i);
		if (contagem >= x)
		{
			d[m++] = contagem;
		}
		i = i + contagem + 1;  
	}
	return m;
}

void test_exemplo (void)
{
	int a[1000];
	int x;
	scanf("%d" , &x);
	int n = ints_get(a);
	int d[1000];
	int result = exemplo(a,n,x,d);
	int total = ints_sum(d,result);
	printf("%d %d\n",result ,total);
}

int main (void)
{
	test_exemplo();
	return 0;
}