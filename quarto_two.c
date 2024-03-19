#include<stdio.h>

double sum_progression_dbl (double x0, double r, int n)
{
	return n==0 ? 0 : x0 + sum_progression_dbl(x0 + r, r , n-1);
}

void test_sum_progression_dbl (void)
{
	double x0;
	double r;
	int n;
	while(scanf("%lf%lf%d" , &x0 , &r , &n) != EOF)
	{
		double z = sum_progression_dbl(x0 , r , n);
		printf("%f\n", z);
	}
}

int main(void)
{
	test_sum_progression_dbl();
	return 0;
}