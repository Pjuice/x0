#include "head.h"

void constdeclaration_list(int *ptr_offset)
{
	if (sym == constsym)
	{
		constdeclaration_stat(ptr_offset);
		constdeclaration_list(ptr_offset);
	}
}