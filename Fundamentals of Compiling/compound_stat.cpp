#include "head.h"

void compound_stat()
{
	if (sym == lbrace)
	{
		getsym();
		statement_list();
		if (sym == rbrace)
		{
			getsym();
		}
		else
		{
			error(13);	//ȱ���Ҵ�����
		}
	}
	else
	{
		error(14);	//ȱ���������
	}
}