#include "head.h"

void vardeclaration_stat(int *ptr_offset)
{
	if (sym == intsym || sym == charsym || sym == doublesym || sym == boolsym)
	{
		enum object type = sym;
		getsym();
		if (sym == ident)
		{
			getsym();
			if (sym == lmbrace)
			{
				int size[maxdimension] = { 0 };
				int d = 0;
				int space = 1;
				while (sym == lmbrace)
				{
					getsym();
					if (sym == intnum)
					{
						size[d++] = intNum;
						space *= intNum;
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
				if (type == charsym) 
				{
					enter(chararray, *ptr_offset, size, d, 0);
					*ptr_offset = *ptr_offset + space;
				}
				else if (type == intsym) 
				{
					enter(intarray, *ptr_offset, size, d, 0);
					*ptr_offset = *ptr_offset + space;
				}
				else if (type == boolsym) 
				{
					enter(boolarray, *ptr_offset, size, d, 0);
					*ptr_offset = *ptr_offset + space;
				}
				else 
				{
					enter(doublearray, *ptr_offset, size, d, 0);
					*ptr_offset = *ptr_offset + space;
				}
			}
			else
			{
				int size[maxdimension] = { 0 };
				int d = 0;
				if (type == charsym)
				{
					enter(charvar, *ptr_offset, size, d, 0);
					*ptr_offset = *ptr_offset + 1;
				}
				else if (type == intsym)
				{
					enter(intvar, *ptr_offset, size, d, 0);
					*ptr_offset = *ptr_offset + 1;
				}
				else if (type == boolsym)
				{
					enter(boolvar, *ptr_offset, size, d, 0);
					*ptr_offset = *ptr_offset + 1;
				}
				else
				{
					enter(doublevar, *ptr_offset, size, d, 0);
					*ptr_offset = *ptr_offset + 1;
				}
			}
			if (sym == semicolon)
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