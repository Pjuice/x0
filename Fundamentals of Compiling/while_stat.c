#include "head.h"

void while_stat()
{
	getsym();
	if (sym == lparen)
	{
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
		error(18);	//ȱ��������
	}
}