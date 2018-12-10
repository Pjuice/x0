#include "head.h"

void expression_stat(int *ptx)
{
	getsym();
	if (sym == semicolon)
	{
		
	}
	else
	{
		expression(ptx);
		if (sym != semicolon)
		{
			error(21);	//»±…ŸΩ· ¯∑÷∫≈
		}
	}
}