#include<stdio.h>
double sum_inverse_squares (double n)
{
	return n==0 ? 0 : 1/(n*n) + sum_inverse_squares(n-1); 
}

void test_sum_inverse_squares(void)
{
	double n;
	while ( scanf("%lf" , &n ) != EOF )
	{
		double z = sum_inverse_squares (n) ;
		printf("%f\n", z );
	}
}

int main (void)
{
	test_sum_inverse_squares();
	return 0;
}