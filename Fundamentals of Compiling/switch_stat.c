#include "head.h"

void switch_stat()
{
	if (sym == switchsym)
	{
		getsym();
		if (sym == lparen)
		{
			getsym();
			expression();
			if (sym == rparen)
			{
				getsym();
				if (sym == lbrace)
				{
					getsym();
					if (sym == casesym)
					{
						while (sym == casesym)
						{
							getsym();
							if (sym == intnum)
							{
								getsym();
								if (sym == colon)
								{
									getsym();
									statement_list();
								}
								else
								{
									error(17);	//缺少冒号
								}
							}
							else
							{
								error(18);	//缺少number标识符
							}
						}
					}
					if (sym == defaultsym)
					{
						getsym();
						if (sym == colon)
						{
							getsym();
							statement_list();
						}
					}
					if (sym == rbrace)
					{
						getsym();
					}
					else
					{
						error(20);	//缺少右大括号
					}
				}
			}
		}
	}
}