#include "head.h"

void dowhile_stat()
{
	if (sym == dosym)
	{
		getsym();
		if (sym == lbrace)
		{
			getsym();
			statement_list();
			if (sym == rbrace)
			{
				getsym();
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
							if (sym == semicolon)
							{
								getsym();
							}
							else
							{
								error(20);	//缺少分号
							}
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
					error(23);	//缺少while字符
				}
			}
			else
			{
				error(24);	//缺少右大括号
			}
		}
		else
		{
			error(25);	//缺少左大括号
		}
	}
	else
	{
		error(26);	//缺少do字符
	}
}