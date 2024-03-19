#include<stdio.h>

int blue (int c , int a)
{
	int result;
	int y;
	int z;
	int r = 4;
	y = (a+1)/2;
	z = c-a;
	result = ((1+(1+(y-1)*r)) * y) /2;
	if (z != 0)
	{
		result = result + (z)*a - ((z+(a%2))/2) * a;
	}
	return result;
}

int yellow (int c , int a , int result)
{
	int result_1 ;
	result_1 = (c * a) - result;
	return result_1;
}

void test_tiles (void)
{
	int c ;
	int a ;
	while (scanf ("%d%d" , &c , &a) != EOF)
	{
		int result = blue( c , a);
		int result_1 =  yellow ( c , a , result);
		printf("%d %d\n", result , result_1);
	}
}

int main (void)
{
	test_tiles();
	return 0;
}