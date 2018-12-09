#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int 
#define true 1
#define false 0

#define norw 8
#define txmax 100
#define al 10
#define nmax 14

enum symbol
{
	nul, ident, number, plus, minus,
	times, slash, oddsym, eql, neq,
	lss, leq, gtr, geq, lparen,
	rparen, comma, semicolon, period, becomes, 
	mainsym, endsym, ifsym, thensym, whilesym,
	writesym, readsym, dosym, callsym, constsym,
	varsym, procsym, lbrace, rbrace, lmbrace, 
	rmbrace, charsym, elsesym, intsym,sharpsym
};

enum object
{
	integer,
	character,
	intarray,
	chararray
};

char ch;
enum symbol sym;
char id[al + 1];
int num;
int cc, ll;
char line[81];
char a[al + 1];
char word[norw][al];	/* 保留字，13个保留字，每个最长为10 */
enum symbol wsym[norw];	/* 保留字对应的符号值 */
enum symbol ssym[256];	/* 单字符的符号值 */
 
struct tablestruct
{
	char name[al];
	enum object kind;
};

struct tablestruct table[txmax];

FILE* fin;
FILE* foutput;
char fname[al];

void error(int n);
void getsym();
void getch();
void init();
void declaration_list(int tx);
void enter(enum object k, int* ptx);
void declaration(int* ptx);
void statement_list(int *ptx);
int position(char* id, int tx);
void statement(int *ptx);
void if_stat(int *ptx);
void while_stat(int *ptx);
void read_stat(int *ptx);
void var(int *ptx);


