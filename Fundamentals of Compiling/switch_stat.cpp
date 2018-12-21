#include "head.h"

void switch_stat()
{
	int tempbrknum = brknum;

	if (sym == switchsym)
	{
		getsym();
		if (sym == lparen)
		{
			getsym();
			expression();
			if (sym == rparen)
			{
				getsym();
				if (sym == lbrace)
				{
					getsym();
					int tempos1 = -1;
					int tempos2 = -1;
					if (sym == casesym)
					{
						while (sym == casesym)
						{
							if (tempos1 != -1)
							{
								code[tempos1].opr1 = codenum;
							}
							getsym();
							if (sym == intnum)
							{
								gen(lit, intNum, 0);
								gen(opr, 21, 0); 
								gen(jpc, 0, 0);
								tempos1 = codenum - 1;

								getsym();
								if (sym == colon)
								{
									getsym();
									if (tempos2 != -1)
									{
										code[tempos2].opr1 = codenum; 
									}
									statement_list();
									gen(jmp, 0, 0);
									tempos2 = codenum - 1;
								}
								else
								{
									error(17);	//ȱ��ð��
								}
							}
							else
							{
								error(18);	//ȱ��number��ʶ��
							}
						}
					}

					if (tempos1 != -1)
					{
						code[tempos1].opr1 = codenum; /* backfill */
					}

					if (tempos2 != -1)
					{
						code[tempos2].opr1 = codenum; /* backfill */
					}

					if (sym == defaultsym)
					{
						getsym();
						if (sym == colon)
						{
							getsym();
							statement_list();
						}
						else
						{
							error(30);	//ȱ��colon����
						}
					}
					if (sym == rbrace)
					{
						getsym();
					}
					else
					{
						error(20);	//ȱ���Ҵ�����
					}
				}
				else
				{
					error(34);	//ȱ���������
				}
			}
			else 
			{
				error(33);	//ȱ����С����
			}
		}
		else
		{
			error(32);	//ȱ����С����
		}
	}
	else
	{
		error(31);	//ȱ��switch
	}
	for (int i = tempbrknum; i < brknum; i++)
	{
		code[brklist[i]].opr1 = codenum;
	}
	brknum = tempbrknum;
}