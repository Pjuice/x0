#include "head.h"

void statement_list()
{
	if (sym == ifsym || sym == whilesym || sym == writesym || sym == lbrace || sym == semicolon ||
		sym == oddsym || sym == readsym || sym == minus || sym == not || sym == lparen || sym == ident
		|| sym == incre || sym == decre || sym == number || sym == truesym || sym == falsesym
		|| sym == forsym || sym == switchsym || sym == exitsym || sym == continuesym || sym == dosym ||
		sym == repeatsym || sym == returnsym)
	{
		statement();
		statement_list();
	}
}