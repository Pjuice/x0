#include "head.h"

void declaration(int* ptx)
{
	if (sym == intsym)
	{
		if (sym == ident)
		{
			getsym();
			if (sym == semicolon)
			{
				enter(integer, ptx);
				getsym();
			}
			else if (sym == lmbrace)
			{
				getsym();
				if (sym == number)
				{
					getsym();
					if (sym == rmbrace)
					{
						getsym();
						if (sym == semicolon)
						{
							enter(intarray, ptx);
							getsym();
						}
						else
						{
							error(2); //������������Ӧ�ã�����
						}
					}
					else
					{
						error(3); //���������������ֺ�Ӧ�ü���������
					}
				}
				else
				{
					error(4); //�����������������ź������
				}
			}
			else
			{
				error(5); //idh��ӦΪ����[
			}
		}
		else
		{
			error(6);//int��Ӧ��Ϊ��ʶ��
		}
	}
	else if (sym == charsym)
	{
		if (sym == ident)
		{
			getsym();
			if (sym == semicolon)
			{
				enter(charsym, ptx);
				getsym();
			}
			else if (sym == lmbrace)
			{
				getsym();
				if (sym == number)
				{
					getsym();
					if (sym == rmbrace)
					{
						getsym();
						if (sym == semicolon)
						{
							enter(chararray, ptx);
							getsym();
						}
						else
						{
							error(2); //������������Ӧ�ã�����
						}
					}
					else
					{
						error(3); //���������������ֺ�Ӧ�ü���������
					}
				}
				else
				{
					error(4); //�����������������ź������
				}
			}
			else
			{
				error(5); //idh��ӦΪ����[
			}
		}
		else
		{
			error(6);//char��Ӧ��Ϊ��ʶ��
		}
	}
}