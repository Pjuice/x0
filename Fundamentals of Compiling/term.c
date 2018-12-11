#include "head.h"

void term()
{
	if (sym == not || sym == lparen || sym == incre || sym == decre || sym == ident || sym == number
		|| sym == truesym || sym == falsesym)
	{
		getsym();
		factor();
		while (sym == times || sym == slash || sym == modsym)
		{
			getsym();
			factor();
		}
	}
	else
	{
		error(15);	//缺少有效标识符
	}
}