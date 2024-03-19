#include <stdio.h>

int sum(int x, int y) 
{ 
	return y == 0  ? x : sum (x+1 , y-1); 
} 

	int twice(int x, int y)
{

    x= sum(x,y);
    return x;
} 

int main(void)
{
   int x;
   scanf("%d", &x);
   int y = x;
   int z = twice(x,y);
   printf("%d\n", z);
   return 0;
}   

