// Fundamentals of Compiling.cpp: 定义控制台应用程序的入口点。
//

#include "head.h"

void init()
{
	int i;

	/* 设置单字符符号 */
	for (i = 0; i <= 255; i++)
	{
		ssym[i] = nul;
	}
	ssym['+'] = plus;
	ssym['-'] = minus;
	ssym['*'] = times;
	ssym['/'] = slash;
	ssym['('] = lparen;
	ssym[')'] = rparen;
	ssym[';'] = semicolon;
	ssym['{'] = lbrace;
	ssym['}'] = rbrace;
	ssym['['] = lmbrace;
	ssym[']'] = rmbrace;
	ssym['='] = becomes;
	ssym['#'] = sharpsym;
	ssym['!'] = not;
	
	/* 设置保留字名字，按照字母顺序，便于二分查找 */
	strcpy(&(word[0][0]), "bool");
	strcpy(&(word[1][0]), "char");
	strcpy(&(word[2][0]), "const");
	strcpy(&(word[3][0]), "continue");
	strcpy(&(word[4][0]), "do");
	strcpy(&(word[5][0]), "double");
	strcpy(&(word[6][0]), "else");
	strcpy(&(word[7][0]), "exit");
	strcpy(&(word[8][0]), "false");
	strcpy(&(word[9][0]), "for");
	strcpy(&(word[10][0]), "if");
	strcpy(&(word[11][0]), "int");
	strcpy(&(word[12][0]), "main");
	strcpy(&(word[13][0]), "odd");
	strcpy(&(word[14][0]), "read");
	strcpy(&(word[15][0]), "repeat");
	strcpy(&(word[16][0]), "return");
	strcpy(&(word[17][0]), "switch");
	strcpy(&(word[18][0]), "true");
	strcpy(&(word[19][0]), "while");
	strcpy(&(word[20][0]), "write");
	strcpy(&(word[21][0]), "xor");

	wsym[0] = boolsym;
	wsym[1] = charsym;
	wsym[2] = constsym;
	wsym[3] = continuesym;
	wsym[4] = dosym;
	wsym[5] = doublesym;
	wsym[6] = elsesym;
	wsym[7] = exitsym;
	wsym[8] = falsesym;
	wsym[9] = forsym;
	wsym[10] = ifsym;
	wsym[11] = intsym;
	wsym[12] = mainsym;
	wsym[13] = oddsym;
	wsym[14] = readsym;
	wsym[15] = repeatsym;
	wsym[16] = returnsym;
	wsym[17] = switchsym;
	wsym[18] = truesym;
	wsym[19] = whilesym;
	wsym[20] = writesym;
	wsym[21] = xor;
}