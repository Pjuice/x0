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
								error(20);	//ȱ�ٷֺ�
							}
						}
						else
						{
							error(21);	//ȱ����С����
						}
					}
					else
					{
						error(22);	//ȱ����С����
					}
				}
				else
				{
					error(23);	//ȱ��while�ַ�
				}
			}
			else
			{
				error(24);	//ȱ���Ҵ�����
			}
		}
		else
		{
			error(25);	//ȱ���������
		}
	}
	else
	{
		error(26);	//ȱ��do�ַ�
	}

	for (int i = tempbrknum; i < brknum; i++)
	{
		code[brklist[i]].opr1 = codenum;
	}
	brknum = tempbrknum;

}