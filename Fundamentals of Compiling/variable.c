#include "head.h"

void variable(enum object*ptr_kind, int *ptr_offset)
{
	if (sym == incre || sym == decre)
	{
		getsym();
		simple_var(ptr_offset, ptr_kind);
		if (*ptr_kind != intvar && *ptr_kind != intarray && *ptr_kind != intvar && * ptr_kind != charvar && *ptr_kind != chararray)
		{
			error(30);	//�������Լ���ident����Ϊint����var������Ϊconst��bool��
		}
	}
	else if (sym == ident)
	{
		simple_var(ptr_offset, ptr_kind);
		if (sym == incre || sym == decre)
		{
			if (*ptr_kind != intvar && *ptr_kind != intarray && *ptr_kind != intvar && * ptr_kind != charvar && *ptr_kind != chararray)
			{
				error(30);	//�������Լ���ident����Ϊint����var������Ϊconst��bool��
			}
			getsym();
		}
	}
	else
	{
		error(20);	//δ�ҵ���Ч��ʶ��
	}
}