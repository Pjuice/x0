#include "head.h"

void vardeclaration_list(int *ptr_offset)
{
	if (sym == intsym || sym == charsym || sym == boolsym || sym == doublesym)
	{
		vardeclaration_stat(ptr_offset);
		vardeclaration_list(ptr_offset);
	}
}