#include "head.h"

void dowhile_stat()
{
	if (sym == dosym)
	{
		getsym();
		if (sym == lbrace)
		{
			getsym();
			statement_list();
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
}