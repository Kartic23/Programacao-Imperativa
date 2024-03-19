#include<stdio.h>
#include<math.h>
const double desconto = 0.9;


double cantina_1 (double x , int y , int z)

{
	x = round (x * 100) /100;
	return y==0 ? z * x : 100 * x  + cantina_1(x * desconto, y-1 , z) ; 
}
 
int cantina (int r)
{
	double result;
	double x;
	int y;
	int z;
	x = 8;
	y = r/100;
	z = r%100;
	if (r<= 100)
	{
		result = r * 8;
	}
	else 
	{
		result = cantina_1 (x , y ,z);
		result = round ( result * 200)/200; 
	}
	printf("%f\n", result);
	return 0;
}


void test_cantina (void)
{
	int r;
	while (scanf("%d" , &r) != EOF)
	{
		cantina (r);
	}
}



int main (void)
{
	test_cantina ();
	return 0;
}