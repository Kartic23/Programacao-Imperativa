
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>


int main(void)
{
	char  i[1000];
	scanf("%s", i);
	char p[1000];
	scanf("%s", p);
	int result = i[0] + p[0];
	printf("%d\n", result);
	return 0;
}