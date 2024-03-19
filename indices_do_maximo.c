#include<stdio.h>
#include<math.h>
#include<assert.h>

void ints_println_basic (const int *d ,int result)
{	
	if (result > 0)
	{
		printf("%d", d[0]);
		for (int i = 1; i < result ; i++)  
			printf(" %d", d[i]);
	}
	printf("\n");
}
		
int ints_indices (const int *a , int n, int b ,int *d)
{
	int result = 0;
	for (int i = 0 ; i < n ; i++)
		if (a[i] == b)
			d[result++] = i;
	ints_println_basic (d,result);
	return 0;
}

int ints_argmax (const int*a, int n)
{
	assert (n > 0);
	int b = a[0];
	for (int i = 1; i < n ; i++)
		if (b < a[i])
			b = a[i];	
	return b;
}

int ints_argsmax (const int*a , int n)
{
	int b = ints_argmax (a, n);
	int d[1000];
	ints_indices(a,n,b,d);
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

void test_ints_argsmax (void)
{
	int a[1000];
	int n = ints_get (a);
	ints_argsmax(a, n);
}

int main (void)
{
	test_ints_argsmax ();
	return 0;
}