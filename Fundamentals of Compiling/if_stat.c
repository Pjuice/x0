#include "head.h"

void if_stat()
{
	getsym();
	if (sym == lparen)
	{
		expression();
		if (sym == rparen)
		{
			statement();
			if (sym == elsesym)
			{
				statement();
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