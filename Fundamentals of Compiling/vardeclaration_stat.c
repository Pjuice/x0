#include "head.h"

void vardeclaration_stat()
{
	if (sym == intsym || sym == charsym || sym == doublesym || sym == boolsym)
	{
		getsym();
		if (sym == ident)
		{
			getsym();
			if (sym == lmbrace)
			{
				while (sym == lmbrace)
				{
					getsym();
					if (sym == intnum)
					{
						getsym();
						if (sym == rmbrace)
						{
							getsym();
						}
						else
						{
							error(10);	//ȱ����������
						}
					}
					else
					{
						error(11);	//ȱ������
					}
				}
			}
			if (sym == semicolon)
			{
				getsym();
			}
			else
			{
				error(12);	//ȱ�ٽ����ֺ�
			}
		}
	}
}