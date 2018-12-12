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
						error(18);	//缺少结束分号
					}
				}
				else
				{
					error(19);	//缺少右小括号	
				}
			}
			else
			{
				error(20);	//缺少数字标识符
			}
		}
		else
		{
			error(21);	//缺少左小括号
		}
	}
	else
	{
		error(22);	//缺少exit标识符
	}
}