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
			error(16);	//ȱ����С����
		}
	}
	else if (sym == incre || sym == decre || sym == ident)
	{
		getsym();
		variable();
	}
	else if (sym == number || sym == truesym || sym == falsesym)
	{
		getsym();
	}
	else
	{
		error(16);	//ȱ����Ч��ʶ��
	}
}