#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int nao_vistos (const int*a , int n , int episodio, int*n_vistos)
//Esta função calcula todos os episodios não vistos//
{
	int result = 0;
    int k= 0;
    int i = 1;
    while (i <= episodio)
    {
        if (i != a[k])
        {
            n_vistos[result++] = i;
        }
        else
        {
            k++	;
        }
        i++;
    }
    return result;
}

int faz_sequencias (const int*a, int m)
{
	int i = 0;
	while ( i < m - 1 && a[i] + 1 == a[i+1])
	{
		i++;
	}
	return i+1;
}

int ints_contagem_de_episodios_seguidos (int* n_vistos, int m, int*indices_finais, int*episodios_seguidos)
{
	int result = 0;
    int i = 0;
    while (i < m)
    {
        int seguidos = faz_sequencias(n_vistos + i, m - i);
        indices_finais[result] = i;
        episodios_seguidos[result] = seguidos;
        result++;
        i = i + seguidos;
    }
    return result;
}

int ints_final_escolhido (int*indices_finais, int* episodios_seguidos, int result, int*n_vistos)
{
	int valor_menor_episodios_seguidos = ints_min (episodios_seguidos,result);
	int descobre = ints_find (episodios_seguidos, result,valor_menor_episodios_seguidos);
	int indice = indices_finais[descobre];
	int final_escolhido = n_vistos[indice];
	return final_escolhido;	
}

int big_bang (const int*a , int n , int episodio)
{
	int n_vistos[1000];
	int m = nao_vistos (a,n,episodio,n_vistos);
	int indices_finais[1000];
	int episodios_seguidos[1000];
	int result = ints_contagem_de_episodios_seguidos (n_vistos,m,indices_finais,episodios_seguidos);
	int final_escolhido = ints_final_escolhido(indices_finais,episodios_seguidos,result,n_vistos);
	return final_escolhido;	
}


void test_big_bang (void)
{
	int episodio;
	scanf ("%d" , &episodio);
	int a[1000];
	int n = ints_get (a);
	int final_escolhido = big_bang (a,n,episodio);
	printf("%d\n", final_escolhido);
}

int main(void)
{
	test_big_bang();
	return 0;
}