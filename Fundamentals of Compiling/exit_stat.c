#include "head.h"

void exit_stat()
{
	if (sym == exitsym)
	{
		getsym();
		if (sym == lparen)
		{
			getsym();
			if (sym == intnum)
			{
				getsym();
				gen(lit, intnum, 0);
				if (sym == rparen)
				{
					getsym();
					if (sym == semicolon)
					{
						getsym();
						gen(opr, 7, 0);	//ִ��c�����е�exit����
					}
					else
					{
						error(18);	//ȱ�ٽ����ֺ�
					}
				}
				else
				{
					error(19);	//ȱ����С����	
				}
			}
			else
			{
				error(20);	//ȱ�����ֱ�ʶ��
			}
		}
		else
		{
			error(21);	//ȱ����С����
		}
	}
	else
	{
		error(22);	//ȱ��exit��ʶ��
	}
}