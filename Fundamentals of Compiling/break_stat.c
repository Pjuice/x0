#include "head.h"

void break_stat()
{
	if (sym == breaksym)
	{
		getsym();
		if (sym == semicolon)
		{
			getsym();
			gen(jmp, 0, 0);
			brklist[brknum] = codenum - 1;
			brknum = brknum + 1;
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