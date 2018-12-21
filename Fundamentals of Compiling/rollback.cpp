#include "head.h"

void rollback()
{
	backupnum--;

	fin = backupsave[backupnum].backupfin;
	ch = backupsave[backupnum].backupch;
	sym = backupsave[backupnum].backupsym;
	cc = backupsave[backupnum].backupcc;
	ll = backupsave[backupnum].backupll;
	doublenumber = backupsave[backupnum].backupdoublenum;
	intNum = backupsave[backupnum].backupintnum;
	codenum = backupsave[backupnum].backupcode;

	strcpy(id, backupsave[backupnum].backupid);

	for (int i = 0; i < 81; i++)
	{
		line[i] = backupsave[backupnum].backupline[i];
	}
}