#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_doubles.h"

double doubles_neve_2 (const double*a , int i, int dias,int x)
{
	return dias == 0 ? a[i] : a[i] + doubles_neve_2 (a,i+x , dias-1,x);
}

double doubles_neve_1 (const double*a , int n,int x,double cada)
{
	int dias;
	double d[1000];
	int m = 0;
	dias = n/x;
	for (int i = 0 ; i < x ; i++)
	{
		d[m++] = doubles_neve_2 (a,i,dias,x) - cada;
	}
	doubles_println_special (d,m);
	return 0;
}

double doubles_neve (const double*a , int n,int x)
{
	double total = 0;
	double cada;
	for (int i = 0 ; i < n ; i++)
	{
		total = total + a[i];
	}
	cada = total/x;
	doubles_neve_1 (a,n,x,cada);
	return 0;
}

void test_neve (void)
{
	int x;
	scanf ("%d" , &x);
	double a[1000];
	int n = doubles_get(a);
	doubles_neve (a,n,x);	
}



int main (void)
{
	test_neve ();
	return 0;
}