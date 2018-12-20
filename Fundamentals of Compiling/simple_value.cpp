#include "head.h"

void simple_value()
{
	if (sym == oddsym)
	{
		getsym();
		addict_expr();
		gen(opr, 20, 0);
	}
	else if (sym == minus || sym == notsym || sym == lparen || sym == incre || sym == decre || sym == ident
		|| sym == truesym || sym == falsesym || sym == intnum || sym == doublenum)
	{
		addict_expr();
		if (sym == gtr || sym == lss || sym == geq || sym == leq || sym == eql || sym == neq)
		{
			enum symbol tempsym = sym;
			getsym();
			addict_expr();
			if (tempsym == gtr)
			{
				gen(opr, 12, 0);
			}
			else if (tempsym == lss)
			{
				gen(opr, 10, 0);
			}
			else if (tempsym == geq)
			{
				gen(opr, 11, 0);
			}
			else if (tempsym == leq)
			{
				gen(opr, 13, 0);
			}
			else if (tempsym == eql)
			{
				gen(opr, 8, 0);
			}
			else if (tempsym == neq)
			{
				gen(opr, 9, 0);
			}
		}
	}
	else
	{
		error(15);	//缺少有效标识符
	}
}