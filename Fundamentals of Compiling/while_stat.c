#include "head.h"

void while_stat()
{
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
				statement();
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
		error(23);	//ȱ��while��ʶ��
	}
}