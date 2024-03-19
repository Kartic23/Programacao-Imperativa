#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_doubles.h"

double doubles_max_1 (const double *a, int n)
{
  double result = a[0];
  for (int i = 1; i < n; i++) 
    if (result <= a[i])
      result = a[i];
  return result;
}


double doubles_min_1(const double *a, int n)
{
  double result = a[0];
  for (int i = 0; i < n; i++)
    if (result >= a[i])
      result = a[i];
  return result;
}

int doubles_argmin_1 (const double *a, int n)
{
  int x = 0;
  double m = a[0];
  for (int i = 1; i < n; i++) 
  {
  	if (m >= a[i])
  	{
      m = a[i];
      x = i;
  	}
  } 
  return x;
}

int doubles_argmax_1(const double *a, int n)
{
  int y = 0;
  double m = a[0];
  for (int i = 1; i < n; i++)
  {
  	if (m <= a[i])
    {
    m = a[i];
    y = i ;
    }
  }
  return y;
}

double doubles_gasolina (const double*a , double n )
{
	double k = doubles_max_1 (a,n);
	double j = doubles_min_1 (a,n);
	int y = doubles_argmax_1 (a,n);
	int x = doubles_argmin_1 (a,n);
	int w = x - y;
	w = w - 1;
	if (k == j && k != 0 )
	{
		printf("Idem\n");
	}	
	else if (x < y || k == 0)
	{
		printf("void\n");
	}
	else
	{
		printf("%d\n", w);
	}
	return 0;
}

void test_doubles_gasolina (void)
{
	double a[1000];
	double n = doubles_get (a);
	doubles_gasolina (a,n);
}


int main (void)
{
	test_doubles_gasolina ();
	return 0;
}