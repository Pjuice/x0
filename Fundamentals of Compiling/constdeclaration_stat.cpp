#include "head.h"

void constdeclaration_stat(int *ptr_offset)
{
	enum symbol type;
	if (sym == constsym)
	{
		getsym();
		if (sym == intsym || sym == charsym || sym == boolsym || sym == doublesym)
		{
			type = sym;
			getsym();
			if (sym == ident)
			{
				getsym();
				if (sym == becomes)
				{
					getsym();
					int size[maxdimension] = { 0 };
					int d = 0;
					if (sym == intnum || sym == truesym || sym == falsesym || sym == doublenum)
					{
						getsym();
						if (sym == intnum || sym == doublenum)
						{
							if (type == intsym)
							{
								enter(constintvar, *ptr_offset, size, d, sym == intnum ? intNum : doublenumber);
								*ptr_offset = *ptr_offset + 1;
							}
							else if (type == charsym)
							{
								enter(constcharvar, *ptr_offset, size, d, sym == intnum ? intNum : doublenumber);
								*ptr_offset = *ptr_offset + 1;
							}
							else if (type == boolsym)
							{
								enter(constboolvar, *ptr_offset, size, d, sym == intnum ? intNum : doublenumber);
								*ptr_offset = *ptr_offset + 1;
							}
							else if (type == doublesym)
							{
								enter(constdoublevar, *ptr_offset, size, d, sym == intnum ? intNum : doublenumber);
								*ptr_offset = *ptr_offset + 1;
							}
						}
						else if (sym == falsesym || sym == truesym)
						{
							if (type == intsym)
							{
								enter(constintvar, *ptr_offset, size, d, sym == truesym ? 1 : 0);
								*ptr_offset = *ptr_offset + 1;
							}
							else if (type == charsym)
							{
								enter(constcharvar, *ptr_offset, size, d, sym == truesym ? 1 : 0);
								*ptr_offset = *ptr_offset + 1;
							}
							else if (type == boolsym)
							{
								enter(constboolvar, *ptr_offset, size, d, sym == truesym ? 1 : 0);
								*ptr_offset = *ptr_offset + 1;
							}
							else if (type == doublesym)
							{
								enter(constdoublevar, *ptr_offset, size, d, sym == truesym ? 1 : 0);
								*ptr_offset = *ptr_offset + 1;
							}
						}
						if (sym == semicolon)
						{
							getsym();
						}
						else
						{
							error(10);	//ȱ�ٽ����ֺ�
						}
					}
					else
					{
						error(11);	//ȱ��ֵ
					}
				}
				else
				{
					error(12);	//ȱ�ٸ�ֵ��
				}
			}
			else
			{
				error(13);	//ȱ��identical
			}
		}
		else
		{
			error(14);	//ȱ������
		}
	}
	else
	{
		error(15);	//ȱ��const��
	}
}