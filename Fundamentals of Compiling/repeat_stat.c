#include "head.h"

void repeat_stat()
{
	if (sym == repeatsym)
	{
		getsym();
		if (sym == lbrace)
		{
			getsym();
			statement_list();
			if (sym == rbrace)
			{
				getsym();
				if (sym == untilsym)
				{
					getsym();
					if (sym == lparen)
					{
						getsym();
						expression;
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
}