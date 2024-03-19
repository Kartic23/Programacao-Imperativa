#include<stdio.h>
int reforma_1 (int x ,int m)

{
	int result;
	int result_1;
	if ((x==66) & (m <4))
	{
		result = 66;
		result_1 = 4;
		printf("%d %d\n", result , result_1);
	}
	else if  ((x>=66) & (x<70))
	{
		result = x;
		result_1 = m;
		printf("%d %d\n", result , result_1);
	}
	else
	{
		result = 70;
		result_1 = 0;
		printf("%d %d\n", result , result_1);		
	}
	return 0;
}
int reforma (int a , int m)
{
	int x;
	int result;
	int result_1;
	x = a + 40;
	if (x <= 65)
	{
		result = 66;
		result_1 = 4;
		printf("%d %d\n", result , result_1);
	}
	else
	{
		reforma_1 (x , m);
	}  
	return 0;
}


void test_reforma (void)
{
	int a;
	int m;
	while (scanf("%d%d" , &a , &m) != EOF)
	{
		reforma (a,m);
	}
}

int main (void)
{
	test_reforma ();
	return 0;
}