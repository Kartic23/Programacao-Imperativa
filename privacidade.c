#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>

int str_len(const char *s)
{   
	int result = 0;
	while (s[result] != '\0')
		result++;
	return result;
}


int contar (const char*s)
{
	int result = 0;
	while(s[result] != '\0' && s[result] != '_')
	{
		result++;
	}
	return result;
}

char* final (const char* s ,char* r , int*d, int m, int letras)
{
	r[0] = s[0];
	r[1] = s[d[m-2]];
	r[2] = s[letras-2];
	r[3] = s[letras-1];
	return r;
}

char* privacidade (const char* s, char*r)
{
	int d[1000];
	int m = 0;
	int i = 0;
	int letras = str_len(s);
	while (i < letras)
	{
		d[m++] = i;
		int t = contar(s + i);
		i = i + t + 1;
	}
	final(s,r,d,m,letras);
	r[4] = '\0';
	return r;
}

void test_privacidade (void)
{
	char s[1000];
	while (scanf("%s" , s) != EOF)
	{
		char r[1000];
		privacidade(s,r);
		printf("%s\n", r);
	}
}

int main()
{
	test_privacidade();
	return 0;
}