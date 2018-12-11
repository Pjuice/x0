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
			error(15);	//缺少分号
		}
	}
	else
	{
		error(16);	//缺少break标识符
	}
}