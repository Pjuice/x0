#include "head.h"

void switch_stat()
{
	if (sym == switchsym)
	{
		getsym();
		if (sym == lparen)
		{
			getsym();
			expression();
			if (sym == rparen)
			{
				getsym();
				if (sym == lbrace)
				{
					getsym();
					if (sym == casesym)
					{
						while (sym == casesym)
						{
							getsym();
							if (sym == intnum)
							{
								getsym();
								if (sym == colon)
								{
									getsym();
									statement_list();
								}
								else
								{
									error(17);	//ȱ��ð��
								}
							}
							else
							{
								error(18);	//ȱ��number��ʶ��
							}
						}
					}
					if (sym == defaultsym)
					{
						getsym();
						if (sym == colon)
						{
							getsym();
							statement_list();
						}
					}
					if (sym == rbrace)
					{
						getsym();
					}
					else
					{
						error(20);	//ȱ���Ҵ�����
					}
				}
			}
		}
	}
}