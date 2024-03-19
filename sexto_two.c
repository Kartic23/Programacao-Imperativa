#include<stdio.h>
#include<math.h>
double sum_powers_from (double x , double y , double n)
{
	return n==0 ? 0 : pow (x , y) + sum_powers_from (x+1 , y , n -1 );
}

void test_sum_powers_from (void)
{
	double x;
	double y;
	double n;
	while (scanf("%lf%lf%lf" , &x , &y , &n) != EOF )
	{
		double z = sum_powers_from ( x ,  y , n);
		printf("%f\n", z );
	}
} 
int main (void)
{
	test_sum_powers_from ();
	return 0;
}