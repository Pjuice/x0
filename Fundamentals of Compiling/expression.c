#include "head.h"

void expression(int *ptx)
{
	getsym();
	if(sym == sharpsym)
	{
		var(ptx);
		getsym();
		if (sym == becomes)
		{
			expression(ptx);
		}
		else
		{
			error(22);	//缺少赋值号
		}
	}
	else if (sym == minus || sym == lparen || sym == ident || sym == number)
	{
		simple_expr(ptx);
	}
	else
	{
		error(23);	//未找到有效的符号
	}
}