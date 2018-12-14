#include "head.h"

void expression()
{
	if (sym == ident)
	{
		backup();
		simple_var();
		if (sym == becomes)
		{
			getsym();
			expression();
		}
		else
		{
			rollback();
			value_expr();	
		}
	}
	else if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
		|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym)
	{
		value_expr();
	}
	else
	{
		error(14);	//Î´ÕÒµ½ÓÐÐ§·û
	}
}