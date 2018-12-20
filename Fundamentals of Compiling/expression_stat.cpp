#include "head.h"

void expression_stat()
{
	if (sym == semicolon)
	{
		getsym();
	}
	else if (sym == oddsym || sym == minus || sym == notsym || sym == lparen || sym == ident
		|| sym == incre || sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym)
	{
		expression();
	}
	else
	{
		error(14);	//缺少有效标识符
	}
}