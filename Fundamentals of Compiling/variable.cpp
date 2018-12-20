#include "head.h"

void variable(enum object*ptr_kind, int *ptr_offset)
{
	int cretype = 5;

	if (sym == incre || sym == decre)
	{
		if (sym == incre)
		{
			cretype = 3;
		}
		else if (sym == decre)
		{
			cretype = 4;
		}
		else
		{
			cretype = 5;
		}
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

			if (sym == incre)
			{
				cretype = 1;
			}
			else if(sym == decre)
			{
				cretype = 2;
			}
			else
			{
				cretype = 5;
			}

			getsym();
		}
	}
	else
	{
		error(20);	//δ�ҵ���Ч��ʶ��
	}

	switch (cretype)
	{
	case 1:
		gen(add, *ptr_offset, fctnum - 1);
		gen(lod, *ptr_offset, fctnum - 1);
		gen(tad, -1, 0);
		break;
	case 2:
		gen(sub, *ptr_offset, fctnum - 1);
		gen(lod, *ptr_offset, fctnum - 1);
		gen(tad, 1, 0);
		break;
	case 3:
		gen(add, *ptr_offset, fctnum - 1);
		gen(lod, *ptr_offset, fctnum - 1);
		break;
	case 4:
		gen(sub, *ptr_offset, fctnum - 1);
		gen(lod, *ptr_offset, fctnum - 1);
		break;
	case 5:
		gen(lod, *ptr_offset, fctnum - 1);
		break;
	}
}