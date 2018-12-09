#include "head.h"

void enter(enum object k, int* ptx)
{
	(*ptx)++;
	strcpy(table[(*ptx)].name, id);
	table[(*ptx)].kind = k;
}

