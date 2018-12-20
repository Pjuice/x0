#include "head.h"

void while_stat()
{
	int tempbrknum = brknum;
	int tempctnnum = ctnnum;

	if (sym == whilesym)
	{
		getsym();
		if (sym == lparen)
		{
			int tempos1 = codenum;
			getsym();
			expression();
			if (sym == rparen)
			{
				int tempos2 = codenum;

				gen(jpc, 0, 0);
				
				getsym();
				statement();

				for (int i = tempctnnum; i < ctnnum; i++)
				{
					int pos = ctnlist[i];
					code[pos].opr1 = codenum;
				}
				ctnnum = tempctnnum;

				gen(jmp, tempos1, 0);
				code[tempos2].opr1 = codenum;
			}
			else
			{
				error(21);	//缺少右小括号
			}
		}
		else
		{
			error(22);	//缺少左小括号
		}
	}
	else
	{
		error(23);	//缺少while标识符
	}

	for (int i = tempbrknum; i < brknum; i++)
	{
		int pos = brklist[i];
		code[pos].opr1 = codenum;
	}
	brknum = tempbrknum;

}