#include "head.h"

void simple_var()
{
	if (sym == ident)
	{
		getsym();
		while (sym == lmbrace)
		{
			getsym();
			expression();
			if (sym == rmbrace)
			{
				getsym();
			}
			else
			{
				error(14);	//缺少右中括号
			}
		}
	}
	else
	{
		error(15);	//缺少ident标识符
	}
}