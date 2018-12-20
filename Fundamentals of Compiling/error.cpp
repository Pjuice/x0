#include "head.h"

void error(int n)
{
	char space[81];
	memset(space, 32, 81);

	space[cc - 1] = 0;

	printf("%s^%d\n", space, n);
	fprintf(foutput, "%s^%d\n", space, n);

	exit(1);
}