#include "getInteger.h"
int getInteger(char a)
{
	int b;
	a = getch();
	char *p = &a;
	b = atoi(p);
	return b;
}