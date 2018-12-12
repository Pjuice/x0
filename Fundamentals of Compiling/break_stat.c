#include "head.h"

void break_stat()
{
	if (sym == breaksym)
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