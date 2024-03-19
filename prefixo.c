#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>



char* str_prefix (const char* s, int x ,char* result)
{
	int m = 0;
	for (int i = 0; s[i] != '\0' ; ++i)
	{
		if (i < x)
			result[m++] = s[i];
	}
	result[m] = '\0';
	return result;
}



void test_prefixo (void)
{
	char s[1000];
	int x;
	while (scanf("%s%d" , s, &x) != EOF )
	{
		char result[1000];
		str_prefix(s,x,result);
		printf("{%s}\n", result );
	}
}


int main (void)
{
	test_prefixo();
	return 0;
}