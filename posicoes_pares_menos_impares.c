#include <stdio.h>
#include <math.h>
#include <assert.h>

int even_positions_minus_odd_positions (const int *a , int result)
{
	int odd = 0;
	int pair = 0;
	for (int i = 0; i < result ; i++)
	{
		if (i%2 == 0)
		{ 
			pair = pair + a[i];
		}
		else
		{
			odd = odd + a[i];
		}
	}
	int k;
	k = pair - odd;
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

void test_even_positions_minus_odd_positions (void)
{
	int a[1000];
	int result = ints_get (a); 
	int k = even_positions_minus_odd_positions (a ,result);
	printf("%d\n", k);
}

int main (void)
{
	test_even_positions_minus_odd_positions();
	return 0;
}
