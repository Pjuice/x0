#include "head.h"

void for_stat()
{
	if (sym == forsym)
	{
		getsym();
		if (sym == lparen)
		{
			getsym();
			expression();
			if (sym == semicolon)
			{
				getsym();
				expression();
				if (sym == semicolon)
				{
					getsym();
					expression();
					if (sym == rparen)
					{
						getsym();
						statement();
					}
					else
					{
						error(17);	//ȱ��������
					}
				}
				else
				{
					error(18);	//ȱ�ٷֺ�
				}
			}
			else
			{
				error(18);	//ȱ�ٷֺ�
			}
		}
		else
		{
			error(19);	//ȱ��������
		}
	}
	else
	{
		error(20);	//ȱ��for����
	}
}