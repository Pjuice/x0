#include "head.h"

void read_stat()
{
	if (sym == readsym)
	{
		getsym();
		enum object kind;
		int offset;
		variable(&kind, &offset);
		if (sym == semicolon)
		{
			getsym();
		}
		else
		{
			error(10);	//ȱ�ٷֺ�
		}
	}
	else
	{
		error(11);	//ȱ��read����
	}
}