#include "head.h"

void gen(enum fct f, int opr1, double opr2)
{
	if (codenum >= maxcode) 
	{
		error(26);	//当前code的数目过多
	}
	
	code[codenum].f = f;
	code[codenum].opr1 = opr1;
	code[codenum].opr2 = opr2;
	codenum++;

}