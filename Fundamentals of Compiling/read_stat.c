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
			error(10);	//È±ÉÙ·ÖºÅ
		}
	}
	else
	{
		error(11);	//È±ÉÙread·ûºÅ
	}
}