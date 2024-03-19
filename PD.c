#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

//-------------------------------------------------------------------// A = Penalti
int lado (int a, int b)
{
	return( a * b >= 0 ? 1 : 0 );
	//Se for para a direita ou para o meio, fica 1, mas se for para a esquerda fica 0//
}

int ints_lado (const int*a , int n)
{
	int result = 0;
	while (result < n  && lado (a[0] , a[result])) 
	{
        result++;
	}
    return result;
}


int ints_penalti (const int*a, int n, int *b)
{
	int i = 0;
	int m = 0;
	int result = 0;
	while ( i < n )
	{
		result = ints_lado(a + i , n - i);
		b[m++] = result;
		i = i + result;
	}
	return m;
}

void test_ints_penalti (void)
{
	int a[1000];
	int b[1000];
	int n = ints_get (a);
	int m = ints_penalti (a,n,b);
	ints_println_basic (b,m);
}

//---------------------------------------------------------------------------------------------------------// B = Dezembro


double dezembro (const double*a, int n)
{
	int i = 0;
	int dias = 0;
	while (i < 31 )
	{
		if (a[i] <= 0)
		{
			dias++;
		}
		i++;
	}
	return dias;
}


double doubles_dezembro (const double*a, int n, int*b)
{
	int i = 0;
	int dias = 0;
	int anos = (n/31);
	int result = 0;
	while (i < n)
	{
		dias = dezembro (a + i , n - i);
		if (dias >= 3)
		{
			b[result] = anos;
			result++;
		}
		i = i + 31;
		anos--;
	}
	return result;
}

void test_doubles_dezembro (void)
{
	double a[4000];
	int b [1000];
	int n = doubles_get (a);
	int m = doubles_dezembro (a,n,b);
	if (m == 0)
	{
		printf("%d\n", m);
	}
	else
	{
		printf("%d %d\n", m , b[m-1]);
	}
}



//--------------------------------------------------------------------------------------------------------//C = penico



int ints_maximo_1 (int seguidos_b ,int result)
{
	if (seguidos_b < result)
	{
		seguidos_b = result;
	}
	return seguidos_b;
}

int ints_maximo (int seguidos_a, int result)
{
	if (seguidos_a < result)
	{
		seguidos_a = result;
	}
	return seguidos_a;
}


double doubles_consecutivos_a (const double *a, int n)
{
	int result = 0;
	int seguidos_a = 0;
	int i = 0;
	while (i < n)
	{
		if (a[i] > 0)
		{
			result++;
		}
		else
		{
			seguidos_a = ints_maximo (seguidos_a, result);
			result = 0;
		}
		i++;
	}
	return seguidos_a;
}

double doubles_consecutivos_b (const double *b, int n)
{
	int result = 0;
	int seguidos_b = 0;
	int i = 0;
	while (i < n)
	{
		if (b[i] > 0)
		{
			result++;
		}
		else
		{
			seguidos_b = ints_maximo_1 (seguidos_b, result);
			result = 0;
		}
		i++;
	}
	return seguidos_b;
}

double doubles_chuva_b (const double *b, int n)
{
	int dias = 0;
	int i = 0;
	while (i < n)
	{
		if (b[i] > 0)
		{
			dias++;
		}
		i++;
	}
	return dias;
}

double doubles_chuva_a (const double *a, int n)
{
	int dias = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (a[i] > 0)
			dias++;
	}
	return dias;
}

double doubles_maxima_b (const double*b, int n)
{
	double max_b = 0;
	int i = 0;
	while (i < n)
	{
		if (b[i] > max_b)
		{
			max_b = b[i];
		}
		i++;
	}
	return max_b;
}

double doubles_maxima_a (const double*a, int n)
{
	double max_a = 0;
	int i = 0;
	while (i < n)
	{
		if (a[i] > max_a)
		{
			max_a = a[i];
		}
		i++;
	}
	return max_a;
}

double doubles_total_b (const double*b, int n)
{
	double total_b = 0;
	int i = 0;
	while (i < n)
	{
		total_b = total_b + b[i];
		i++;
	} 
	return total_b;
}

