#include<stdio.h>

int half (int x)
{
		if ( x <= 1)
	{
		x = 0;
	}
	
	else
	{ 
		x = x-2;
		x = half (x); 
		x = x + 1;
	}
	return x;
}

int main (void)

{
	int x;
	scanf ("%d" , &x);
	int z = half (x);
	printf ("%d\n" , z);
	return 0;
}