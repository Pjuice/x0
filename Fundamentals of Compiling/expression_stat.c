#include "head.h"

void expression_stat()
{
	if (sym == semicolon)
	{
		getsym();
	}
	else if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == ident
		|| sym == incre || sym == decre || sym == intsym || sym == doublesym || sym == truesym || sym == falsesym)
	{
		expression();
	}
	else
	{
		error(14);	//缺少有效标识符
	}
}