double doubles_total_a (const double*a, int n)
{
	double total_a = 0;
	int i = 0;
	while (i < n)
	{
		total_a = total_a + a[i];
		i++;
	} 
	return total_a;
}


void test_doubles_penico (void)
{
	double a[1000];
	double b[1000];
	int n = doubles_get_two (a,b);
	double total_a = doubles_total_a (a,n);
	double total_b = doubles_total_b (b,n);
	double max_a = doubles_maxima_a (a,n);
	double max_b = doubles_maxima_b (b,n);
	int dias_a = doubles_chuva_a (a,n);
	int dias_b = doubles_chuva_b (b,n);
	int seguidos_a = doubles_consecutivos_a (a,n);
	int seguidos_b = doubles_consecutivos_b (b,n);
	printf("%0.1f %0.1f\n", total_a , total_b);
	printf("%0.1f %0.1f\n", max_a , max_b);
	printf("%d %d\n", dias_a , dias_b);
	printf("%d %d\n", seguidos_a , seguidos_b );
}

//-------------------------------------------------------------------------------------------------------------// D = rampa


int ints_comprimento_total (const int* d , int k)
{
	return k == 0 ? 0 : d[0] + ints_comprimento_total(d+1, k-1);
}

int ints_comprimento (const int*a ,int n)
{
	int comprimento = 0;
	while  ( comprimento < n && a[comprimento+1] > a[comprimento])
	{
		comprimento++;
	}
	return comprimento;
}

int ints_rampa (const int*a, int n, int x ,int *d)
{
	int i = 0;
	int k = 0;
	int comprimento = 0;
	while (i < n )
	{
		comprimento = ints_comprimento (a + i ,n - i);
		if (comprimento >= x)
		{
			d[k++] = comprimento;
		}
		i = i + comprimento + 1;
	}
	return k;
}

void test_ints_rampa (void)
{
	int x;
	scanf ("%d", &x);
	int a[1000];
	int d[1000];
	int n = ints_get (a);
	int k = ints_rampa (a,n,x,d);
	int total = ints_comprimento_total (d,k);
	printf("%d %d\n", k , total);
}

//--------------------------------------------------------------------// E = recessao


int ints_anos_seguidos (const int*a ,int n)
{
	int result = 0;
	while (result < n -1   && a[result] > a[result+1] )
	{
		result++;
	}
	return result+1;
}

int ints_recessao (const int*a , int n, int*indices, int*anos_seguidos)
{
	int i = 0;
	int m = 0;
	int anos = 0;
	while ( i < n )	
	{
		anos = ints_anos_seguidos (a+i,n-i);
		if (anos  >= 3)
		{
			indices[m] = i;
			anos_seguidos[m++]= anos;
		}
		i = i + anos;
	}
	return m;
}

void test_recessao (void)
{
	int a[1000];
	int indices[1000];
	int anos_seguidos[1000];
	int n = ints_get (a);
	int m = ints_recessao (a,n,indices,anos_seguidos);
	printf("%d\n", m );
	ints_print_two (indices,anos_seguidos,m);
}


//-------------------------------------------------------------// F = Big Bang

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
	while ( i < m  && a[i] + 1 == a[i+1])
	{
		i++;
	}
	return i+1;
}

int ints_contagem (int* n_vistos, int m, int*indices_finais, int*episodios_seguidos)
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
	int indices_finais[1000];//array que tem os primeiros indices da sequencia do array não vistos// 
	int episodios_seguidos[1000];//array que tem os numeros dos episodios consecutivos//
	int result = ints_contagem (n_vistos,m,indices_finais,episodios_seguidos);
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


int main(int argc, char **argv)
{
	int x = 'F';
	if (argc > 1)
		x = *argv[1];
	if ( x == 'A')
		test_ints_penalti();
	else if ( x== 'B')
		test_doubles_dezembro();
	else if ( x == 'C')
	    test_doubles_penico();
	else if ( x == 'D')
		test_ints_rampa();
	else if ( x == 'E')
		test_recessao();
	else if ( x == 'F')
		test_big_bang();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	else 
		printf("%s: Invalid option.\n", argv[1]);
  return 0;
}
