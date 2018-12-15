#include "head.h"

/*
* ����:
* identame: ��Ҫ���ҵ�ident������
* pos: ��fctinfo�еĺ���������
* ���:
* ��ident�����������symbol���λ��
*/

int positionbyidentname(char* identname, int pos)
{
	for (int i = 0; i < fctinfo[pos].tablesize; i++)
	{
		if (strcmp(fctinfo[pos].symtable[i].name, identname) == 0)
		{
			return i;
		}
	}
	return -1;
}

/*
* ����:
* offset: ������ҪѰ�ҵ�ident��offset
* pos: ��facinfo�еĺ�����λ��
* ���:
* ���ident�ں�����sym���е�λ��
*/
int positionbyoffset(int offset, int pos)
{
	for (int i = 0; i < fctinfo[pos].tablesize; i++)
	{
		if (fctinfo[pos].symtable[i].offset == offset)
		{
			return i;
		}
	}
	return -1;
}

/*
* ����: ������
* ���: ��facinfo�к�����λ��
*/
int positionbyfctname(char* fctname)
{
	for (int i = 0; i < fctnum; i++)
	{
		if (strcmp(fctinfo[i].name, fctname) == 0)
		{
			return i;
		}
	}
	return -1;
}