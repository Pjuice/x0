#include "head.h"

void constdeclaration_stat()
{
	if (sym == constsym)
	{
		getsym();
		if (sym == intsym || sym == charsym || sym == boolsym || sym == doublesym)
		{
			getsym();
			if (sym == ident)
			{
				getsym();
				if (sym == becomes)
				{
					getsym();
					if (sym == intnum || sym == truesym || sym == falsesym || sym == doublenum)
					{
						getsym();
						if (sym == semicolon)
						{
							getsym();
						}
						else
						{
							error(10);	//ȱ�ٽ����ֺ�
						}
					}
					else
					{
						error(11);	//ȱ��ֵ
					}
				}
				else
				{
					error(12);	//ȱ�ٸ�ֵ��
				}
			}
			else
			{
				error(13);	//ȱ��identical
			}
		}
		else
		{
			error(14);	//ȱ������
		}
	}
	else
	{
		error(15);	//ȱ��const��
	}
}