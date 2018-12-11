#include "head.h"

void vardeclaration_stat()
{
	if (sym == intsym || sym == charsym || sym == doublesym || sym == boolsym)
	{
		getsym();
		if (sym == ident)
		{
			getsym();
			if (sym == lmbrace)
			{
				while (sym == lmbrace)
				{
					getsym();
					if (sym == number)
					{
						getsym();
						if (sym == rmbrace)
						{
							getsym();
						}
						else
						{
							error(10);	//缺少右中括号
						}
					}
					else
					{
						error(11);	//缺少数字
					}
				}
			}
			else if (sym == semicolon)
			{
				getsym();
			}
			else
			{
				error(12);	//缺少结束分号
			}
		}
	}
}