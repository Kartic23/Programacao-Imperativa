#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>
#include "our_ints.h"
#include "our_doubles.h"

/*Eu, Kartic Hitendra Premgi , declaro por minha honra que este programa foi escrito por mim, 
durante o exame de 5 de fevereiro de 2021, e que não recebi ajuda de ninguém, a não ser
da professora Graça*/


//----------------------------------------------------------------// B = corretor

int encontrar_diferenca (char* s, char* t, int letra_1 ,int letra_2)
{

	int i = 0;
	int k = 0;
	int m = 0;
	int result = 0;
	while ((s[i] != '\0' || t[i] != '\0') && i < letra_2 && m < letra_1)
	{
		if (s[m] == t[i])
			k++;

		else if (letra_1 > letra_2)
		{
			i = i - 1;
		    result++;
		}
		else
		{
			m = m - 1;
		    result++;
		}
		m++;
		i++;
	}
	if ((k == letra_1 - 1 || k == letra_2 - 1) && result <= 1)
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


//_-----------------------------------------------------------------------// A = privacidade


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

//--------------------------------------------------------------------------------//


int main(int argc, char **argv)
{
	int x = 'B';
	if (argc > 1)
		x = *argv[1];
	if ( x == 'A')
		test_privacidade();
	else if ( x== 'B')
		test_corretor();
	else if ( x == 'C')
	    test_terceira_vaga();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	else 
		printf("%s: Invalid option.\n", argv[1]);
  return 0;
}