#include "head.h"

void simple_var(int *ptr_offset, int *ptr_kind)
{
	if (sym == ident)
	{
		int pos = positionbyidentname(id, fctnum - 1);

		if (pos == -1)
		{
			error(20);	//没有在符号表中找到该变量的定义
		}

		*ptr_kind = fctinfo[fctnum - 1].symtable[pos].kind;
		*ptr_offset = fctinfo[fctnum - 1].symtable[pos].offset;

		getsym();
		if (sym == lmbrace)
		{
			/*ident不为数组元素*/
			if (*ptr_kind != intarray && *ptr_kind != chararray
				&& *ptr_kind != boolarray && *ptr_kind != doublearray)
			{
				error(25);	//ident非数组元素但是查找了数组元素
			}
			/*如果当前ident为数组，那么确认索引没有出界*/
			backup();
			int curdimension = 0;
			while (sym == lmbrace)
			{
				getsym();
				if (sym == intnum)
				{
					int tepNum = intNum;
					getsym();
					if (sym == rmbrace)
					{
						if (tepNum >= fctinfo[fctnum - 1].symtable[pos].size[curdimension++])
						{
							error(50);	//数组越界
						}
						getsym();
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			rollback();

			while (sym == lmbrace)
			{
				getsym();
				expression();
				if (sym == rmbrace)
				{
					getsym();
				}
				else
				{
					error(14);	//缺少右中括号
				}
			}
		}
		else
		{
			if (*ptr_kind != intvar && *ptr_kind != charvar
				&& *ptr_kind != boolvar && *ptr_kind != doublevar
				&& *ptr_kind != constintvar && *ptr_kind != constcharvar
				&& *ptr_kind != constboolvar && *ptr_kind != constdoublevar)
			{
				error(24);	//当前ident不是一个变量
			}
		}
	}
	else
	{
		error(15);	//缺少ident标识符
	}
}