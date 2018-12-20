#include "head.h"

void factor()
{
	int flag = 0;

	if (sym == notsym)
	{
		flag = 1;
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
			error(16);	//缺少右小括号
		}
	}
	else if (sym == incre || sym == decre || (sym == ident && position(id, fctnum - 1) != -1))
	{
		int offset;
		enum object kind;
		variable(&kind, &offset);
	}
	else if (sym == intnum || sym == truesym || sym == falsesym || sym == doublenum)
	{
		if (sym == intnum)
		{
			gen(lit, intNum, 0);
		}
		else if (sym == doublenum)
		{
			gen(lit, 0, doublenumber);
		}
		else if (sym == truesym)
		{
			gen(lit, 1, 0);
		}
		else if (sym == falsesym)
		{
			gen(lit, 0, 0);
		}
		getsym();
	}
	else
	{
		error(16);	//缺少有效标识符
	}


	if (flag == 1)
	{
		gen(opr, 18, 0);
	}
}