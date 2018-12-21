#include "head.h"
#include "stackobject.h"

void interpret()
{
	int p = 0; /* 指令指针 */
	int b = 1; /* 指令基址 */
	int t = 0; /* 栈顶指针 */
	struct codeins ins; /*当前指令*/
	stackobject s[maxstacksize];

	int d;	/*数组的维度*/
	int offset;
	int pos;

	s[1].datatype = Int;
	s[1].intdata = 0;
	s[2].datatype = Int;
	s[2].intdata = 0;
	s[3].datatype = Int;
	s[3].intdata = 0;

	do
	{
		ins = code[p];
		p++;
		if (ins.f == lit)
		{
			t = t + 1;
			if (ins.opr2 == 0)
			{
				s[t].datatype = Int;
				s[t].intdata = ins.opr1;
			}
			else
			{
				s[t].datatype = Double;
				s[t].doubledata = ins.opr2;
			}
		}
		else if (ins.f == opr)
		{
			switch (ins.opr1)
			{
				case 0:
					t = b - 1;
					p = s[t + 3].intdata;
					b = s[t + 2].intdata;
					break;

				case 1:
					s[t] = -s[t];
					break;

				case 2:
					t = t - 1;
					s[t] = s[t] + s[t + 1];
					break;

				case 3:
					t = t - 1;
					s[t] = s[t] - s[t + 1];
					break;

				case 4:
					t = t - 1;
					s[t] = s[t] * s[t + 1];
					break;

				case 5:
					t = t - 1;
					s[t] = s[t] / s[t + 1];
					break;

				case 6:
					t = t - 1;
					s[t] = s[t] % s[t + 1];
					break;

				case 7:
					t = t - 1;
					if (s[t + 1].datatype == Double)
					{
						error(40);	//exit函数的参数必须为整数
					}
					exit(s[t + 1].intdata);
					break;

				case 8:
					t = t - 1;
					s[t] = (s[t] == s[t + 1]);
					break;

				case 9:
					t = t - 1;
					s[t] = (s[t] != s[t + 1]);
					break;

				case 10:
					t = t - 1;
					s[t] = (s[t] < s[t + 1]);
					break;

				case 11:
					t = t - 1;
					s[t] = (s[t] >= s[t + 1]);
					break;

				case 12:
					t = t - 1;
					s[t] = (s[t] > s[t + 1]);
					break;

				case 13:
					t = t - 1;
					s[t] = (s[t] <= s[t + 1]);
					break;

				case 14:
					t = t + 1;
					s[t].datatype = (enum datatype)(int)(ins.opr2);
					if (s[t].datatype == Int || s[t].datatype == Bool)
					{
						scanf("%d", &(s[t].intdata));
					}
					else if (s[t].datatype == Char)
					{
						s[t].intdata = getchar();
					}
					else if (s[t].datatype == Double)
					{
						scanf("%lf", &(s[t].doubledata));
					}
					break;

				case 15:
					if (s[t].datatype == Int || s[t].datatype == Bool)
					{
						printf("%d\n", s[t].intdata);
					}
					else if (s[t].datatype == Double)
					{
						printf("%f\n", s[t].doubledata);
					}
					else if (s[t].datatype == Char)
					{
						printf("%c\n", s[t].intdata);
					}
					t = t - 1;
					break;
				
				case 16:
					t = t - 1;
					s[t] = s[t] && s[t + 1];
					break;

				case 17:
					t = t - 1;
					s[t] = s[t] || s[t + 1];
					break;

				case 18:
					s[t] = s[!t];
					break;
				
				case 19:
					t = t - 1;
					s[t] = s[t] ^ s[t + 1];
					break;

				case 20:
					if (s[t].datatype == Double)
					{
						error(20);		//odd操作的参数必须为int值
					}
					s[t].intdata = s[t].intdata % 2;
					s[t].datatype = Bool;
					break;

				case 21:
					s[t] = (s[t - 1] == s[t]);
					break;

				default:
					error(21);	//opr没有有效的操作参数
			}			
		}
		else if (ins.f == lod)
		{
			pos = position(ins.opr1, 0);
			d = fctinfo[0].symtable[pos].d;
			offset = 0;
			for (int i = 0; i < d; i++)
			{
				if (s[t + 1 - d + i].datatype == Double)
				{
					error(20);	//数组的下标必须为int值
				}
				offset = offset * fctinfo[0].symtable[pos].size[i] + s[t + 1 - d + i].intdata;
			}
			s[t + 1 - d] = s[b + ins.opr1 + offset];
			t = t + 1 - d;
		}
		else if (ins.f == sto)
		{
			pos = position(ins.opr1, 0);
			d = fctinfo[0].symtable[pos].d;
			offset = 0;
			for (int i = 0; i < d; i++)
			{
				if (s[t - d + i].datatype == Double)
				{
					error(20);//数组的下标必须为int值
				}
				offset = offset * fctinfo[0].symtable[pos].size[i] + s[t - d + i].intdata;
			}
			s[b + ins.opr1 + offset].assign(s[t]);
			s[t - d] = s[t]; 
			t = t - d;
		}
		else if (ins.f == add)
		{
			pos = position(ins.opr1, 0);
			d = fctinfo[0].symtable[pos].d;
			offset = 0;
			for (int i = 0; i < d; i++)
			{
				if (s[t + 1 - d + i].datatype == Double)
				{
					error(20);//数组的下标必须为int值
				}
				offset = offset * fctinfo[0].symtable[pos].size[i] + s[t + 1 - d + i].intdata;
			}
			s[b + ins.opr1 + offset].intdata += 1;
		}
		else if (ins.f == sub)
		{
			pos = position(ins.opr1, 0);
			d = fctinfo[0].symtable[pos].d;
			offset = 0;
			for (int i = 0; i < d; i++)
			{
				if (s[t + 1 - d + i].datatype == Double)
				{
					error(20);//数组的下标必须为int值
				}
				offset = offset * fctinfo[0].symtable[pos].size[i] + s[t + 1 - d + i].intdata;
			}
			s[b + ins.opr1 + offset].intdata -= 1;
		}
		else if (ins.f == tad)
		{
			if (s[t].datatype == Double)
			{
				error(53);		//自增自减参数必须为int值
			}
			s[t].intdata += ins.opr1;
		}
		else if (ins.f == jmp)
		{
			p = ins.opr1;
		}
		else if (ins.f == jpc)
		{
			if (!s[t].intdata)
				p = ins.opr1;
			t = t - 1;
		}
		else if (ins.f == ini)
		{
			t = b + 2;

			for (int i = 0; i < fctinfo[ins.opr1].tablesize; i++)
			{
				struct tablestruct tempobject = fctinfo[ins.opr1].symtable[i];
				int totalsize = 1;
				for (int j = 0; j < tempobject.d; j++)
				{
					totalsize *= tempobject.size[j];
				}
				for (int j = 1; j <= totalsize; j++)
				{
					switch (tempobject.kind)
					{
					case intvar:
					case intarray:
						s[++t].datatype = Int;
						break;
					case constintvar:
						s[++t].datatype = Int;
						s[t].intdata = (int)(tempobject.value);
						break;
					case doublevar:
					case doublearray:
						s[++t].datatype = Double;
						break;
					case constdoublevar:
						s[++t].datatype = Double;
						s[t].doubledata = tempobject.value;
						break;
					case charvar:
					case chararray:
						s[++t].datatype = Char;
						break;
					case constcharvar:
						s[++t].datatype = Char;
						s[t].intdata = (int)(tempobject.value);
						break;
					case boolvar:
					case boolarray:
						s[++t].datatype = Bool;
						break;
					case constboolvar:
						s[++t].datatype = Bool;
						s[t].intdata = (int)(tempobject.value);
						break;
					default: 
						error(45);
					}
				}
			}
		}
	} while (p!=0);
}