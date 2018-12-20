#include "head.h"

void write_stat()
{
	if (sym == writesym)
	{
		getsym();
		expression();
		if (sym == semicolon)
		{
			getsym();
		}
		else
		{
			error(12);	//缺少结束符分号
		}
		gen(opr, 15, 0);	//输出栈顶元素
	}
	else
	{
		error(13);	//缺少write符号
	}
}