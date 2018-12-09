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
		error(9);
	}

	getsym();

	if (sym != lbrace)
	{
		error(9);
	}
	
	getsym();
	declaration_list(0);

}