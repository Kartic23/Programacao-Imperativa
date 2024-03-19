#include<stdio.h>
#include<math.h>
#include<assert.h>

int ints_second_max(const int*d, int m)
{
	int result = d[0];
	for (int i = 1; i < m ; i++)
		if (result < d[i])
			result = d[i];
	printf("%d\n", result );
	return 0;
}

int ints_remove (const int*a, int n, int k, int *d)
{
	int m = 0;
	for (int i= 0; i< n; i++)
		if (a[i] != k)
			d[m++] = a[i];
	ints_second_max (d,m);
	return 0;
}

int ints_min (const int*a ,int n)
{
	assert (n > 0);
	int b = a[0];
	for (int i = 1; i < n ; i++)
		if ( b > a[i])
			b = a[i];
	return b;
}

int ints_max_1(const int*a , int n)
{
	assert (n > 0);
	int c = a[0];
	for (int i = 1; i < n ; i++)
		if (c < a[i])
			c = a[i];
	return c;
}

int ints_all_equal (const int*a ,int n)
{
	int b = ints_min (a,n);
	int c = ints_max_1 (a,n);
	int p;
	if (b == c)
	{
		p = 0;
	}
	else
	{
		p = 1;
	} 
	return p;
}

int ints_max (const int*a, int n)
{
	int p = ints_all_equal(a,n);
	assert(n > 1 && p != 0);
	int k = a[0];
	int d[1000];
	for (int i = 1; i < n ; i++)
		if (k < a[i])
			k = a[i];
	ints_remove(a,n,k,d);
	return 0;
}

int ints_get(int *a)
{ 
	int n = 0;
	int x;
	while (scanf("%d", &x) != EOF) 
		a[n++] = x;
	return n;
}

void test_ints_max (void)
{
	int a[1000];
	int n = ints_get (a);
	ints_max (a, n);
}

int main (void)
{
	test_ints_max ();
	return 0;
}