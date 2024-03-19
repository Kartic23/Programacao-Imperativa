#include<stdio.h>
#include<math.h>
const double desconto = 0.8;

double azeite (double p, double c, int u)
{
	int y;
	int z;
	double a;
	double b;
	double x;
	double result;
	y = u/3;
	z = u%3;
	a = y * (2 * (p * desconto));
	b = z * (p * desconto);
	x = u * c;
	result = (a + b)/x;
	result = round (result * 100)/100;
	return result;
}

void test_azeite (void)
{
	double p;
	double c;
	int u;
	while (scanf("%lf%lf%d" , &p ,&c ,&u) != EOF)
	{
		double result = azeite (p ,c ,u);
		printf("%f\n", result);
	}
}



int main (void)
{
	test_azeite();
	return 0;
}