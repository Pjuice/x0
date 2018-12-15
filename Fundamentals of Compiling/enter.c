#include "head.h"

/*
* 在符号表中加入一项
*/
void enter(enum object k, int offset, int* size, int d, double value)
{

	strcpy(fctinfo[fctnum - 1].symtable[fctinfo[fctnum - 1].tablesize].name, id);
	fctinfo[fctnum - 1].symtable[fctinfo[fctnum - 1].tablesize].kind = k;
	fctinfo[fctnum - 1].symtable[fctinfo[fctnum - 1].tablesize].offset = offset;
	for (int i = 0; i < d; i++)
	{
		fctinfo[fctnum - 1].symtable[fctinfo[fctnum - 1].tablesize].size[i] = size[i];
	}
	fctinfo[fctnum - 1].symtable[fctinfo[fctnum - 1].tablesize].d = d;
	fctinfo[fctnum - 1].symtable[fctinfo[fctnum - 1].tablesize].value = value;

	fctinfo[fctnum - 1].tablesize++;
}