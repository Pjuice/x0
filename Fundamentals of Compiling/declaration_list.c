#include "head.h"

void declaration_list(int tx)
{
	int i;

	if (sym == intsym || sym == charsym)
	{
		declaration(&tx);
		while (sym == intsym || sym == charsym)
		{
			declaration(&tx);
		}
		
	}
	statement_list(&tx);
}