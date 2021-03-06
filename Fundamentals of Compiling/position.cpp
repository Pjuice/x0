#include "head.h"

/*
* 输入:
* identame: 想要查找的ident的名字
* pos: 在fctinfo中的函数的索引
* 输出:
* 该ident在这个函数的symbol表的位置
*/

int position(char* identname, int pos)
{
	for (int i = 0; i < fctinfo[pos].tablesize; i++)
	{
		if (strcmp(fctinfo[pos].symtable[i].name, identname) == 0)
		{
			return i;
		}
	}
	return -1;
}

/*
* 输入:
* offset: 我们想要寻找的ident的offset
* pos: 在facinfo中的函数的位置
* 输出:
* 这个ident在函数的sym表中的位置
*/
int position(int offset, int pos)
{
	for (int i = 0; i < fctinfo[pos].tablesize; i++)
	{
		if (fctinfo[pos].symtable[i].offset == offset)
		{
			return i;
		}
	}
	return -1;
}

