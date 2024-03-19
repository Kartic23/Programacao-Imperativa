#include<stdio.h>
const double imc_homem = 31.2;
const double imc_mulher = 32.4;

double obesidade (int s , double w , double h)
{
	double result;
	int result_1;
	result = w / (h * h);
	if ((s==0) & (result >= imc_mulher))
		result_1 = 1;
	else if ((s==1) & (result >= imc_homem))
	{
		result_1 = 1;
	}
	else 
		result_1 = 0;

	printf("%f %d\n", result , result_1 );
	return 0;
}

void test_obesidade (void)
{
	int s;
	double w;
	double h;
	while (scanf ("%d%lf%lf" , &s , &w ,&h) != EOF)
	{
		obesidade(s, w , h);
	} 
}

int main(void)
{
	test_obesidade();
	return 0;
}