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
				error(14);	//ȱ����������
			}
		}
	}
	else
	{
		error(15);	//ȱ��ident��ʶ��
	}
}