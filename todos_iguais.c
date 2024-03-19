#include<stdio.h>
#include<math.h>
#include<assert.h>

int ints_min (const int*a ,int result)
{
	assert (result > 0);
	int c = a[0];
	for (int i = 1; i < result ; i++)
		if ( c > a[i])
			c = a[i];
	return c;
}

int ints_max (const int*a, int result)
{
	assert (result > 0);
	int b = a[0];
	for (int i = 1; i < result ; i++)
		if (b < a[i])
			b = a[i];
	return b;
}

int ints_all_equal (const int *a , int result)
{
	int k;
	int b = ints_max (a ,result);
	int c = ints_min (a,result);
		if (b == 0)
		{
			k = 1;
		}
		else if ( b == c)
		{
			k = 1;
		}
		else
		{
			k = 0;
		}
	return k;
}

int ints_get(int *a)
{ 
	int result = 0;
	int x;
	while (scanf("%d", &x) != EOF) 
		a[result++] = x;
	return result;
}

void test_ints_all_equal (void)
{
	int a[1000];
	int result = ints_get (a);
	int k = ints_all_equal (a, result);
	printf ("%d\n", k);
}

int main (void)
{
	test_ints_all_equal ();
	return 0;
}