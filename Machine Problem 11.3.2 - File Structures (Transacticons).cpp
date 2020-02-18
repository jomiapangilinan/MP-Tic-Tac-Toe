//Machine Problem #11.4 In Data & File Structures 
//Program Name: File Structures - Transactions
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#include<string.h>
struct rec
	{char update, num[10], desc[26];
	float price;
	}part;
char file[]="transac.txt";
int main()
{time_t now;
time(&now);
struct tm* now_tm;
now_tm=localtime(&now);
char choice, ch, year[20], entrd[80];
int iyear;
FILE *trans;
trans=fopen(file, "a");
strftime(entrd, 80, " %m%d", now_tm);
strftime(year, 20, "%Y", now_tm);
iyear=atoi(year);
iyear%=100;
itoa(iyear, year, 10);
strcat(entrd, year);
do
	{part.update='\0';
	printf("\n\n%s", __DATE__);
	printf("\nUpdate Code: ");
	part.update=getche();
	if (toupper(part.update)=='A')
		{printf("\nPart number: ");
		scanf("\n%s", &part.num);
		printf("\nPart description: ");
		scanf("%s", &part.desc);
		printf("\nPart price: ");
		scanf("%f", &part.price);	
		fprintf(trans, "%c %10s %26s %6.2f ", toupper(part.update), part.num, part.desc, part.price);
		fputs(entrd, trans);
		fprintf(trans, "\n");
		}
	else if (toupper(part.update)=='C')
		{printf("\nPart number: ");
		scanf("%s", &part.num);
		st1: printf("\nChange ID: ");
		ch=getche();
		if (toupper(ch)=='D')
			{printf("\nPart description: ");
			scanf("%s", &part.desc);
			}
		else if (toupper(ch)=='P')
			{printf("\nPart price: ");
			scanf("%f", &part.price);	
			}
		else
			{printf("\nInvalid Input!\n");
			goto st1;
			}
		fprintf(trans, "%c %10s %26s %6.2f ", toupper(part.update), part.num, part.desc, part.price);
		fputs(entrd, trans);
		fprintf(trans, "\n");	
		}
	else if (toupper(part.update)=='D')
		{printf("\nPart number: ");
		scanf("%s", part.num);
		fprintf(trans, "%c %10s %26s %6.2f ", toupper(part.update), part.num, part.desc, part.price);
		fputs(entrd, trans);
		fprintf(trans, "\n");
		}
	else
		{fprintf(trans, "%c %10s %26s %6.2f ", toupper(part.update), part.num, part.desc, part.price);
		fputs(entrd, trans);
		fprintf(trans, "\n");
		}
	printf("\nAnother transaction?[Y/N]: ");
	choice=getch();	
	}
while (toupper(choice)=='Y');
fclose(trans);
printf("\nAll transactions are saved in %s.\n",file);
getch();
}
