#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"



double doubles_groups(const double *a, int n)
{
	double result = 0;
	int i= 0;
	while (i < n)
	{ 
		result = result + a[i];
		i++;
	}
	return result;
}


void test_array (void)
{
	double a[1000];
	int n = doubles_get (a);
	double result = doubles_groups (a,n);
	printf("%f\n",  result);
}


int main (void)
{
	test_array ();
	return 0;
}