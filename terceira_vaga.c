#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int descida (const int*a, int n)
{
	int result = 0;
	while ( result < n-1 && a[result] > a[result+1])
		result++;
	return result;
}

int subida (const int*a, int n)
{
	int result = 0;
	while ( result < n-1 && a[result] < a[result+1])
		result++;
	return result;
}

int extra (int*a ,int n, int x )
{
	int seguida_1 = 0;
	int i = 0;
	while (seguida_1 < x && i < n)
	{
		seguida_1 = descida (a + i , n - i);
		i = i + seguida_1 + 1;
	}
	return i;
}



int terceira_vaga(int*a ,int n, int x, int*c ,int *d)
{
	int i  = 0;
	int m = 0;
	int seguida = 0;
	int seguida_1 = 0;
	while (i < n)
	{
		seguida = subida(a  + i , n - i);
		if (seguida >= x)
		{
		      int seguida_1 = extra(a + i + seguida, n - i - seguida,x );
		      c[m] = i;      
		      d[m++] = i + seguida_1;
		}
	i = i + seguida + seguida_1 + 1;	
	}
	return m;
}

void test_terceira_vaga (void)
{
	int x;
	int a[1000];
	int c[1000];
	int d[1000];
	scanf("%d" , &x);
	int n = ints_get(a);
	int m = terceira_vaga(a,n,x,c,d);
	printf("%d\n", m );
	ints_print_two (c,d,m);
}

int main(void)
{
	test_terceira_vaga();
	return 0;
}