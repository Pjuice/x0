#include "head.h"

void value_expr()
{
	simple_value();
	while (sym == andsym || sym == orsym || sym == xor)
	{
		getsym();
		simple_value();
	}
}