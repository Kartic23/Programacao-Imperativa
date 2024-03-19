#include<stdio.h>
double sum_squares_from (double n , double x)
{
	return x == 0 ? 0 : n * n + sum_squares_from (n+1 , x-1);
}
void test_sum_squares_from (void)
{
	double n;
	double x;
	while( scanf("%lf%lf" , &n , &x) != EOF)
	{
		double z = sum_squares_from (n , x);
		printf("%f\n", z);
	}
}
int main(void)
{
	test_sum_squares_from();
	return 0;
}