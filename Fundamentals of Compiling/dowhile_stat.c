#include "head.h"

void dowhile_stat()
{
	int tempbrknum = brknum;
	int tempctnnum = ctnnum;

	if (sym == dosym)
	{
		getsym();
		if (sym == lbrace)
		{
			getsym();
			int tempos = codenum;
			statement_list();

			for (int i = tempctnnum; i < ctnnum; i++)
			{
				code[ctnlist[i]].opr1 = codenum;
			}
			ctnnum = tempctnnum;

			if (sym == rbrace)
			{
				getsym();
				if (sym == whilesym)
				{
					getsym();
					if (sym == lparen)
					{
						getsym();
						expression();
						gen(jpc, codenum + 2, 0);
						gen(jmp, tempos, 0);
						if (sym == rparen)
						{
							getsym();
							if (sym == semicolon)
							{
								getsym();
							}
							else
							{
								error(20);	//È±ÉÙ·ÖºÅ
							}
						}
						else
						{
							error(21);	//È±ÉÙÓÒÐ¡À¨ºÅ
						}
					}
					else
					{
						error(22);	//È±ÉÙ×óÐ¡À¨ºÅ
					}
				}
				else
				{
					error(23);	//È±ÉÙwhile×Ö·û
				}
			}
			else
			{
				error(24);	//È±ÉÙÓÒ´óÀ¨ºÅ
			}
		}
		else
		{
			error(25);	//È±ÉÙ×ó´óÀ¨ºÅ
		}
	}
	else
	{
		error(26);	//È±ÉÙdo×Ö·û
	}

	for (int i = tempbrknum; i < brknum; i++)
	{
		code[brklist[i]].opr1 = codenum;
	}
	brknum = tempbrknum;

}