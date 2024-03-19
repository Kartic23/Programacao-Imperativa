#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int ints_maximo_1 (int seguidos_b ,int result)
{
	if (seguidos_b < result)
	{
		seguidos_b = result;
	}
	return seguidos_b;
}

int ints_maximo (int seguidos_a, int result)
{
	if (seguidos_a < result)
	{
		seguidos_a = result;
	}
	return seguidos_a;
}


double doubles_consecutivos_a (const double *a, int n)
{
	int result = 0;
	int seguidos_a = 0;
	int i = 0;
	while (i < n)
	{
		if (a[i] > 0)
		{
			result++;
		}
		else
		{
			seguidos_a = ints_maximo (seguidos_a, result);
			result = 0;
		}
		i++;
	}
	return seguidos_a;
}

double doubles_consecutivos_b (const double *b, int n)
{
	int result = 0;
	int seguidos_b = 0;
	int i = 0;
	while (i < n)
	{
		if (b[i] > 0)
		{
			result++;
		}
		else
		{
			seguidos_b = ints_maximo_1 (seguidos_b, result);
			result = 0;
		}
		i++;
	}
	return seguidos_b;
}

double doubles_chuva_b (const double *b, int n)
{
	int dias = 0;
	int i = 0;
	while (i < n)
	{
		if (b[i] > 0)
		{
			dias++;
		}
		i++;
	}
	return dias;
}

double doubles_chuva_a (const double *a, int n)
{
	int dias = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (a[i] > 0)
			dias++;
	}
	return dias;
}

double doubles_maxima_b (const double*b, int n)
{
	double max_b = 0;
	int i = 0;
	while (i < n)
	{
		if (b[i] > max_b)
		{
			max_b = b[i];
		}
		i++;
	}
	return max_b;
}

double doubles_maxima_a (const double*a, int n)
{
	double max_a = 0;
	int i = 0;
	while (i < n)
	{
		if (a[i] > max_a)
		{
			max_a = a[i];
		}
		i++;
	}
	return max_a;
}

double doubles_total_b (const double*b, int n)
{
	double total_b = 0;
	int i = 0;
	while (i < n)
	{
		total_b = total_b + b[i];
		i++;
	} 
	return total_b;
}

double doubles_total_a (const double*a, int n)
{
	double total_a = 0;
	int i = 0;
	while (i < n)
	{
		total_a = total_a + a[i];
		i++;
	} 
	return total_a;
}


void test_doubles_penico (void)
{
	double a[1000];
	double b[1000];
	int n = doubles_get_two (a,b);
	double total_a = doubles_total_a (a,n);
	double total_b = doubles_total_b (b,n);
	double max_a = doubles_maxima_a (a,n);
	double max_b = doubles_maxima_b (b,n);
	int dias_a = doubles_chuva_a (a,n);
	int dias_b = doubles_chuva_b (b,n);
	int seguidos_a = doubles_consecutivos_a (a,n);
	int seguidos_b = doubles_consecutivos_b (b,n);
	printf("%0.1f %0.1f\n", total_a , total_b);
	printf("%0.1f %0.1f\n", max_a , max_b);
	printf("%d %d\n", dias_a , dias_b);
	printf("%d %d\n", seguidos_a , seguidos_b );
}

int main (void)
{
	test_doubles_penico();
	return 0;
}