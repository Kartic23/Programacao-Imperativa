#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

int ints_video_1 (const int*a, int n ,int valor , int alcance)
{
	int result;
	for (int i = 0; i < n ; i++)
	{
		if (a[i] <= valor && valor <= a[i]+ alcance)
	{
		result = 1;
	}	
	}
	if (result != 1)
	{
		result = 0;
	}
	else
	{
		result = 1;
	}
	return result;
}

int ints_video (const int*a, int n ,const int*b , int m , int alcance)
{
	for (int i = 0 ; i < m  ; i++ )
	{
		int valor = b[i];
		int result = ints_video_1 (a,n,valor,alcance);
		if (result == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}			
	}
	return 0;
}

void test_video (void)
{
	int alcance;
	scanf ("%d" , &alcance);
	int a[1000];
	int n = ints_get_until (-1,a);
	int b[1000];
	int m = ints_get (b);
	ints_video (a,n,b,m,alcance);
}

int main (void)
{
	test_video();
	return 0;
}