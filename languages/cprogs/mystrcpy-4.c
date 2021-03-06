#include<stdio.h>
#define MAXLINE 1000

int getline(char s[],int lim);
void mystrcpy(char *s,char *t);

int main(void)
{
	char s[MAXLINE],t[MAXLINE];

	putchar('t');
	putchar(':');
	getline(t,MAXLINE);
	
	mystrcpy(s,t);

	putchar('s');
	putchar(':');

	printf("%s",s);

	return 0;
}

int getline(char s[],int lim)
{
	int c,i;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c != '\n'; ++i)
		s[i] = c;

	if( c == '\n')
	{
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';

	return i;
}

/* strcpy : pointer version 2 */

void mystrcpy(char *s,char *t)
{
	while((*s++ = *t++))
		;
}

	
		
	
