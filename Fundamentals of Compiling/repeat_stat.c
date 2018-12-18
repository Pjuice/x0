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
								error(25);	//ȱ�ٷֺ�
							}
						}
						else
						{
							error(26);	//ȱ����С����
						}
					}
					else
					{
						error(27);	//ȱ����С����
					}
				}
				else
				{
					error(28);	//ȱ��until����
				}
			}
			else
			{
				error(29);	//ȱ���Ҵ�����
			}
		}
		else
		{
			error(30);	//ȱ���������
		}
	}
	else
	{
		error(31);	//ȱ��repeat����
	}

	for (int i = tempbrknum; i < brknum; i++)
	{
		code[brklist[i]].opr1 = codenum;
	}
	brknum = tempbrknum;
}