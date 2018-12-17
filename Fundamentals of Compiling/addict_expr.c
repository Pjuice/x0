#include "head.h"

void addict_expr()
{
	if (sym == minus)
	{
		getsym();
		term();
		gen(opr, 1, 0);
		while (sym == plus || sym == minus)
		{
			enum symbol tempsym = sym;
			getsym();
			term();

			if (tempsym == plus)
			{
				gen(opr, 2, 0);
			}
			else if (tempsym == minus)
			{
				gen(opr, 3, 0);
			}
		}
	}
	else if (sym == not || sym == lparen || sym == incre || sym == decre || sym == ident || sym == intnum || sym == doublenum
		|| sym == truesym || sym == falsesym)
	{
		term();
		while (sym == plus || sym == minus)
		{
			enum symbol tempsym = sym;
			getsym();
			term();

			if (tempsym == plus)
			{
				gen(opr, 2, 0);
			}
			else if (tempsym == minus)
			{
				gen(opr, 3, 0);
			}
		}
	}
	else
	{
		error(16);	//缺少有效标识符
	}
}