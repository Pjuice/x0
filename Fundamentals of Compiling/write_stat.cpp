#include "head.h"

void write_stat()
{
	if (sym == writesym)
	{
		getsym();
		expression();
		if (sym == semicolon)
		{
			getsym();
		}
		else
		{
			error(12);	//ȱ�ٽ������ֺ�
		}
		gen(opr, 15, 0);	//���ջ��Ԫ��
	}
	else
	{
		error(13);	//ȱ��write����
	}
}