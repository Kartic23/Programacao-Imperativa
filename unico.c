#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>


int extra (const char* s , int k)
{
	int result = 0;
	while ( result < k-1 && s[result] == s[result+1])
	{
		result++;
	}
	return result;
}

int str_len(const char *s)
{   
	int result = 0;
	while (s[result] != '\0')
		result++;
	return result;
}

char* str_unique(const char* s, char* r)
{
	int k = str_len(s);
	int i = 0;
	int m = 0; 
	int a = 0;
	while ( i < k)
	{
		r[m++] = s[i];
		a = extra(s + i , k - i);
		i = i + a + 1;
	}
	r[m]='\0';
	return r;
}

void test_unico (void)
{
	char s[1000];
	while(scanf("%s" , s) != EOF)
	{
		char r[1000];
		str_unique(s,r);
		printf("{%s}\n", r);
	}
}

int main ()
{
	test_unico();
	return 0;
}