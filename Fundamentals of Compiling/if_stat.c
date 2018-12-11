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
			error(16);	// »±…Ÿ”“¿®∫≈
		}
	}
	else
	{
		error(15);	//»±…Ÿ◊Û¿®∫≈
	}
}