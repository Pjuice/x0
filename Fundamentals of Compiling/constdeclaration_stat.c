#include "head.h"

void constdeclaration_stat()
{
	if (sym == constsym)
	{
		getsym();
		if (sym == intsym || sym == charsym || sym == boolsym || sym == doublesym)
		{
			getsym();
			if (sym == ident)
			{
				getsym();
				if (sym == becomes)
				{
					getsym();
					if (sym == intnum || sym == truesym || sym == falsesym || sym == doublenum)
					{
						getsym();
						if (sym == semicolon)
						{
							getsym();
						}
						else
						{
							error(10);	//缺少结束分号
						}
					}
					else
					{
						error(11);	//缺少值
					}
				}
				else
				{
					error(12);	//缺少赋值号
				}
			}
			else
			{
				error(13);	//缺少identical
			}
		}
		else
		{
			error(14);	//缺少类型
		}
	}
	else
	{
		error(15);	//缺少const符
	}
}