#include "head.h"

void simple_expr(int *ptx)
{
	getsym();
	addictive_expr(ptx);
	if (sym == neq || sym == eql || sym == gtr || sym == geq || sym == lss || sym == leq)
	{
		addictive_expr(ptx);
	}

}