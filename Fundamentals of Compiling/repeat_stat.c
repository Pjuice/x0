#include "head.h"

void repeat_stat()
{
	if (sym == repeatsym)
	{
		getsym();
		if (sym == lbrace)
		{
			getsym();
			statement_list();
			if (sym == rbrace)
			{
				getsym();
				if (sym == untilsym)
				{
					getsym();
					if (sym == lparen)
					{
						getsym();
						expression;
						if (sym == rparen)
						{
							getsym();
							if (sym == semicolon)
							{
								getsym();
							}
							else
							{
								error(25);	//»±…Ÿ∑÷∫≈
							}
						}
						else
						{
							error(26);	//»±…Ÿ”“–°¿®∫≈
						}
					}
					else
					{
						error(27);	//»±…Ÿ◊Û–°¿®∫≈
					}
				}
				else
				{
					error(28);	//»±…Ÿuntil∑˚∫≈
				}
			}
			else
			{
				error(29);	//»±…Ÿ”“¥Û¿®∫≈
			}
		}
		else
		{
			error(30);	//»±…Ÿ◊Û¥Û¿®∫≈
		}
	}
	else
	{
		error(31);	//»±…Ÿrepeat∑˚∫≈
	}
}