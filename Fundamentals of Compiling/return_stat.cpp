#include "head.h"

void return_stat()
{
	if (sym == returnsym)
	{
		getsym();
		if (sym == minus || sym == notsym || sym == lparen || sym == incre || sym == decre || sym == ident
			|| sym == truesym || sym == falsesym || sym == intnum || sym == doublenum || sym == oddsym)
		{
			value_expr();
		}

		if (sym == semicolon)
		{
			getsym();
			gen(opr, 0, fctnum - 1);
		}
		else
		{
			error(30);	//缺少结束分号
		}
	}
	else
	{
		error(31);	//缺少return符号
	}
}