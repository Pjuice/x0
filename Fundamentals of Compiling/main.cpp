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
		error(9);	//»±…Ÿmain∑˚∫≈
	}

	fctnum++;
	strcpy(fctinfo[fctnum-1].name, id);
	fctinfo[fctnum].startintcode = codenum;
	fctinfo[fctnum].paranum = 0;
	fctinfo[fctnum].returntype = retvoid;

	getsym();

	if (sym != lparen)
	{
		error(9);	//»±…Ÿ◊Û–°¿®∫≈'('
	}

	getsym();

	if (sym != rparen)
	{
		error(9);	//»±…Ÿ”“–°¿®∫≈')'
	}

	getsym();

	if (sym != lbrace)
	{
		error(9);	//»±…Ÿ◊Û¥Û¿®∫≈'{'
	}

	getsym();

	int offset = 3;

	constdeclaration_list(&offset);

	vardeclaration_list(&offset);

	statement_list();
	

	if (sym != rbrace)
	{
		error(9);	//»±…Ÿ”“¥Û¿®∫≈
	}

	getsym();

	if (sym != oversym)
	{
		error(10);	//»±…Ÿ≥Ã–ÚΩ· ¯∑˚
	}

	printf("\n===Parsing success!===\n");
	fprintf(foutput, "\n===Parsing success!===\n");

	for (int i = 0; i < codenum; i++)
	{
		fprintf(foutput, "[%d] %s %d %.2f\n", i, fctcodestring[code[i].f], code[i].opr1, code[i].opr2);
	}

	fclose(foutput);
	fclose(fin);

}