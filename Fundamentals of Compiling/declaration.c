#include "head.h"

void declaration(int* ptx)
{
	if (sym == intsym)
	{
		if (sym == ident)
		{
			getsym();
			if (sym == semicolon)
			{
				enter(integer, ptx);
				getsym();
			}
			else if (sym == lmbrace)
			{
				getsym();
				if (sym == number)
				{
					getsym();
					if (sym == rmbrace)
					{
						getsym();
						if (sym == semicolon)
						{
							enter(intarray, ptx);
							getsym();
						}
						else
						{
							error(2); //声明整数数组应用；结束
						}
					}
					else
					{
						error(3); //声明整数数组数字后应该加右中括号
					}
				}
				else
				{
					error(4); //声明整数数组左括号后加数字
				}
			}
			else
			{
				error(5); //idh后应为；或[
			}
		}
		else
		{
			error(6);//int后应该为标识符
		}
	}
	else if (sym == charsym)
	{
		if (sym == ident)
		{
			getsym();
			if (sym == semicolon)
			{
				enter(charsym, ptx);
				getsym();
			}
			else if (sym == lmbrace)
			{
				getsym();
				if (sym == number)
				{
					getsym();
					if (sym == rmbrace)
					{
						getsym();
						if (sym == semicolon)
						{
							enter(chararray, ptx);
							getsym();
						}
						else
						{
							error(2); //声明整数数组应用；结束
						}
					}
					else
					{
						error(3); //声明整数数组数字后应该加右中括号
					}
				}
				else
				{
					error(4); //声明整数数组左括号后加数字
				}
			}
			else
			{
				error(5); //idh后应为；或[
			}
		}
		else
		{
			error(6);//char后应该为标识符
		}
	}
}