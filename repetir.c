#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>

char* str_cpy_1(char *r, const char *t, int m) 
{   
	for (int i = 0; t[i] != '\0'  ; i++)
		r[m++] = t[i];
	r[m] = '\0';  
	return r; 
} 

int contar (const char* s)
{
	int result = 0;
	for (int i = 0; s[i] != '\0' ; i++)
		result++;
	return result;
}


char* str_repeat (char* r ,const char* s, int n)
{
	int m = 0;
	int letras = contar(s);
	if (n == 0)
	{
		r[0] = '\0';
	}
	while (n > 0)
	{
		str_cpy_1(r,s,m);
		m = m + letras;
		n--;
	}
	return r;
}

void test_repetir (void)
{
	char a[10000];
	int n;
	char r[1000];
	while (scanf("%s%d" , a, &n) != EOF)
	{
		str_repeat(r,a,n);
		printf("{%s}\n", r );
	}
}

int main (void)
{
	test_repetir();
	return 0;
}