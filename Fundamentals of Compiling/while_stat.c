#include "head.h"

void while_stat(int *ptx)
{
	getsym();
	if (sym == lparen)
	{
		expression(ptx);
		if (sym == rparen)
		{
			statement(ptx);
		}
		else
		{
			error(17);	//ȱ��������
		}
	}
	else
	{
		error(18);	//ȱ��������
	}
}