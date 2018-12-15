#include "head.h"

void read_stat()
{
	if (sym == readsym)
	{
		getsym();
		void variable(enum object*ptr_kind, int *ptr_offset);
		if (sym == semicolon)
		{
			getsym();
		}
		else
		{
			error(10);	//È±ÉÙ·ÖºÅ
		}
	}
	else
	{
		error(11);	//È±ÉÙread·ûºÅ
	}
}