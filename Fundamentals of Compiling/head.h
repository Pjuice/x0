#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int 
#define true 1
#define false 0

#define norw 26
#define txmax 100
#define al 10
#define nmax 14
#define maxbackup 100


enum symbol
{
	nul, ident, number, plus, minus,untilsym,
	times, slash, oddsym, eql, neq,
	lss, leq, gtr, geq, lparen, colon,breaksym,
	rparen, comma, semicolon, period, becomes, 
	mainsym, endsym, ifsym, thensym, whilesym,
	writesym, readsym, dosym, callsym, constsym,
	varsym, procsym, lbrace, rbrace, lmbrace, casesym,
	rmbrace, charsym, elsesym, intnum,sharpsym,andsym,orsym, intsym,
	doublesym, boolsym, truesym, falsesym, switchsym, forsym, defaultsym, doublenum,
	repeatsym, returnsym, exitsym, continuesym, not, incre, decre,xor,modsym, oversym
};

enum object
{
	integer,
	character,
	intarray,
	chararray
};

extern char ch;
extern enum symbol sym;
extern char id[al + 1];
extern int intNum;
extern double doublenumber;
extern int cc, ll;
extern char line[81];
extern char a[al + 1];
extern char word[norw][al];	/* 保留字，13个保留字，每个最长为10 */
extern enum symbol wsym[norw];	/* 保留字对应的符号值 */
extern enum symbol ssym[256];	/* 单字符的符号值 */
extern int backupnum;
extern struct backup backupsave[maxbackup];

struct tablestruct
{
	char name[al];
	enum object kind;
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

struct tablestruct table[txmax];

FILE* fin;
FILE* foutput;
char fname[al];

void error(int n);
void getsym();
void getch();
void init();
void enter(enum object k, int* ptx);
void statement_list();
int position(char* id, int tx);
void statement( );
void if_stat();
void while_stat();
void read_stat();
void write_stat();
void compound_stat();
void expression_stat();
void expression();
void constdeclaration_list();
void constdeclaration_stat();
void vardeclaration_stat();
void vardeclaration_list();
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
void simple_var();
void switch_stat();
void term();
void value_expr();
void vardeclaration_list();
void vardeclaration_stat();
void variable();
void backup();
void rollback();


