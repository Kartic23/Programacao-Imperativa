#include<stdio.h>
int concatenate( int x , int y )
{
	
	if ( y > 0)
	{
		x = x * 10;
		return concatenate (x , y/10);
	}
	
	else

	 return x;
	

}

int main (void)
{
	int x ;
	int y ;
	scanf("%d%d", &x , &y);
	int z = concatenate (x , y);
	z = z + y ;
	printf("%d\n",  z);
	return 0;
}

