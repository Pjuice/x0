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
	}
	else
	{
		error(13);	//ȱ��write����
	}
}