#include<stdio.h>

int sum (int x, int y, int n)
{   
	return y < n  ? 0 :  x * x + sum (x+1 , y-1 , n );
} 

int main ( void )
{
   int x;
   int y;
   scanf ("%d%d", &x , &y );
   int n = x ;
   int z = sum ( x , y, n);
   printf("%d\n", z);
   return 0;
}   