#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backup()
{
	backupsave[backupnum].backupfin = fin;
	backupsave[backupnum].backupch = ch;
	backupsave[backupnum].backupsym = sym;
	backupsave[backupnum].backupcc = cc;
	backupsave[backupnum].backupll = ll;
	strcpy(backupsave[backupnum].backupid, id);

	for (int i = 0; i < 81; i++)
	{
		backupsave[backupnum].backupline[i] = line[i];
	}

	backupnum++;
}