#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int ints_min_1(int result_1 , int k)
{
    if (result_1 > k)
      result_1 = k;
  return result_1;
}


int ints_maradona_1 (const int*d , int m, int*b)
{
	int p = 0;
	int k;
	int result_1 = 0;
	int g;
	for (int i = 0 ; i < m ; i++)
	{
		k = d[i];
		int result = ints_count (d,m,k);
		if ( p < result ) 
		{
			p = result;
			result_1 = d[i];
		}
		else if (p == result)
		{
			g = ints_min_1(result_1,k);
			result_1 = g;
			p = result;
		}
	}
	b[0] = result_1;
	b[1] = p;
	printf("%d %d\n", b[0], b[1]);
	return 0;
}


int ints_maradona (const int*a, int n, int*b)
{
	int d[1000];
	int k;
	int m = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if (a[i] >= 100)
		{
			k = a[i]/100;
			d[m++] = k;
		}
		else 
		{
			d[m++] = 0;
		}
	}
	ints_maradona_1 (d,m,b);
	return 0;
}


void test_maradona (void)
{
	int a[1000];
	int b[1000];
	int n = ints_get (a);
	ints_maradona (a,n,b);	
}



double doubles_albufeira_1 (const double*a, int i,int p)
{
	return p == 0 ? 0 : a[i] + doubles_albufeira_1 (a,i+12,p-1);
}

double doubles_albufeira (const double*a, int n)
{
	double d[1000];
	int m = 0;
	double anos = (n+1)/12;
	double total;
	double media;
	int k = 12;
	for (int i = 0; i < k; i++)
	{
		int p = anos - 1 ;
		total = doubles_albufeira_1 (a,i,p);
		media = total / p;
		int ultimo = i+((anos-1)*12);
		if (a[ultimo] < media)
		{
			d[m++] = i+1;
		}
	}
	doubles_println_special (d,m);
	return 0;
}

void test_albufeira (void)
{
	double a[1000];
	int n = doubles_get (a);
	doubles_albufeira (a,n);
}


void ints_println_basic_1(const int *a, int n)
{
  if (n > 0)
  {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)  // i = 1
      printf("\n%d", a[i]);
  }
  printf("\n");
}

int ints_stop_1 (int k, int x)
{
	int result;
	if (k%10 == x && k != 0)
	{
		result = 1;
	}
	else if (k <= 0)
	{
		result = 0;
	}
	else
	{
		result = ints_stop_1 (k/10, x);
	}
	return result;
}

int ints_stop (const int*a, int n ,int x, int*d)
{
	int m = 0;
	int k;
	int b = 0;
	int result = 0;
	for (int i = 0 ; i < n ; i++)
	{
		k = a[i];
		result = ints_stop_1(k,x);
		if (result == 1)
		{
			b = b + 1;
		    d[m++]= a[i];
		}
	}
	return b;
}

void ints_test_stop (void)
{
	int x;
	scanf ("%d", &x);
	int a[1000];
	int d[1000];
	int n = ints_get (a);	
	int b = ints_stop (a,n,x,d);
	printf("%d\n", b);
	ints_println_basic_1(d,b);
}




int main(int argc, char **argv)
{
	int x = 'A';
	if (argc > 1)
		x = *argv[1];
	if (x == 'A')
		ints_test_stop ();
	else if (x == 'B')
		test_albufeira (); 
	else if (x == 'C')
		test_maradona ();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	else 
		printf("%s: Invalid option.\n", argv[1]);
  return 0;
}