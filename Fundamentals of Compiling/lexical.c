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
			if (EOF == fscanf(fin, "&c", &ch))
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
		if (ch >= '0' && ch <= '9')/*当前的单词是数字*/
		{
			k = 0;
			num = 0;
			sym = number;
			do
			{
				num = 10 * num + ch - '0';
				k++;
				getch();
			} while (ch >= '0' && ch <= '9');
			k--;
			if (k > nmax)
			{
				error(30);
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

