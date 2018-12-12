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
				error(21);	//缺少右小括号
			}
		}
		else
		{
			error(22);	//缺少左小括号
		}
	}
	else
	{
		error(23);	//缺少while标识符
	}
}