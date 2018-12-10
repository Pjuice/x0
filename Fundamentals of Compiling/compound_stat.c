#include "head.h"

void compound_stat(int *ptx)
{
	getsym();
	if (sym == lbrace)
	{
		statement_list(ptx);
		if (sym != rbrace)
		{
			error(22);	//»±…Ÿ”“¥Û¿®∫≈
		}
	}
}