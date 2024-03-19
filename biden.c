#include<stdio.h>
#include<math.h>

int biden_1 (int v)
{
	return v < 100 ? v : biden_1 (v/10);
}

int concatenate(int x , int v)
{
	if (v>=100) 
	{
		return concatenate (x*10 , v/10);
	}
	else 

	 return x;
}


int biden (int v)
{
	int result;
	int x;
	int w;
	if (v<=100)
	{
		result = v;
	}
	else 
	{
		x = biden_1 (v);
		w = concatenate (x,v);
		result = w;
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