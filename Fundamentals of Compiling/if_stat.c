#include "head.h"

void if_stat()
{
	getsym();
	if (sym == lparen)
	{
		getsym();
		expression();


		int tempos1 = codenum;
		gen(jpc, 0, 0);

		if (sym == rparen)
		{
			getsym();
			statement();

			if (sym == elsesym)
			{
				int tempos2 = codenum;
				gen(jmp, 0, 0);
				code[tempos1].opr1 = codenum;

				getsym();
				statement();
				code[tempos2].opr1 = codenum;
			}
			else
			{
				code[tempos1].opr1 = codenum;
			}
		}
		else
		{
			error(16);	// »±…Ÿ”“¿®∫≈
		}
	}
	else
	{
		error(15);	//»±…Ÿ◊Û¿®∫≈
	}
}