#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<string.h>


int str_find (const char*s , char x)
{
	for (int i = 0 ; s[i] != '\0' ; i++)
		if (s[i]==x)
			return i;
	return -1;
}

int str_count(const char* s, char x)
{
	int result = 0;
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] == x)
			result++;	
	return result;
}


// Copy second argument to first argument. Return (the address of) the first argument. 
char* str_cpy(char *r, const char *t)
{
	int n = 0;
	for (int i = 0; t[i]; i++)
		r[n++] = t[i];
	r[n] = '\0';   
	return r; 
}

// Length of the string, measured in number of memory bytes used. 
int str_len(const char *s)
{   
	int result = 0;
	while (s[result] != '\0')
		result++;
	return result;
}


// Are the two strings equal? 
int str_equal(const char *s, const char *t) 
{   
	int i = 0;
	while (s[i] && t[i] && s[i] == t[i])
		i++;  
	return s[i] == '\0' && t[i] == '\0'; 
}