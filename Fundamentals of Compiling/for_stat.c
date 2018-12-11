#include "head.h"

void for_stat()
{
	if (sym == forsym)
	{
		getsym();
		if (sym == lparen)
		{
			getsym();
			expression();
			if (sym == semicolon)
			{
				getsym();
				expression();
				if (sym == semicolon)
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
						error(17);	//»±…Ÿ”“¿®∫≈
					}
				}
				else
				{
					error(18);	//»±…Ÿ∑÷∫≈
				}
			}
			else
			{
				error(18);	//»±…Ÿ∑÷∫≈
			}
		}
		else
		{
			error(19);	//»±…Ÿ◊Û¿®∫≈
		}
	}
	else
	{
		error(20);	//»±…Ÿfor∑˚∫≈
	}
}