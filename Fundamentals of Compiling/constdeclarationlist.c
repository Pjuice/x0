#include "head.h"

void constdeclarationlist()
{
	if (sym == constsym)
	{
		constdeclarationstat();
		constdeclarationlist();
	}
}