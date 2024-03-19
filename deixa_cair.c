#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>


int extra(const char*s)
{
	int result = 0;
	for (int i = 0; s[i] != '\0' ; ++i)
	{
		result++;
	}
	return  result;
}

char* str_drop (char*r, const char*s , int x)
{
	int m = 0;
	int k = extra(s);
	if (x < 0)
		x = 0;
	while (x <= k && s[x] )
	{
		r[m++] = s[x++];
	}
	r[m] = '\0';
	return r;
}

void test_deixa_cair (void)
{
	char a[1000];
	int x;
	char r[1000];
	while (scanf("%s%d" , a, &x) != EOF)
	{
		str_drop(r,a,x);
		printf("{%s}\n", r );
	}
}

int main(void)
{
	test_deixa_cair();
	return 0;
}