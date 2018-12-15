#include "head.h"

void variable(enum object*ptr_kind, int *ptr_offset)
{
	if (sym == incre || sym == decre)
	{
		getsym();
		simple_var(ptr_offset, ptr_kind);
		if (*ptr_kind != intvar && *ptr_kind != intarray && *ptr_kind != intvar && * ptr_kind != charvar && *ptr_kind != chararray)
		{
			error(30);	//自增或自减的ident必须为int或者var，不能为const或bool等
		}
	}
	else if (sym == ident)
	{
		simple_var(ptr_offset, ptr_kind);
		if (sym == incre || sym == decre)
		{
			if (*ptr_kind != intvar && *ptr_kind != intarray && *ptr_kind != intvar && * ptr_kind != charvar && *ptr_kind != chararray)
			{
				error(30);	//自增或自减的ident必须为int或者var，不能为const或bool等
			}
			getsym();
		}
	}
	else
	{
		error(20);	//未找到有效标识符
	}
}