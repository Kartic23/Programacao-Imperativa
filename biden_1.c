#include<stdio.h>
#include<math.h>

int biden_1 (int v)
{
	return v < 100 ? v : biden_1 (v/10);
}

int concatenate(int x , int v)
{
	if (v>0)
	{
		return concatenate (x*10 , v/10);
	}
	else 

	 return x/100;
}

int biden_2 (int v)
{ 
	int result;
	int x;
	int y;
	if (v>20000000)
	{
		x = biden_1 (v);
		result = x * pow (10,6);
	}
	else if (v>100000000)
	{
		x = biden_1(v);
		result = x * pow(10,8);
	}
	else 
	{
		x = biden_1 (v);
		y = concatenate (x,v);
		result = y;
	}	
	return result;
}

int biden (int v)
{
	int result;
	if (v<100)
	{
		result = v;
	}
	else 
	{
		result = biden_2 (v);
	}
	return result;
}

void test_biden (void)
{
	int v;
	while (scanf("%d" , &v) != EOF)
	{
		int result = biden(v);
		printf("%d\n", result);
	}
}

int main (void)
{
	test_biden ();
	return 0;
}