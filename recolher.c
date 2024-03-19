#include<stdio.h>
#include<math.h>


double recolher_1(int z , double n, double k)
{
	return z==0 ? k * (0.1 *(n*n)): 60 * (0.1 * (n * n)) + recolher_1(z-1 ,n+1,k);
}

double recolher_2 (int z ,double n , double k)
{
	double result;
	if (z==0)
	{
		result = k * 0.1;
	}
	else
	{
		result = recolher_1 (z,n,k);
	}
	return result;
}


double recolher (int h ,int m , int s, int t,int a, int b)
{
	double result;
	double x;
	double y;
	double w;
	int z;
	double k;
	int c;
	int d;
	int n = 1;
	x = (h * 60) + m;//converte para minutos a hora de inicio//
	y = (s * 60) + t;//converte para minutos a hora de final//
	a = (a * 60) + b;//converte para minutos a hora que foi apanhado//
	w = (y - x)/2;//faz o ponto medio entre a hora de inicio e a hora do fim//
	w = round (w * 0.2)/0.2;
	w = x + w;//hora em minutos do meio entre a  hora de inicio e a hora do fim//
	if (a<=w)
	{
		c = a - x;
		z = c/60;
		k = c%60;
		result = recolher_2 (z,n,k); 
	}
	else
	{
		d = y - a;
		z = d/60;
		k = d%60;
        result = recolher_2 (z,n,k);
	}
	return result;
}

void test_recolher (void)
{
	int h;
	int m;
	int s;
	int t;
	int a;
	int b;
	scanf ("%d%d%d%d" , &h ,&m ,&s,&t);
	while (scanf("%d%d", &a,&b) != EOF)
	{
		double result = recolher (h,m,s,t,a,b);
		printf("%.2f\n", result);
	}
}



int main (void)
{
	test_recolher ();
	return 0;
}