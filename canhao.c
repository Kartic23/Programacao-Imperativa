#include<stdio.h>

double canhao (double t , int p)
{
	
}

void test_canhao (void)
{
	double t;
	int p;
	while (scanf("%lf%d" , &t , &p) != EOF)
	{
		canhao(t , p);
	}
}


int main (void)
{
	test_canhao ();
	return 0;
}