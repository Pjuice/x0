#include "head.h"

void term()
{
	if (sym == not || sym == lparen || sym == incre || sym == decre || sym == ident || sym == intnum || sym == doublenum
		|| sym == truesym || sym == falsesym)
	{
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