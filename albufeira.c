#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_doubles.h" 

double doubles_albufeira_1 (const double*a, int i,int p)
{
	return p == 0 ? 0 : a[i] + doubles_albufeira_1 (a,i+12,p-1);
}

double doubles_albufeira (const double*a, int n)
{
	double d[1000];
	int m = 0;
	double anos = (n+1)/12;//calcula quantos anos foram introduzidos na consola//
	double total;
	double media;
	int k = 12;
	for (int i = 0; i < k; i++)
	{
		int p = anos - 1 ;
		total = doubles_albufeira_1 (a,i,p); //calcula a soma de todos os anos de um certo mes//
		media = total / p;//faz a media do total//
		int ultimo = i+((anos-1)*12);//o ultimo significa os meses do ultimo ano//
		if (a[ultimo] < media)
		{
			d[m++] = i+1;
		}
	}
	doubles_println_special (d,m);
	return 0;
}

void test_albufeira (void)
{
	double a[1000];
	int n = doubles_get (a);
	doubles_albufeira (a,n);
}



int main (void)
{
	test_albufeira ();
	return 0;
}