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
				error(20);	//ȱ��������]
			}
		}
	}
	else
	{
		error(21);	//ȱ��ident
	}
}