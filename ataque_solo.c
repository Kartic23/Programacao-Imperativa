#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_doubles.h"

double doubles_ataque_porta (const double*altura, int n,const double *largura)
{
	int p = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (altura[i] > largura[i])
		{
			p = p + 1;
		}
	}
	return p;
}

double doubles_ataque_janela(const double*altura, int n,const double *largura)
{
	int j = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (altura[i] <= largura[i])
		{
			j = j + 1;
		}
	}
	return j;
}

double doubles_ataque (const double*altura, int n,const double *largura)
{
	int j = doubles_ataque_janela (altura,n,largura);
	int p = doubles_ataque_porta (altura,n,largura);
	printf("%d %d\n", p , j );
	return 0;
}

void test_ints_ataque (void)
{
	double altura[1000];
	double largura[1000];
	int n = doubles_get_two(altura,largura);
	doubles_ataque (altura,n,largura);
}

int main(void)
{
	test_ints_ataque();
	return 0;
}