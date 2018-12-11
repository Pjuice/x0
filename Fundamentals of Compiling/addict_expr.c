#include "head.h"

void addict_expr()
{
	if (sym == minus)
	{
		getsym();
		term();
		while (sym == plus || sym == minus)
		{
			getsym();
			term();
		}
	}
	if (sym == not || sym == lparen || sym == incre || sym == decre || sym == ident || sym == number
		|| sym == truesym || sym == falsesym)
	{
		term();
		while (sym == plus || sym == minus)
		{
			getsym();
			term();
		}
	}
	else
	{
		error(16);	//缺少有效标识符
	}
}