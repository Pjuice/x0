#include "head.h"

void repeat_stat()
{
	int tempbrknum = brknum;
	int tempctnnum = ctnnum;

	if (sym == repeatsym)
	{
		getsym();
		if (sym == lbrace)
		{
			getsym();
			int pos = codenum;
			statement_list();

			for (int i = tempctnnum; i < ctnnum; i++)
			{
				code[ctnlist[i]].opr1 = codenum;
			}
			ctnnum = tempctnnum;
			if (sym == rbrace)
			{
				getsym();
				if (sym == untilsym)
				{
					getsym();
					if (sym == lparen)
					{
						getsym();
						expression();
						gen(jpc, pos, 0);

						if (sym == rparen)
						{
							getsym();
							if (sym == semicolon)
							{
								getsym();
							}
							else
							{
								error(25);	//È±ÉÙ·ÖºÅ
							}
						}
						else
						{
							error(26);	//È±ÉÙÓÒĞ¡À¨ºÅ
						}
					}
					else
					{
						error(27);	//È±ÉÙ×óĞ¡À¨ºÅ
					}
				}
				else
				{
					error(28);	//È±ÉÙuntil·ûºÅ
				}
			}
			else
			{
				error(29);	//È±ÉÙÓÒ´óÀ¨ºÅ
			}
		}
		else
		{
			error(30);	//È±ÉÙ×ó´óÀ¨ºÅ
		}
	}
	else
	{
		error(31);	//È±ÉÙrepeat·ûºÅ
	}

	for (int i = tempbrknum; i < brknum; i++)
	{
		code[brklist[i]].opr1 = codenum;
	}
	brknum = tempbrknum;
}