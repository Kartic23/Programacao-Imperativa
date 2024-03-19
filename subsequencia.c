#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>


int str_find_1 (const char*s , char y, int result)
{
	for (int i = 0 ; s[i] != '\0' ; i++)
	{
		if (s[i] == y && result < i)
		{
			return i;
		}
	}
	return -1;
}

int str_find (const char*s , char x)
{
	for (int i = 0 ; s[i] != '\0' ; i++)
	{
		if (s[i]==x)
		{
			return i;
		}
	}
	return -1;
}


int subsequencia (const char *a, const char *nome)
{
	int result = str_find(nome,a[0]); 
	int result_1 = 0;
	if (result != -1)
	{
		for (int i = 1 ; a[i] != '\0' ; i++)
	{
		result_1 = str_find_1(nome,a[i],result);
		if (result_1 == -1)
		{
		    a[i] = '\0';
		    result = -1;
		}
		else
		{
			result = result_1;
		}
	}
	}
	return result;
}

void test_subsequencia (void)
{
	char a[1000];
	char nome[1000];
	while (scanf ("%s %s" , a, nome ) != EOF)
	{
		int result = subsequencia(a,nome);
		if (result == -1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}

int main (void)
{
	test_subsequencia();
	return 0;
}
