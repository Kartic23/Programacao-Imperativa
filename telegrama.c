#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>

char* retirar (char *b ,const char* s)
{
	int result = 0;
	for (int i = 0; s[i] != '\0'; i++)
  	  if (s[i] != '_')
  	  	b[result++] = s[i];
  	b[result] = '\0';
  	return b;
}

void test_telegrama (void)
{
	char s[1000];
	while (scanf("%s" , s) != EOF)
	{
		char b[1000];
		retirar(b,s);
		printf("%s\n", b);
	}
}

int main (void)
{
	test_telegrama();
	return 0;
}