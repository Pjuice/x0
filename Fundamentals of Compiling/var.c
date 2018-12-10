#include "head.h"

void var(int *ptx)
{
	getsym();
	if (sym == ident)
	{
		getsym();
		if (sym == lmbrace)
		{
			expression(ptx);
			if (sym != rmbrace)
			{
				error(20);	//»±…Ÿ”“¿®∫≈]
			}
		}
	}
	else
	{
		error(21);	//»±…Ÿident
	}
}