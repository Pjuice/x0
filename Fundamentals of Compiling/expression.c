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
			error(16);	//ȱ�ٸ�ֵ��
		}
	}
	else if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
		|| sym == decre || sym == intsym || sym == doublesym || sym == truesym || sym == falsesym)
	{
		value_expr();
	}
	else
	{
		error(14);	//δ�ҵ���Ч��
	}
}