#include "head.h"

void term()
{
	if (sym == notsym || sym == lparen || sym == incre || sym == decre || sym == ident || sym == intnum || sym == doublenum
		|| sym == truesym || sym == falsesym)
	{
		factor();
		while (sym == times || sym == slash || sym == modsym)
		{
			enum symbol tempsym = sym;
			getsym();
			factor();
			if (tempsym == times)
			{
				gen(opr, 4, 0);
			}
			else if (tempsym == slash)
			{
				gen(opr, 5, 0);
			}
			else if (tempsym == modsym)
			{
				gen(opr, 6, 0);
			}
		}
	}
	else
	{
		error(15);	//缺少有效标识符
	}
}