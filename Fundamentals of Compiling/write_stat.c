#include "head.h"

void write_stat(int *ptx)
{
	getsym();
	expression(ptx);
	if (sym != semicolon)
	{
		error(21);	//½áÊøÈ±ÉÙ·ÖºÅ
	}
}