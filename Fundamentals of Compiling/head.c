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
int backupnum = 0;
struct backup backupsave[maxbackup];

int cx;				/*���������ָ�룬ȡֵ��Χ[0, cxmax-1]*/
char memonic[fctcodenum][5];	/*���������ָ������*/
bool declbegsys[symnum];    /* ��ʾ������ʼ�ķ��ż��� */
bool statbegsys[symnum];    /* ��ʾ��俪ʼ�ķ��ż��� */
bool facbegsys[symnum];     /* ��ʾ���ӿ�ʼ�ķ��ż��� */
struct functioninfo fctinfo[maxfunction];	/*���ÿ����������Ϣ*/
int fctnum;		//��������Ŀ
struct tablestruct table[txmax];

FILE* fin;
FILE* foutput;
char fname[al];