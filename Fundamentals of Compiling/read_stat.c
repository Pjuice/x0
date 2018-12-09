#include "head.h"

void read_stat(int *ptx)
{
	getsym();
	var(ptx);
	if (sym == semicolon)
	{
		
	}
	else
	{
		error(17); //»±…Ÿ∑÷∫≈
	}
}