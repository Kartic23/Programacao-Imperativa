#include <stdio.h>

int sum_positive_integers (int n)
{
	return n==0 ? 0 : n + sum_positive_integers (n - 1 );
}
void test_sum_positive_integers (void)
{
	int n;
	while ( scanf ("%d" , &n) != EOF )
	{
		int z = sum_positive_integers ( n );
		printf ("%d\n" , z);
	}
}

int main (void )
{
	test_sum_positive_integers ();
	return 0;
}