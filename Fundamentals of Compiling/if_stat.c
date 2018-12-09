#include "head.h"

void if_stat(int* ptx)
{
	getsym();
	if (sym == lparen)
	{
		expression(ptx);
		if (sym == rparen)
		{
			statement(ptx);
			if (sym == elsesym)
			{
				statement(ptx);
			}
			else
			{
				//没有else条件，直接跳过
			}
		}
		else
		{
			error(16);	// 缺少右括号
		}
	}
	else
	{
		error(15);	//缺少左括号
	}
}