#include "head.h"

void statement(int* ptx)
{
	if (sym == ifsym)
	{
		if_stat(ptx);
	}
	else if (sym == whilesym)
	{
		while_stat(ptx);
	}
	else if (sym == readsym)
	{
		read_stat(ptx);
	}
	else if (sym == writesym)
	{
		write_stat(ptx);
	}
	else if (sym == lbrace)
	{
		compound_stat(ptx);
	}
	else if (sym == semicolon || sym == sharpsym || sym == minus
		|| sym == ident || sym == number)
	{
		expression_stat(ptx);
	}
}