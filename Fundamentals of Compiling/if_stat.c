#include "head.h"

void if_stat(int* ptx)
{
	getsym();
	if (sym == lparen)
	{
		expression(ptx);
		if (sym == rparen)
		{
			statement(ptx);
			if (sym == elsesym)
			{
				statement(ptx);
			}
			else
			{
				//û��else������ֱ������
			}
		}
		else
		{
			error(16);	// ȱ��������
		}
	}
	else
	{
		error(15);	//ȱ��������
	}
}