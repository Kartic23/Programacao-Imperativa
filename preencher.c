#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>

char* str_cpy_2(char *r, const char *t, int k)
{
	int n = 0;
	for (int i = 0; i < k; i++)
		r[n++] = t[i];
	r[n] = '\0';   
	return r; 
}

char* str_cpy_1(char *r, const char *t, int m) 
{   
	for (int i = 0; t[i] != '\0'  ; i++)
		r[m++] = t[i];
	r[m] = '\0';  
	return r; 
} 

int str_len (const char* s)
{
	int result = 0;
	while (s[result] != '\0')
		result++;
	return result;
}


char* str_repeat (char* r ,const char* s, int n)
{
	int m = 0;
	int letras = str_len(s);
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


char* str_fill (const char*a, int x, char*b)
{
	char r[1000];
	str_repeat(r,a,x);
	str_cpy_2(b,r,x);
	return b;
} 



void test_repetir (void)
{
	char a[1000];
	int x;
	char b[1000];
	while (scanf("%s%d" , a , &x) != EOF)
	{
		str_fill (a,x,b);
		printf("{%s}\n", b );
	}
}

int main (void)
{
	test_repetir();
	return 0;
}