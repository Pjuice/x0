#include "head.h"

void simple_var(int *ptr_offset, int *ptr_kind)
{
	if (sym == ident)
	{
		int pos = positionbyidentname(id, fctnum - 1);

		if (pos == -1)
		{
			error(20);	//û���ڷ��ű����ҵ��ñ����Ķ���
		}

		*ptr_kind = fctinfo[fctnum - 1].symtable[pos].kind;
		*ptr_offset = fctinfo[fctnum - 1].symtable[pos].offset;

		getsym();
		if (sym == lmbrace)
		{
			/*ident��Ϊ����Ԫ��*/
			if (*ptr_kind != intarray && *ptr_kind != chararray
				&& *ptr_kind != boolarray && *ptr_kind != doublearray)
			{
				error(25);	//ident������Ԫ�ص��ǲ���������Ԫ��
			}
			/*�����ǰidentΪ���飬��ôȷ������û�г���*/
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
							error(50);	//����Խ��
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
					error(14);	//ȱ����������
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
				error(24);	//��ǰident����һ������
			}
		}
	}
	else
	{
		error(15);	//ȱ��ident��ʶ��
	}
}