#include "head.h"

void read_stat()
{
	if (sym == readsym)
	{
		getsym();
		enum object kind;
		int offset;
		variable(&kind, &offset);

		if (kind == constintvar || kind == constcharvar
			|| kind == constboolvar || kind == constdoublevar)
		{
			error(52);			//read不能为const数据类型
		}

		if (kind == intvar || kind == intarray)
		{
			gen(opr, 14, Int);
		}
		else if (kind == doublevar || kind == doublearray)
		{
			gen(opr, 14, Double);
		}
		else if (kind == charvar || kind == chararray)
		{
			gen(opr, 14, Char);
		}
		else if (kind == boolvar || kind == boolarray)
		{
			gen(opr, 14, Bool);
		}

		gen(sto, offset, fctnum - 1);

		if (sym == semicolon)
		{
			getsym();
		}
		else
		{
			error(10);	//缺少分号
		}
	}
	else
	{
		error(11);	//缺少read符号
	}
}