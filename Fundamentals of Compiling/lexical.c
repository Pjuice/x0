#include "head.h"

void getch()
{
	if (cc == ll)
	{
		if (feof(fin))
		{
			printf("Program incomplete!\n");
			exit(1);
		}
		ll = 0;
		cc = 0;

		ch = ' ';
		while (ch != 10)
		{
			if (EOF == fscanf(fin, "%c", &ch))
			{
				line[ll] = 0;
				break;
			}

			printf("%c", ch);
			fprintf(foutput, "%c", ch);
			line[ll] = ch;
			ll++;
		}
	}
	ch = line[cc];
	cc++;
}

void getsym()
{
	int i, j, k;

	while (ch == ' ' || ch == 10 || ch == 9)
	{
		getch();
	}
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		k = 0;
		do 
		{
			if (k < al)
			{
				a[k] = ch;
				k++;
			}
			getch();
		} while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
		a[k] = 0;
		strcpy(id, a);
		i = 0;
		j = norw - 1;
		do
		{
			k = (i + j) / 2;
			if (strcmp(id, word[k]) <= 0)
			{
				j = k - 1;
			}
			if (strcmp(id, word[k]) >= 0)
			{
				i = k + 1;
			}
		} while (i <= j);
		if (i - 1 > j)
		{
			sym = wsym[k];
		}
		else
		{
			sym = ident;
		}
	}
	else
	{
		if (ch >= '0' && ch <= '9')	/* 读取数字 */
		{
			k = 0;
			intNum = 0;
			int flagDecPoint = 0; 
			double decimal = 0;   
			double weight = 0.1;  

			do
			{
				if (!flagDecPoint)
				{
					intNum = 10 * intNum + ch - '0';
					k++;

					if (k > nmax) /* 数字超过了规定大小 */
					{
						error(20);	
					}
				}
				else
				{
					decimal += weight * (ch - '0');
					weight *= 0.1;
				}
				getch();
				if (ch == '.' && !flagDecPoint)
				{
					getch();
					flagDecPoint = 1;
					if (ch < '0' || ch > '9') /* illegal number */
					{
						error(21);
					}
				}
			} while (ch >= '0' && ch <= '9');

			if (flagDecPoint) /* current sym is floatnumber */
			{
				doublenumber = intNum + decimal;
			}
			if (flagDecPoint)
			{
				sym = doublenum;
			}
			else
			{
				sym = intnum;
			}
		}
		else
		{
			if (ch == '=')	//检测到赋值符号
			{
				getch();
				if (ch == '=')
				{
					sym = eql;
					getch();
				}
				else
				{
					sym = becomes;
				}
			}
			else
			{
				if (ch == '!')
				{
					getch();
					if (ch == '=')
					{
						sym = neq;
						getch();
					}
					else
					{
						sym = not;
					}
				}
				else
				{
					if (ch == '<')
					{
						getch();
						if (ch == '=')
						{
							sym = leq;
							getch();
						}
						else
						{
							sym = lss;
						}
					}
					else
					{
						if (ch == '>')
						{
							getch();
							if (ch == '=')
							{
								sym = geq;
								getch();
							}
							else
							{
								sym = gtr;
							}
						}
						else
						{
							if (ch == '&')
							{
								getch();
								if (ch == '&')
								{
									sym = andsym;
									getch();
								}
								else
								{
									sym = nul;
								}
							}
							else 
							{
								if (ch == '|')
								{
									getch();
									if (ch == '|')
									{
										sym = orsym;
										getch();
									}
									else
									{
										sym = nul;
									}
								}
								else
								{
									if (ch == '+')
									{
										getch();
										if (ch == '+')
										{
											sym = incre;
											getch();
										}
										else
										{
											sym = plus;
										}
									}
									else
									{
										if (ch == '-')
										{
											getch();
											if (ch == '-')
											{
												sym = decre;
												getch();
											}
											else
											{
												sym = minus;
											}
										}
										else
										{
											sym = ssym[ch];
											if (sym != oversym)
											{
												getch();
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

