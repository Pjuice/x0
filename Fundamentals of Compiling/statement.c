#include "head.h"

void statement()
{
	if (sym == ifsym)
	{
		if_stat();
	}
	else if (sym == whilesym)
	{
		while_stat();
	}
	else if (sym == readsym)
	{
		read_stat();
	}
	else if (sym == writesym)
	{
		write_stat();
	}
	else if (sym == lbrace)
	{
		compound_stat();
	}
	else if (sym == semicolon || sym == oddsym || sym == minus || sym == not || sym == lparen || sym == ident
		|| sym == incre || sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym)
	{
		expression_stat();
	}
	else if (sym == forsym)
	{
		for_stat();
	}
	else if (sym == switchsym)
	{
		switch_stat();
	}
	else if (sym == breaksym)
	{
		break_stat();
	}
	else if (sym == exitsym)
	{
		exit_stat();
	}
	else if (sym == continuesym)
	{
		continue_stat();
	}
	else if (sym == dosym)
	{
		dowhile_stat();
	}
	else if (sym == repeatsym)
	{
		repeat_stat();
	}
	else if (sym == returnsym)
	{
		return_stat();
	}
	else
	{
		error(20);	//缺少有效标识符
	}
}