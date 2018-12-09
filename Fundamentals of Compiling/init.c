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
	strcpy(&(word[0][0]), "char");
	strcpy(&(word[1][0]), "else");
	strcpy(&(word[2][0]), "if");
	strcpy(&(word[3][0]), "int");
	strcpy(&(word[4][0]), "main");
	strcpy(&(word[5][0]), "read");
	strcpy(&(word[6][0]), "while");
	strcpy(&(word[7][0]), "write");
	
	wsym[0] = charsym;
	wsym[1] = elsesym;
	wsym[2] = ifsym;
	wsym[3] = intsym;
	wsym[4] = mainsym;
	wsym[5] = readsym;
	wsym[6] = whilesym;
	wsym[7] = writesym;
}