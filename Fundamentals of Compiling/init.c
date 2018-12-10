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
	
	/* 设置保留字名字，按照字母顺序，便于二分查找 */
	strcpy(&(word[0][0]), "bool");
	strcpy(&(word[1][0]), "char");
	strcpy(&(word[2][0]), "const");
	strcpy(&(word[3][0]), "double");
	strcpy(&(word[4][0]), "else");
	strcpy(&(word[5][0]), "false");
	strcpy(&(word[6][0]), "if");
	strcpy(&(word[7][0]), "int");
	strcpy(&(word[8][0]), "main");
	strcpy(&(word[9][0]), "read");
	strcpy(&(word[10][0]), "true");
	strcpy(&(word[11][0]), "while");
	strcpy(&(word[12][0]), "write");
	
	wsym[0] = boolsym;
	wsym[1] = charsym;
	wsym[2] = constsym;
	wsym[3] = doublesym;
	wsym[4] = elsesym;
	wsym[5] = falsesym;
	wsym[6] = ifsym;
	wsym[7] = intsym;
	wsym[8] = mainsym;
	wsym[9] = readsym;
	wsym[10] = truesym;
	wsym[11] = whilesym;
	wsym[12] = writesym;
}