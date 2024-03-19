#include<stdio.h>
#include<math.h>
const double feet_to_inches = 12.0;
const double sixteenth_of_an_inch = 16.0;
const double inches_to_meters = 0.0254;

int nba (int x , int y , int w )
{
	double result;  
	result = x * feet_to_inches + y + w/sixteenth_of_an_inch;
	result = result * inches_to_meters;
	result = round (result * 0.2 * 1000 ) / (0.2 * 1000);
	printf("%0.6f\n", result); 
	return 0;
}


void test_nba (void)
{
	int x;
	int y;
	int w;
		while (scanf ("%d%d%d" , &x , &y, &w ) != EOF)
	{
		nba (x,y,w);
	}
}

int main (void)
{
	test_nba();
	return 0;
}