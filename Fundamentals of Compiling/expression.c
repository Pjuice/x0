#include "head.h"

void expression()
{
	if (sym == ident)
	{
		simple_var();
		if (sym == becomes)
		{
			geysym();
			expression();
		}
		else
		{
			error(16);	//缺少赋值号
		}
	}
	else if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
		|| sym == decre || sym == intsym || sym == doublesym || sym == truesym || sym == falsesym)
	{
		value_expr();
	}
	else
	{
		error(14);	//未找到有效符
	}
}