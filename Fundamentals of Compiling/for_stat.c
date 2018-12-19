#include "head.h"

void for_stat()
{
	int tempbrknum = brknum;
	int tempctnnum = ctnnum;

	if (sym == forsym)
	{
		getsym();
		if (sym == lparen)
		{
			getsym();
			if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
				|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym || sym == ident)
			{
				expression();
			}
			if (sym == semicolon)
			{
				getsym();
				int tempcodenum0 = codenum;
				int tempos1;
				int isempty = 1;
				
				if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
					|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym || sym == ident)
				{
					expression();
					isempty = 0;
					tempos1 = codenum;
					gen(jpc, 0, 0);
				}
				else if (sym == semicolon)
				{
					tempos1 = codenum;
				}

				gen(jmp, 0, 0);

				if (sym == semicolon)
				{
					getsym();
					int tempcodenum1 = codenum;

					if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
						|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym || sym == ident)
					{
						expression();
					}
					
					gen(jmp, tempcodenum0, 0);

					if (sym == rparen)
					{
						int tempcodenum2 = codenum;
						getsym();
						statement();

						for (int i = tempctnnum; i < ctnnum; i++)
						{
							code[ctnlist[i]].opr1 = codenum;
						}
						ctnnum = tempctnnum;

						gen(jmp, tempcodenum1, 0);

						if (isempty == 0)
						{
							code[tempos1].opr1 = codenum;
							code[tempos1 + 1].opr1 = tempcodenum2;
						}
						else
						{
							code[tempos1].opr1 = tempcodenum2;
						}
					}

					else
					{
						error(17);	//È±ÉÙÓÒÀ¨ºÅ
					}
				}
				else
				{
					error(18);	//È±ÉÙ·ÖºÅ
				}
			}
			else
			{
				error(18);	//È±ÉÙ·ÖºÅ
			}
		}
		else
		{
			error(19);	//È±ÉÙ×óÀ¨ºÅ
		}
	}
	else
	{
		error(20);	//È±ÉÙfor·ûºÅ
	}

	for (int i = tempbrknum; i < brknum; i++)
	{
		code[brklist[i]].opr1 = codenum;
	}
	brknum = tempbrknum;

}