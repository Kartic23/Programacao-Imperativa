#include<stdio.h>
double sum_inverses(double n)
{
	return n==0 ? 0 : 1/n + sum_inverses(n-1);
}

void test_sum_inverses(void)
{
	double n;
	while (scanf ("%lf" , &n ) != EOF)
	{
		double z = sum_inverses( n );
		printf("%f\n", z ); 
	}
}
int main(void)
{
	test_sum_inverses ();
	return 0;
}

