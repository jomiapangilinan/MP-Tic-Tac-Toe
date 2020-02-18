//Machine Problem #11.1 In Data & File Structures 
//Program Name: File Structures - Meet My Master
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
struct masterrecord
	{float partprice;
	char partnum[50], partdesc[50];
	}mast;
	
void titulo ()
{printf("\n\n\t ------------------------------------------------------------ \n");
printf("\t|                                                            |\n");
printf("\t| F I L E  S T R U C T U R E S  -  M E E T  M Y  M A S T E R |\n");
printf("\t|                                                            |\n");
printf("\t ------------------------------------------------------------ \n");
}

int main()
{
FILE *mastfile;
char ans;
titulo ();
mastfile=fopen("master.txt", "w");
do
	{printf("\nPart Number: ");
	scanf("%s", mast.partnum);
	printf("Part Description: ");
	scanf("%s", mast.partdesc);
	printf("Part Price: ");
	scanf("%f", &mast.partprice);
	fprintf(mastfile, "%10s\t%24s\t%.2f\n", mast.partnum, mast.partdesc, mast.partprice);

	printf("Another [Y/N]?: ");
	ans=getche();
	} 
while (toupper(ans)=='Y');
printf("\nTransactions saved. Press any key to continue...");
fclose(mastfile);
mastfile=fopen("master.txt", "r");
printf("\nPart Number\t\tPart Description\t\t\tPart Price\n");
while (fscanf(mastfile, "%s%s%f", mast.partnum, mast.partdesc, &mast.partprice)!=EOF)
	{printf("%10s\t", mast.partnum);
	printf("\t%24s\t", mast.partdesc);
	printf("\t%.2f\n", mast.partprice);
	}
fclose(mastfile);
getch();
}
