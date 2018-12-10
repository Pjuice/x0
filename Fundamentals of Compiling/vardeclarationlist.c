#include "head.h"

void vardeclarationlist()
{
	if (sym == intsym || sym == charsym || sym == boolsym || sym == doublesym)
	{
		vardeclarationstar();
		vardeclarationlist();
	}
}