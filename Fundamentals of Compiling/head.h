#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int 
#define true 1
#define false 0

#define norw 26			//保留字的个数
#define txmax 100		//符号表容量
#define al 20			//标识符的最大长度
#define nmax 14			//数字的最大位数
#define maxbackup 100	//备份的最大个数
#define maxerr 30		//允许的最多错误数
#define amax 2048		//地址上界
#define	cxmax 200		//最多的虚拟机代码数
#define maxstacksize 500	//运行时数据栈元素最多为500个
#define fctcodenum 11	//虚拟机代码指令个数
#define symnum 65		//符号的个数
#define maxdimension 10	//最大维度
#define maxfunction 100 //最大的函数数目
#define maxcode		1000	//中间代码的最大数
#define maxcodelen	5	//中间代码操作符的最大长度
#define maxctn 1000		//continue数组的最大长度
#define maxbrk 1000		//break数组的最大长度


enum symbol
{
	nul, ident, number, plus, minus,
	untilsym, times, slash, oddsym, eql, 
	neq, lss, leq, gtr, geq, 
	lparen, colon, breaksym, rparen, comma, 
	semicolon, period, becomes, mainsym, endsym, 
	ifsym, thensym, whilesym, writesym, readsym, 
	dosym, callsym, constsym, varsym, procsym,
	lbrace, rbrace, lmbrace, casesym, rmbrace,
	charsym, elsesym, intnum,sharpsym,andsym,
	orsym, intsym, doublesym, boolsym, truesym, 
	falsesym, switchsym, forsym, defaultsym, doublenum,
	repeatsym, returnsym, exitsym, continuesym, notsym,
	incre, decre,xorsym,modsym, oversym
};

/* 符号表中的类型 */
enum object
{
	intvar, constintvar, intarray,
	doublevar, constdoublevar, doublearray,
	charvar, constcharvar, chararray,
	boolvar, constboolvar, boolarray
};

/* 虚拟机代码指令 */
enum fct 
{
	lit, opr, lod,
	sto, cal, ini,
	jmp, jpc, add,
	sub, tad
};

/* 虚拟机代码结构 */
struct codeins
{
	enum fct f; /* 虚拟机代码指令 */
	int opr1;      
	double opr2;      
};

extern char ch;					/* 存放当前读取的字符，getch 使用 */
extern enum symbol sym;			/* 当前的符号 */
extern char id[al + 1];			/* 当前ident，多出的一个字节用于存放0 */
extern int intNum;				/* 当前整数number值 */
extern double doublenumber;		/* 当前浮点数number值 */
extern int cc, ll;				/* getch使用的计数器，cc表示当前字符(ch)的位置 */
extern char line[81];			/* 读取行缓冲区 */
extern char a[al + 1];			/* 临时符号，多出的一个字节用于存放0 */
extern char word[norw][al];		/* 保留字，13个保留字，每个最长为10 */
extern enum symbol wsym[norw];	/* 保留字对应的符号值 */
extern enum symbol ssym[256];	/* 单字符的符号值 */
extern int backupnum;			/* 当前backup函数的位置 */
extern struct backup backupsave[maxbackup];	/*存放每次备份值*/

extern int cx;						/*虚拟机代码指针，取值范围[0, cxmax-1]*/
extern char memonic[fctcodenum][5];		/*虚拟机代码指令名称*/
extern bool declbegsys[symnum];     /* 表示声明开始的符号集合 */
extern bool statbegsys[symnum];     /* 表示语句开始的符号集合 */
extern bool facbegsys[symnum];      /* 表示因子开始的符号集合 */
extern struct functioninfo fctinfo[maxfunction];	/*存放每个函数的信息*/
extern int fctnum;		//函数的数目
extern int codenum;		

struct tablestruct
{
	char name[al+1];
	enum object kind;
	int offset;
	int size[maxdimension];
	int d;
	double value;
};

/*返回值的类型*/
 enum rettype
{
	retvoid, retint, retdouble, retchar, retbool
};

 enum datatype
 {
	 Nul, Int, Double, Char, Bool
 };

 /*存储函数的信息*/
struct functioninfo
{
	char name[al + 1];
	struct tablestruct symtable[txmax];  /* 该函数的符号表 */
	int tablesize;                         /* 符号表的大小 */
	int paranum;		                   /* 参数的个数 */
	int startintcode;		               /* 该函数在code表中的起始位置 */
	enum rettype returntype;                       /* 返回值的类型 */
};

 struct backup
{
	FILE* backupfin;
	char backupch;
	enum symbol backupsym;
	int backupcc;
	int backupll;
	char backupline[81];
	char backupid[al + 1];
	int backupcode;
	double backupdoublenum;           
	int backupintnum;
};

extern struct tablestruct table[txmax];
extern struct codeins code[maxcode];
extern FILE* fin;
extern FILE* foutput;
extern char fname[al];

void error(int n);
void getsym();
void getch();
void init();
void statement_list();
void statement( );
void if_stat();
void while_stat();
void read_stat();
void write_stat();
void compound_stat();
void expression_stat();
void expression();
void constdeclaration_list(int *ptr_offset);
void constdeclaration_stat(int *ptr_offset);
void vardeclaration_stat(int *ptr_offset);
void vardeclaration_list(int *ptr_offset);
void addict_expr();
void break_stat();
void continue_stat();
void dowhile_stat();
void exit_stat();
void factor();
void for_stat();
void repeat_stat();
void simple_value();
void simple_var(int *ptr_offset, enum  object*ptr_kind);
void switch_stat();
void term();
void value_expr();
void variable(enum object*ptr_kind, int *ptr_offset);
void backup();
void rollback();
void gen(enum fct f, int opr1, double opr2);
void interpret();

void enter(enum object k, int offset, int* size, int d, double value);

int position(char* identname, int pos);
int position(int offset, int pos);


extern int ctnnum;
extern int brknum;
extern int ctnlist[maxctn];
extern int brklist[maxbrk];

extern char fctcodestring[fctcodenum][maxcodelen];