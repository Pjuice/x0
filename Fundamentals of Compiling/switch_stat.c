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
							if (sym == number)
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
							statement_list;
							if (sym == rbrace)
							{
								getsym();
							}
						}
					}
					else if (sym == rbrace)
					{
						getsym();
					}
				}
			}
		}
	}
}