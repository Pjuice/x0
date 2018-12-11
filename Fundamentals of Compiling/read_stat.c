#include "head.h"

void read_stat()
{
	if (sym == readsym)
	{
		getsym();
		variable();
		getsym();
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