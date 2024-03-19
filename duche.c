#include<stdio.h>
#include<math.h>

int rosa(int a,int c)
{
	return a==0 ? 0 : (2 * a) +((2 * c)-4) + rosa (a-2, c-2);
}

int branco(int a ,int c)
{
	return a==0 ? 0 : (2 * a) +((2 * c)-4) + branco (a-2, c-2);
}

int duche (int l, int w, int b)
{
	int a;
	int c;
	int result;
	int result_1;
	a = l * 10;
	c = w * 10;
	result = rosa (a,c);
	result_1 = branco (a,c);
	printf("%d %d\n", result , result_1);
	return 0;
}

void test_duche (void)
{
	int l;
	int w;
	int b;
	while (scanf("%d%d%d", &l ,&w ,&b) != EOF)
	{
		duche (l,w,b);
	}
}



int main (void)
{
	test_duche ();
	return 0;
}