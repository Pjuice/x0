#include "head.h"

char ch;
enum symbol sym;
char id[al + 1];
int intNum;
double doublenumber;
int cc, ll;
char line[81];
char a[al + 1];
char word[norw][al];	/* 保留字，13个保留字，每个最长为10 */
enum symbol wsym[norw];	/* 保留字对应的符号值 */
enum symbol ssym[256];	/* 单字符的符号值 */