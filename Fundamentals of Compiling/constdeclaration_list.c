#include "head.h"

void constdeclaration_list()
{
	if (sym == constsym)
	{
		constdeclaration_stat();
		constdeclaration_list();
	}
}