#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>

int remover (int*p , const int*k , int m)
{
	int c = 0;
	for (int i = 0; i < m; ++i)
	{
		if (k[i] != -1)
			p[c++] = k[i];
	}
	return c;
}

int contar(const int *a, int n, int x)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == x)
      result++;
  return result;
}

int ints_minimo (const int*a , int n)
{
	int result = a[0];
	for (int i = 0; i < n; i++)
		if (result > a[i] )
			result = a[i];
	return result;
}

int extra(const int *k ,int m)
{
	int p[1000];
	int result = -1;
	int l = contar(k,m,-1);
	if (m != l)
	{
		int t = remover(p,k,m);
		result = ints_minimo(p,t);
	}
	return result;
}



int str_find (const char*s , char x)
{
	for (int i = 0 ; s[i] != '\0' ; i++)
		if (s[i]==x)
			return i;
	return -1;
}

int str_find_any (const char*a, const char*b)
{
	int k[1000];
	int m = 0;
	for (int i = 0; b[i] != '\0' ; ++i)
	{
		int z = str_find(a,b[i]);
		k[m++] = z;
	}
	int result = extra(k,m); 
	return result;
}

void test_encontrar (void)
{
	char a[1000];
	char b[1000];
	while (scanf("%s%s" , a, b) != EOF)
	{
		int result = str_find_any(a,b);
		printf("%d\n", result);
	}
}

int main (void)
{
	test_encontrar();
	return 0;
}