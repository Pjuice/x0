#include "head.h"

void continue_stat()
{
	if (sym == continuesym)
	{
		getsym();
		if (sym == semicolon)
		{
			getsym();
			gen(jmp, 0, 0);
		}
		else
		{
			error(22);	//ȱ�ٷֺ�
		}
	}
	else
	{
		error(23);	//ȱ��continue����
	}
}