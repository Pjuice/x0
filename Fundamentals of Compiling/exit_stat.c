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
				if (sym == rparen)
				{
					getsym();
					if (sym == semicolon)
					{
						getsym();
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