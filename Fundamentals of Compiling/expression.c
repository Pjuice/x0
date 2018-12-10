#include "head.h"

void expression()
{
	if (sym == ident)
	{
		simple_var();
	}
	else if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
		|| sym == decre || sym == intsym || sym == doublesym || sym == truesym || sym == falsesym)
	{
		value_expr();
	}
	else
	{
		error(14);	//Î´ÕÒµ½ÓÐÐ§·û
	}
}