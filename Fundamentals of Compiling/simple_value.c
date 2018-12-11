#include "head.h"

void simple_value()
{
	if (sym == oddsym)
	{
		getsym();
		addict_expr();
	}
	else if (sym == minus || sym == not || sym == lparen || sym == incre || sym == decre || sym == ident
		|| sym == truesym || sym == falsesym || sym == number)
	{
		getsym();
		addict_expr();
		if (sym == gtr || sym == lss || sym == geq || sym == leq || sym == eql || sym == neq)
		{
			getsym();
			addict_expr();
		}
	}
	else
	{
		error(15);	//缺少有效标识符
	}
}