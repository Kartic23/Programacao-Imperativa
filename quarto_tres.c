#include<stdio.h>
#include<math.h>

double salary (double s , int h , int m)
{
	double result; 
	double y;
	double x = m ; 
	y = h + ( x/60 ) - 18 ;  
	if (y > 2)
	{
		y = (y - 2) * ( s + (s * 0.5));
		result = (s * 2) + y;
	}
	else 
	{
		result = y * s ; 
	}
	result = round (result * 100 ) / 100 ;
	printf("%f\n", result );
	return 0;
}
void test_salary (void)
{
	double s;
	int h;
	int m;
	while (scanf("%lf%d%d" , &s ,&h , &m ) != EOF )
	{
		salary (s , h , m);
	}
}
int main (void)
{
	test_salary();
	return 0;
}