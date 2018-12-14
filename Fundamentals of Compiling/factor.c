#include "head.h"

void factor()
{
	if (sym == not)
	{
		getsym();
	}
	if (sym == lparen)
	{
		getsym();
		expression();
		if (sym == rparen)
		{
			getsym();
		}
		else
		{
			error(16);	//缺少右小括号
		}
	}
	else if (sym == incre || sym == decre || sym == ident)
	{
		variable();
	}
	else if (sym == intnum || sym == truesym || sym == falsesym || sym == doublenum)
	{
		getsym();
	}
	else
	{
		error(16);	//缺少有效标识符
	}
}