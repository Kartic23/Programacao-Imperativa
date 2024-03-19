#include<stdio.h>
#include<math.h>

const double price_per_kilometer = 0.087;

double price_of_ticket (int k)
{
	double x = k;
	double y;
	x = x * price_per_kilometer;
	x = ceil (x *2)/2;
	y = x * 2 * 0.85;		
	y = ceil (y *2)/2;
	printf("%.2f %.2f\n", x  , y);
	return 0;
}

void test_price_of_ticket (void)
{
	int k;
	while (scanf ("%d" , &k) != EOF)
	{
		price_of_ticket (k);
	}
}

int main (void)
{
	test_price_of_ticket();
	return 0;
}