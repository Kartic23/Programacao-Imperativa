#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"


int ints_find_triple (const int*a , int n)
{
	int d[1000];
	int m = 0;
	int k = -1;
	for (int i = 0; i < n-2 ; i++)
	{
		if (a[i] == a[i+1]  &&  a[i] == a[i+2] )
		{
			k = i; 
			d[m++] = i;
		}
	}
	if (k != -1)
	{
		k = ints_min (d,m);
	}
	else
	{
		k = -1;
	}
	printf("%d\n", k);
	return 0;
}

void test_ints_find_triple (void)
{
	int a [1000];
    int n = ints_get_until (-1 ,a);	
    ints_find_triple (a,n);	
}



int ints_unaccumulate (const int*a , int n)
{
	int d[1000];
	int m = 0;
	for (int i = 0 ; i < n-1 ; i++)
	{
		d[m++] = a[i+1] - a[i];
	}
	ints_println_special (d,m);
	return 0;
}

void test_ints_unaccumulate (void)
{
    int a[1000];
    int n = ints_get_until (-1 ,a);	
    ints_unaccumulate (a,n);	
}


int ints_accumulate_1 (const int*a, int i)
{
	return i == 0 ? a[i] : a[i] + ints_accumulate_1(a ,i-1);
}

int ints_accumulate (const int*a , int n)
{
	int d[1000];
	int m = 1;
	for (int i = 0  ; i < n ; i++)
		d[m++] = ints_accumulate_1(a,i);
	    d[0] = 0;
	ints_println_special (d,m);
	return 0;
}


void test_ints_accumulate (void)
{
	int a[1000];
    int terminator = -1;
    int n = ints_get_until (terminator ,a);	
    ints_accumulate (a,n);
}


int ints_ascending (const int*a , int n)
{
	int d[1000];
	int k = a[0];
	int m = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (a[i] >= k)
        	{
        	    k  = a[i];
        		d[m++] = a[i];
        	}
    }
    ints_println_special (d,m);
    return 0;
}

void test_ints_ascending (void)
{
	int a[1000];
    int n = ints_get_until (-1 ,a);	
    ints_ascending (a,n);	
}


int ints_drop_1 (const int*a , int n)
{
	ints_println_special (a,n);
	return 0;
}

int ints_drop (const int*a , int n, int x , int *d)
{
	if(x < 0)
		ints_drop_1 (a,n);
	else
	{
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (i >= x)
			d[b++] = a[i];
	}
	ints_println_special(d,b); 
	}
	return 0;
}

void test_ints_drop (void)
{
	int a[1000];
	int terminator = -1;
	int n = ints_get_until(terminator,a);
	int x;
	int d[1000];
	while (scanf ("%d" , &x) != EOF)
	ints_drop (a,n,x,d);
}


int ints_take (const int*a , int n, int x , int *d)
{
	int b = 0;
	if(x < 0)
		b = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < x)
			d[b++] = a[i];
	}
	ints_println_special(d,b);
	return 0;;
}

void test_ints_take (void)
{
	int a[1000];
	int terminator = -1;
	int n = ints_get_until(terminator,a);
	int x;
	int d[1000];
	while (scanf ("%d" , &x) != EOF)
	ints_take(a,n,x,d);
}

int ints_append_1 (const int *a, int n,const int *b, int m,int *c)
{
	int k = 0;
	for (int i = 0 ; i < m ; i++)
	{
		c[k++] = b[i];
	}
	for (int i = 0 ; i < n ; i++)
	{
	    c[k++] = a[i];
	}
	ints_println_special (c,k);
	return 0;
}

int ints_append (const int *a, int n,const int *b, int m,int *c) 
{
	int k = 0;
	for (int i = 0 ; i < n ; i++)
	{
		c[k++] = a [i];
	}
	for (int i = 0 ; i < m ; i++)
	{
	    c[k++] = b [i];
	}
	ints_println_special (c,k);
	ints_append_1(a,n,b,m,c);
	return 0;
}

void test_ints_append (void)
{
	int a[1000];
	int b[1000];
	int c[1000];
	int n = ints_get_until (-1, a);
	int m = ints_get_until (-1, b);
	ints_append (a,n,b,m,c);
}

int ints_digits_sum_1 (int k)
{
	return k < 10 ? k : (k%10) + ints_digits_sum_1(k/10);
}

int ints_digits_sum (const int*a , int n)
{
	int m = 0;
	int d[1000];
	int k;
	for (int i = 0 ; i < n ; i++)
		if (a[i] < 10 )
		{
		   d[m++] = a[i];
		}
	    else
	    {
	    	k = a[i];
		    d[m++] = ints_digits_sum_1(k);
	    }
    ints_println_special (d,m);
	return 0;
}

void test_ints_digits_sum (void)
{
	int a[1000];
	int terminator = -1 ;
	int n = ints_get_until (terminator, a);
	ints_digits_sum (a,n);
}

int ints_less_than (const int *a , int n, int k ,int *result)
{
	int r = 0;
	for (int i = 0; i < n ; i++ )
	{
		if (a[i] < k)
			result[r++] = a[i];
	}
	ints_println_special (result,r);
	return 0;
}

void test_ints_less_than (void)
{
	int a[1000];
	int n = ints_get_until (-1, a);
	int k;
	int result[1000];
	while (scanf("%d" , &k) != EOF)
	ints_less_than (a,n,k,result);
}



int ints_greater_than (const int*a , int n,int x, int *result)
{
	int b = 0;
	for (int i = 0; i < n ; i++ )
	{
		if (a[i] > x)
			result[b++] = a[i];
	}
	ints_println_special (result,b);
	return 0;
}

void test_ints_greater_than (void)
{
	int a[1000];
	int n = ints_get_until (-1, a);
	int x;
	int result[1000]; 
	while (scanf("%d" , &x) != EOF)
	ints_greater_than (a,n,x,result);
}


int main(int argc, char **argv)
{
	our_ints_unit_tests();
	int x = 'G';
	if (argc > 1)
		x = *argv[1];
	if (x == 'A')
		test_ints_greater_than ();
	else if (x == 'B')
		test_ints_less_than ();
	else if (x == 'C')
		test_ints_digits_sum ();
	else if (x == 'D')
		test_ints_append ();
	else if (x == 'E')
		test_ints_take ();
	else if ( x == 'F')
		test_ints_drop ();
	else if (x == 'G')
		test_ints_ascending();
	else if (x == 'H')
		test_ints_accumulate();
	else if (x == 'I')
		test_ints_unaccumulate();
	else if (x == 'J')
		test_ints_find_triple();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	else 
		printf("%s: Invalid option.\n", argv[1]);
  return 0;
}