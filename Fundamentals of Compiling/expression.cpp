#include "head.h"

void expression()
{
	if (sym == ident)
	{
		if (position(id, fctnum - 1) != -1)
		{
			backup();
			int offset;
			enum object kind;
			simple_var(&offset, &kind);

			if (sym == becomes)
			{
				if (kind == constintvar || kind == constcharvar|| kind == constboolvar || kind == constdoublevar)
				{
					error(31);	//���������Ա��ı�ֵ�Ĵ�С
				}
				getsym();
				expression();
				gen(sto, offset, fctnum - 1);
			}
			else
			{
				rollback();
				value_expr();
			}
		}
	}
	else if (sym == oddsym || sym == minus || sym == notsym || sym == lparen || sym == incre
		|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym)
	{
		value_expr();
	}
	else
	{
		error(14);	//δ�ҵ���Ч��
	}
}