#include "head.h"

void break_stat()
{
	if (sym == break_stat)
	{
		getsym();
		if (sym == semicolon)
		{
			getsym();
		}
		else
		{
			error(15);	//ȱ�ٷֺ�
		}
	}
	else
	{
		error(16);	//ȱ��break��ʶ��
	}
}