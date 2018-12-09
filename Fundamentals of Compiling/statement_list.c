#include "head.h"

void statement_list (int* ptx)
{
	while (sym == ifsym || sym == whilesym || sym == readsym || sym == writesym || sym == lbrace || sym == semicolon
		|| sym == sharpsym || sym == minus || sym == lparen)
	{
		statement(ptx);
	}
	if (sym != rbrace)
	{
		error(9);
	}
	else
	{
		printf("\n===Parsing success!===\n");
		fprintf(foutput, "\n===Parsing success!===\n");
	}

	fclose(foutput);
	fclose(fin);


	return 0;
}