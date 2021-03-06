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
	ssym['!'] = notsym;
	ssym['%'] = modsym;
	ssym[':'] = colon;
	ssym['$'] = oversym;

	/* 设置保留字名字，按照字母顺序，便于二分查找 */
	strcpy(&(word[0][0]), "bool");
	strcpy(&(word[1][0]), "break");
	strcpy(&(word[2][0]), "case");
	strcpy(&(word[3][0]), "char");
	strcpy(&(word[4][0]), "const");
	strcpy(&(word[5][0]), "continue");
	strcpy(&(word[6][0]), "default");
	strcpy(&(word[7][0]), "do");
	strcpy(&(word[8][0]), "double");
	strcpy(&(word[9][0]), "else");
	strcpy(&(word[10][0]), "exit");
	strcpy(&(word[11][0]), "false");
	strcpy(&(word[12][0]), "for");
	strcpy(&(word[13][0]), "if");
	strcpy(&(word[14][0]), "int");
	strcpy(&(word[15][0]), "main");
	strcpy(&(word[16][0]), "odd");
	strcpy(&(word[17][0]), "read");
	strcpy(&(word[18][0]), "repeat");
	strcpy(&(word[19][0]), "return");
	strcpy(&(word[20][0]), "switch");
	strcpy(&(word[21][0]), "true");
	strcpy(&(word[22][0]), "until");
	strcpy(&(word[23][0]), "while");
	strcpy(&(word[24][0]), "write");
	strcpy(&(word[25][0]), "xor");

	wsym[0] = boolsym;
	wsym[1] = breaksym;
	wsym[2] = casesym;
	wsym[3] = charsym;
	wsym[4] = constsym;
	wsym[5] = continuesym;
	wsym[6] = defaultsym;
	wsym[7] = dosym;
	wsym[8] = doublesym;
	wsym[9] = elsesym;
	wsym[10] = exitsym;
	wsym[11] = falsesym;
	wsym[12] = forsym;
	wsym[13] = ifsym;
	wsym[14] = intsym;
	wsym[15] = mainsym;
	wsym[16] = oddsym;
	wsym[17] = readsym;
	wsym[18] = repeatsym;
	wsym[19] = returnsym;
	wsym[20] = switchsym;
	wsym[21] = truesym;
	wsym[22] = untilsym;
	wsym[23] = whilesym;
	wsym[24] = writesym;
	wsym[25] = xorsym;

}