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
			error(22);	//ȱ�ٸ�ֵ��
		}
	}
	else if (sym == minus || sym == lparen || sym == ident || sym == number)
	{
		simple_expr(ptx);
	}
	else
	{
		error(23);	//δ�ҵ���Ч�ķ���
	}
}