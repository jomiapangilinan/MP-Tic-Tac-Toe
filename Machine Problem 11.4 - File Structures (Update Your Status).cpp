//Machine Problem #11.4 In Data & File Structures 
//Program Name: File Structures - Update Your Status
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
char transac[20], master[20], fblank, fnum[11], fdes[30], fcode, fedit;
float fpri;
int success=0, sadd=0, scha=0, sdel=0, iadd=0, icha=0, idel=0, icode=0, total=0;
void titulo ()
{printf("\n\n     -------------------------------------------------------------------- \n");
printf("    |                                                                    |\n");
printf("    | F I L E  S T R U C T U R E S  -  U P D A T E  Y O U R  S T A T U S |\n");
printf("    |                                                                    |\n");
printf("     -------------------------------------------------------------------- \n");
}
void add ()
{FILE *mf;
mf=fopen (master, "a");
fprintf (mf, "\n%s ", fnum);
fprintf (mf, "%s !! ", fdes);
fprintf (mf, "%.2f", fpri);
fclose(mf);
}
void change ()
{FILE *mf, *temp;
char mblank, mnum[11], mdes[30], bdes[30]="", line[100];
int i=0, x;
float mpri;	
mf=fopen(master, "r");
temp=fopen("buffer.txt", "w");
while (!feof(mf))
	{if (i!=0)
		{fscanf(mf, "%s", mnum);
		char pdes[30]="";
		for (x=0;;)
			{fscanf(mf, "%s", mdes);
			if (strstr(mdes, "!!")==NULL)
				{strcat(pdes, mdes);
				strcat(pdes, " ");
				}
			else
				{strcpy(bdes, pdes);
				break;
				}
			x++;
			}
		fscanf(mf, "%f", &mpri);
		if (strstr(mnum, fnum)!=NULL)
			{if (toupper(fedit)=='E')
				{fprintf(temp, "\n%s %s !! %.2f", mnum, fdes, mpri);					
				}
			if (toupper(fedit)=='P')
				{fprintf(temp, "\n%s %s !! %.2f", mnum, bdes, fpri);					
				}
			}
		else
			{fprintf(temp, "\n%s %s !! %.2f", mnum, bdes, mpri);
			}		
		}
	if (i==0)
		{fscanf(mf, "%c", &mblank);	
		}
	i++;
	}
fclose(mf);
fclose(temp);
mf=fopen(master, "w");
temp=fopen("buffer.txt", "r");
while (!feof(temp))
	{fgets(line, sizeof line, temp);
	fprintf(mf, "%s", line);
	}
fclose(mf);
fclose(temp);
remove("buffer.txt");
}
void del ()
{FILE *mf, *temp;
char mblank, mnum[11], mdes[30], bdes[30]="", line[100];
int i=0, x;
float mpri;	
mf=fopen(master, "r");
temp=fopen("buffer.txt", "w");
while (!feof(mf))
	{if (i!=0)
		{fscanf(mf, "%s", mnum);
		char pdes[30]="";
		for (x=0;;)
			{fscanf(mf, "%s", mdes);
			if (strstr(mdes, "!!")==NULL)
				{strcat(pdes, mdes);
				strcat(pdes, " ");
				}
			else
				{strcpy(bdes, pdes);
				break;
				}
			x++;
			}
		fscanf(mf, "%f", &mpri);
		if (strstr(mnum, fnum)==NULL)
			{fprintf(temp, "\n%s %s !! %.2f", mnum, bdes, mpri);
			}		
		}
	if (i==0)
		{fscanf(mf, "%c", &mblank);	
		}
	i++;
	}
fclose(mf);
fclose(temp);
mf=fopen(master, "w");
temp=fopen("buffer.txt", "r");
while (!feof(temp))
	{fgets(line, sizeof line, temp);
	fprintf(mf, "%s", line);
	}
fclose(mf);
fclose(temp);
remove("buffer.txt");
}
void comp ()
{FILE *mf;
char mblank, mnum[11], mdes[30], bdes[30]="";
int i=0, x;
float mpri;
success*=0;	
mf=fopen(master, "r");
while (!feof(mf))
	{if (i!=0)
		{fscanf(mf, "%s", mnum);
		char pdes[30]="";
		for (x=0;;)
			{fscanf(mf, "%s", mdes);
			if (strstr(mdes, "!!")==NULL)
				{strcat(pdes, mdes);
				strcat(pdes, " ");
				}
			else
				{strcpy(bdes, pdes);
				break;
				}
			x++;
			}
		fscanf(mf, "%f", &mpri);
		if (strstr(mnum, fnum)!=NULL)
			{success+=1;
			}
		}	
	else
		{fscanf(mf, "%c", &mblank);
		}
	i++;
	}
fclose(mf);
if (toupper(fcode)=='A')
	{if (success==0)
		{add ();
		printf("\n%c\t\t%s    ", fcode, fnum);
		printf("\t\t       %s;  %.2f", fdes,fpri);
		sadd++;
		}
	else
		{printf("\n%c\t\t%s    ", fcode, fnum);
		printf("INVALID ADD-ALREADY ON FILE");
		iadd++;
		}
	}
if (toupper(fcode)=='C')
	{if (success==1)
		{change ();
		printf("\n%c\t\t%s    ", fcode, fnum);				
		if (toupper(fedit)=='E')
			{printf("\t\t       Desc-%s", fdes);
			}
		if (toupper(fedit)=='P')
			{printf("\t\t       Price-%.2f", fpri);
			}
		scha++;
		}
	else
		{printf("\n%c\t\t%s    ", fcode, fnum);
		printf("INVALID CHANGE-NOT ON FILE");			
		icha++;
		}
	}
if (toupper(fcode)=='D')
	{if (success==1)
		{del ();
		printf("\n%c\t\t%s    ", fcode, fnum);			
		sdel++;
		}
	else
		{printf ("\n%c\t\t%s    ", fcode, fnum);
		printf ("INVALID DELETE-NOT ON FILE");			
		idel++;
		}
	}
total++;
}
void read ()
{FILE *fp;
char garb[20], tdes[30];
int i=0, x;	
fp=fopen(transac, "r");
while (!feof(fp))
	{if (i!=0)
		{fscanf(fp, "%c ", &fcode);
		if (toupper(fcode)=='A')
			{strcpy(tdes, "");
			fscanf(fp, "%s", fnum);
			for (x=0;;)
				{fscanf(fp, "%s", fdes);
				if (strstr(fdes, "!!")==NULL)
					{strcat(tdes, fdes);
					strcat(tdes, " ");	
					}
				else
					{strcpy(fdes, tdes);
					break;
					}
				x++;
				}
			fscanf(fp, "%f", &fpri);
			comp ();
			}
		else if (toupper(fcode)=='C')
			{fscanf(fp, "%c", &fedit);
			fscanf(fp, "%s", fnum);
			printf("\n%s", fnum);
			if (toupper(fedit)=='E')
				{char tdes[30]="";
				for (x=0;;)
					{fscanf(fp, "%s", fdes);
					if (strstr(fdes, "!!")==NULL)
						{strcat(tdes, fdes);
						strcat(tdes, " ");
						}
					else
						{strcpy(fdes, tdes);
						break;
						}
					x++;
					}
				}
			if (toupper(fedit)=='P')
				{fscanf(fp, "%f", &fpri);
				}
			comp();
			}
		else if (toupper(fcode)=='D')
			{fscanf(fp, "%s", fnum);
			comp ();
			}
		else
			{if (fcode!='\n'&&fcode!=' ')
				{printf("\n%c\t\t\t      ", fcode);
				printf("Invalid Code\n");	
				for (x=0;;)
					{fscanf(fp, "%s", garb);
					if (strstr(garb, "!!")!=NULL)
						{break;
						}
					x++;
					}
				icode++;
				}
			}
		}
	if (i==0)
		{fscanf(fp, "%c", &fblank);
		}
	i++;
	}
fclose(fp);	
}
int main ()
{titulo ();
SYSTEMTIME str_t;
GetSystemTime (&str_t);
printf("\nEnter master file: ");
scanf("%s", master);
printf("Enter transaction file: ");
scanf("%s", transac);
system("cls");
printf("\t\t\t\tXYZ Company\n");
printf("Date: %d/%d/%d", str_t.wMonth, str_t.wDay, str_t.wYear);
printf("\t\t\t\t\t\t\tPage 1 of 1");
printf("\n\n\t\t\t      Audit/Error List");
printf("\nUpdate Code\tPart Number   Error Message    Remarks");
read ();
printf("\n\n\t\t\t\t\tTotal No. of Successful Adds: %d\n\t\t\t\t\tTotal No. of Successful Change: %d\n\t\t\t\t\tTotal No. of Successful Delete: %d", sadd, scha, sdel);
printf("\n\n\t\t\t\t\tTotal No. of Invalide Adds: %d\n\t\t\t\t\tTotal No. of Invalid Change: %d\n\t\t\t\t\tTotal No. of Invalid Delete: %d", iadd, icha, idel);	
printf("\n\t\t\t\t\tTotal No. of Invalid Codes: %d", icode);
printf("\nTotal lines printed (not including headers but including tally): %d lines", total+7);
getch();
}
