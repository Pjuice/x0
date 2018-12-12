#include "head.h"

void if_stat()
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
			if (sym == elsesym)
			{
				getsym();
				statement();
			}
		}
		else
		{
			error(16);	// È±ÉÙÓÒÀ¨ºÅ
		}
	}
	else
	{
		error(15);	//È±ÉÙ×óÀ¨ºÅ
	}
}