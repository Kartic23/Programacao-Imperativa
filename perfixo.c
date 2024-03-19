#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>


int str_is_prefix (char *a ,char*b)
{
	int i = 0;
	int result = 0;
	while (a[i] != '\0')
	{
		if (a[i] == b[i])
			result++;
		i++;
	}
	if (result == i)
		result = 1;
	else
		result = 0;
	return result;
}

void test_prefixo (void)
{	
    char a[1000];
	char b[1000];
	while (scanf("%s%s",a,b)  != EOF)
	{
		int result = str_is_prefix (a,b);
	    if (result == 1 || a[0] == '\0')
		    printf("YES\n");
	    else
		    printf("NO\n");
	}
}

int main (void)
{
	test_prefixo();
	return 0;
}

