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
int backupnum = 0;
struct backup backupsave[maxbackup];

int cx;				/*虚拟机代码指针，取值范围[0, cxmax-1]*/
char memonic[fctcodenum][5];	/*虚拟机代码指令名称*/
bool declbegsys[symnum];    /* 表示声明开始的符号集合 */
bool statbegsys[symnum];    /* 表示语句开始的符号集合 */
bool facbegsys[symnum];     /* 表示因子开始的符号集合 */
struct functioninfo fctinfo[maxfunction];	/*存放每个函数的信息*/
int fctnum;		//函数的数目
struct tablestruct table[txmax];

FILE* fin;
FILE* foutput;
char fname[al];