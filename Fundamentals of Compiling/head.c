#include "head.h"

char ch;
enum symbol sym;
char id[al + 1];
int intNum;
double doublenumber;
int cc, ll;
char line[81];
char a[al + 1];
char word[norw][al];	/* �����֣�13�������֣�ÿ���Ϊ10 */
enum symbol wsym[norw];	/* �����ֶ�Ӧ�ķ���ֵ */
enum symbol ssym[256];	/* ���ַ��ķ���ֵ */