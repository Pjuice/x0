#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int 
#define true 1
#define false 0

#define norw 26			//�����ֵĸ���
#define txmax 100		//���ű�����
#define al 10			//��ʶ������󳤶�
#define nmax 14			//���ֵ����λ��
#define maxbackup 100	//���ݵ�������
#define maxerr 30		//�������������
#define amax 2048		//��ַ�Ͻ�
#define levmax 3		//����������Ƕ����������
#define	cxmax 200		//���������������
#define stacksize 500	//����ʱ����ջԪ�����Ϊ500��
#define fctcodenum 11	//���������ָ�����
#define symnum 65		//���ŵĸ���
#define maxdimension 10	//���ά��
#define maxfunction 100 //���ĺ�����Ŀ

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
	repeatsym, returnsym, exitsym, continuesym, not,
	incre, decre,xor,modsym, oversym
};

/* ���ű��е����� */
enum object
{
	intvar, constintvar, intarray,
	doublevar, constdoublevar, doublearray,
	charvar, constcharvar, chararray,
	boolvar, constboolvar, boolarray
};

/* ���������ָ�� */
enum fct 
{
	lit, opr, lod,
	sto, cal, ini,
	jmp, jpc, add,
	sub, tad
};

/* ���������ṹ */
struct instruction
{
	enum fct f; /* ���������ָ�� */
	int l;      /* ���ò���������Ĳ�β� */
	int a;      /* ����f�Ĳ�ͬ����ͬ */
};

extern char ch;					/* ��ŵ�ǰ��ȡ���ַ���getch ʹ�� */
extern enum symbol sym;			/* ��ǰ�ķ��� */
extern char id[al + 1];			/* ��ǰident�������һ���ֽ����ڴ��0 */
extern int intNum;				/* ��ǰ����numberֵ */
extern double doublenumber;		/* ��ǰ������numberֵ */
extern int cc, ll;				/* getchʹ�õļ�������cc��ʾ��ǰ�ַ�(ch)��λ�� */
extern char line[81];			/* ��ȡ�л����� */
extern char a[al + 1];			/* ��ʱ���ţ������һ���ֽ����ڴ��0 */
extern char word[norw][al];		/* �����֣�13�������֣�ÿ���Ϊ10 */
extern enum symbol wsym[norw];	/* �����ֶ�Ӧ�ķ���ֵ */
extern enum symbol ssym[256];	/* ���ַ��ķ���ֵ */
extern int backupnum;			/* ��ǰbackup������λ�� */
extern struct backup backupsave[maxbackup];	/*���ÿ�α���ֵ*/

extern int cx;						/*���������ָ�룬ȡֵ��Χ[0, cxmax-1]*/
extern char memonic[fctcodenum][5];		/*���������ָ������*/
extern bool declbegsys[symnum];     /* ��ʾ������ʼ�ķ��ż��� */
extern bool statbegsys[symnum];     /* ��ʾ��俪ʼ�ķ��ż��� */
extern bool facbegsys[symnum];      /* ��ʾ���ӿ�ʼ�ķ��ż��� */
extern struct functioninfo fctinfo[maxfunction];	/*���ÿ����������Ϣ*/
extern int fctnum;		//��������Ŀ

struct tablestruct
{
	char name[al];
	enum object kind;
	int offset;
	int size[maxdimension];
	int d;
	double value;
};

/*����ֵ������*/
 enum rettype
{
	retvoid, retint, retdouble, retchar, retbool
};

 /*�洢��������Ϣ*/
struct functioninfo
{
	char name[al + 1];
	struct tablestruct symtable[txmax];  /* symbol table of the function */
	int tablesize;                         /* size of the symbol table */
	int paranum;		                   /* number of parameters */
	int startintcode;		               /* position where the function starts in intermediate code */
	enum rettype returntype;                       /* type of return value */
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

};

extern struct tablestruct table[txmax];

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
void return_stat();
void simple_value();
void simple_var(int *ptr_offset, int *ptr_kind);
void switch_stat();
void term();
void value_expr();
void variable(enum object*ptr_kind, int *ptr_offset);
void backup();
void rollback();

void enter(enum object k, int offset, int* size, int d, double value);
int positionbyidentname(char* identname, int pos);
int positionbyoffset(int offset, int pos);
int positionbyfctname(char* fctname);

