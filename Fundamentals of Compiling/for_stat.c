#include "head.h"

void for_stat()
{
	if (sym == forsym)
	{
		getsym();
		if (sym == lparen)
		{
			getsym();
			if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
				|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym || sym == ident)
			{
				expression();
			}
			if (sym == semicolon)
			{
				getsym();
				if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
					|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym || sym == ident)
				{
					expression();
				}
				if (sym == semicolon)
				{
					getsym();
					if (sym == oddsym || sym == minus || sym == not || sym == lparen || sym == incre
						|| sym == decre || sym == intnum || sym == doublenum || sym == truesym || sym == falsesym || sym == ident)
					{
						expression();
					}
					if (sym == rparen)
					{
						getsym();
						statement();
					}
					else
					{
						error(17);	//ȱ��������
					}
				}
				else
				{
					error(18);	//ȱ�ٷֺ�
				}
			}
			else
			{
				error(18);	//ȱ�ٷֺ�
			}
		}
		else
		{
			error(19);	//ȱ��������
		}
	}
	else
	{
		error(20);	//ȱ��for����
	}
}