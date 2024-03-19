
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>


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

int alfa_2 (const char *s , const char*t)
{
	int z = str_find (s,t[0]);
	if (z != -1)
	{
		z  = str_find (s+z+1,t[1]);
	}
	return z;
}


void test_alfa_2 (void)
{
	char inicial[1000];
	scanf("%s", inicial);
	char pais[1000];
	while (scanf("%s", pais) != EOF)
	{
		int result = alfa_2(pais,inicial);
		if (result == -1 )
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}

int main(void)
{
	test_alfa_2();
	return 0;
}