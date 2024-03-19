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



void test_alfa_3 (void)
{
	char inicial[1000];
	scanf("%s", inicial);
	char pais[1000];
	while (scanf("%s", pais) != EOF)
	{
		int result = str_find (pais,inicial[0]);
		int result_1 = str_find_1 (pais,inicial[1],result );
		int result_2 = str_find_1 (pais,inicial[2], result_1);
		if (result == -1 || result_1 == -1 || result_2 == -1)
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
	test_alfa_3();
	return 0;
}