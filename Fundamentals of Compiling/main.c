#include "head.h"

int main()
{
	printf("Input x0 file?    ");
	scanf("%s", fname);
	
	if ((fin = fopen(fname, "r")) == NULL)
	{
		printf("Can't open the input file!\n");
		exit(1);
	}

	ch = fgetc(fin);
	if (ch == EOF)
	{
		printf("The input file is empty!\n");
		fclose(fin);
		exit(1);
	}
	rewind(fin);

	if ((foutput = fopen("foutput.txt", "w")) == NULL)
	{
		printf("Can't open the output file!\n");
		exit(1);
	}

	init();
	cc = ll = 0;
	ch = ' ';

	getsym();

	if (sym != mainsym)
	{
		error(9);	//ȱ��main����
	}

	getsym();

	if (sym != lparen)
	{
		error(9);	//ȱ����С����'('
	}

	getsym();

	if (sym != rparen)
	{
		error(9);	//ȱ����С����')'
	}

	getsym();

	if (sym != lbrace)
	{
		error(9);	//ȱ���������'{'
	}

	getsym();

	constdeclaration_list();

	vardeclaration_list();

	statement_list();
	
	getsym();

	if (sym != rbrace)
	{
		error(9);	//ȱ���Ҵ�����
	}

	printf("\n===Parsing success!===\n");
	fprintf(foutput, "\n===Parsing success!===\n");

}