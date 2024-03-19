#include<stdio.h>
int sum_positive_integers (int n)
{
	return n==0 ? 0 : n + sum_positive_integers (n - 1 );
}
int sum_multiples (int r , int n)
{
	return n==0 ? 0 :  sum_positive_integers (n-1) * r ;
}

void test_sum_multiples (void)
{
	int r;
	int n;
	while ( scanf ("%d%d" , &r , &n) != EOF)
	{
		int z = sum_multiples ( r , n);
		printf  ( "%d\n" , z); 
	}
}

int main (void)
{
	test_sum_multiples ();
	return 0;
}