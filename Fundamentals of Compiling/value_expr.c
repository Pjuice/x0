#include "head.h"

void value_expr()
{
	if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
		|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym || sym == ident)
	{
		simple_value();
		while (sym == andsym || sym == orsym || sym == xor)
		{
			enum symbol tempsym = sym;
			getsym();
			simple_value();

			if (tempsym == andsym)
			{
				gen(opr, 16, 0);
			}
			else if (tempsym == orsym)
			{
				gen(opr, 17, 0);
			}
			else if (tempsym == xor)
			{
				gen(opr, 18, 0);
			}
		}
	}
	else
	{
		error(20);	//缺少有效标识符
	}
}