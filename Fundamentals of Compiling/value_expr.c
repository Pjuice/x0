#include "head.h"

void value_expr()
{
	if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
		|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym || sym == ident)
	{
		simple_value();
		while (sym == andsym || sym == orsym || sym == xor)
		{
			getsym();
			simple_value();
		}
	}
	else
	{
		error(20);	//缺少有效标识符
	}
}