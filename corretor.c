#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>

int encontrar_diferenca (char* s, char* t, int letra_1 ,int letra_2)
{

	int i = 0;
	int k = 0;
	int m = 0;
	while (s[i] != '\0' && t[i] != '\0')
	{
		if (s[m] == t[i])
			k++;
		else if (s[m] != t[i] && letra_1 > letra_2)
			i = i - 1 ;
		else
			m = m - 1;
		m++;
		i++;
	}
	if (k == letra_1 - 1 || k == letra_2 - 1)
		k = 1;
	else
		k = 0;
	return k;
}

int igual (char* s ,char* t , int letra_1)
{
	int i = 0;
	int k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == t[i])
			k++;
	i++;
	}
	if (k == letra_1 || k == letra_1 - 1)
		k = 1;
	else
		k = 0;
	return k;
}

int str_len(const char *s)
{   
	int result = 0;
	while (s[result] != '\0')
		result++;
	return result;
}


int corretor (char* s ,char* t)
{
	int k = 0;
	int letra_1 = str_len(s);
	int letra_2 = str_len (t);
	if (letra_1 == letra_2)
		k = igual(s,t, letra_1);
	else
		k = encontrar_diferenca(s,t,letra_1, letra_2);
	return k;
}

void test_corretor (void)
{
	char s[1000];
	char t[1000];
	while (scanf("%s%s" , s, t) != EOF)
	{
		int result = corretor (s,t);
		if (result == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

int main(void)
{
	test_corretor();
	return 0;
}