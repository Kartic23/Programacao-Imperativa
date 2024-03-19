#include<stdio.h>

int sum_positive_interegers (int x)
{
	return x==0 ? 0 : x + sum_positive_interegers (x-1);
}

int somersaults (int g)

{
	int x;
	int y;
	int z;
	int result;
	x = g%4;
	y = g/4;
	z = sum_positive_interegers (x);
	result = y * 8 + z;
	printf("%d\n", result );
	return 0;
}

void test_somersaults (void)
{
	int g;
	while ( scanf ("%d" , &g ) != EOF)
	{
		somersaults (g);
	}
}
int main ()
{
	test_somersaults ();
	return 0;
}