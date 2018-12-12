#include "head.h"

void variable()
{
	if (sym == incre || sym == decre)
	{
		getsym();
		simple_var();
	}
	else if (sym == ident)
	{
		simple_var();
		if (sym == incre || sym == decre)
		{
			getsym();
		}
	}
	else
	{
		error(20);	//未找到有效标识符
	}
}