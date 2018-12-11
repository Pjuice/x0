#include "head.h"

void vardeclaration_list()
{
	if (sym == intsym || sym == charsym || sym == boolsym || sym == doublesym)
	{
		vardeclaration_stat();
		vardeclaration_list();
	}
}