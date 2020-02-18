//Machine Problem #11.3 In Data & File Structures 
//Program Name: File Structures - Transacticons
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <string.h>
struct record
	{char update;
	char num[50];
	char desc[50];
	float price;
	}part;
void titulo ()
{printf("\n\n\t ------------------------------------------------------------ \n");
printf("\t|                                                            |\n");
printf("\t| F I L E  S T R U C T U R E S   -   T R A N S A C T I O N S |\n");
printf("\t|                                                            |\n");
printf("\t ------------------------------------------------------------ \n");
}
char filename[]="transac.txt";
int main()
{titulo ();
time_t now;
time(&now);
struct tm* now_time;
now_time=localtime(&now);
char choice, ch;
char yr[20];
int iyr;
char ntrydt[80];
FILE *transfile;
transfile=fopen(filename, "a");
if (transfile==NULL)
	{printf("File does not exist!");
	}
strftime(ntrydt, 80, "%m%d", now_time);
strftime(yr, 20, "%Y", now_time);
iyr=atoi(yr);
iyr%=100;
itoa(iyr, yr, 10);
strcat(ntrydt, yr);
do
	{part.update='\0';
	printf("\n%s", __DATE__);
	printf("\nUpdate Code: ");
	part.update=getche();
	if (toupper(part.update)=='A')
		{printf("\nPart number: ");
		scanf("%s", &part.num);
		printf("\nPart description: ");
		scanf("%s", &part.desc);
		printf("\nPart price: ");
		scanf("%f", &part.price);	
		fprintf(transfile, "%c\n%10s\n%26s\n%6.2f\n", toupper(part.update), part.num, part.desc, part.price);
		fputs(ntrydt, transfile);
		fprintf(transfile,"\n");
		}
	else if (toupper(part.update) == 'C')
		{printf("\nPart number: ");
		scanf("%s", &part.num);
		HERE: printf("\nChange ID: ");
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
			goto HERE;
			}
		fprintf(transfile, "%c\n%10s\n%26s\n%6.2f\n", toupper(part.update), part.num, part.desc, part.price);
		fputs(ntrydt, transfile);
		fprintf(transfile,"\n");	
		}
	else if (toupper(part.update)=='D')
		{printf("\nPart number: ");
		scanf("%s", part.num);
		fprintf(transfile, "%c\n%10s\n%26s\n%6.2f\n", toupper(part.update), part.num, part.desc, part.price);
		fputs(ntrydt, transfile);
		fprintf(transfile,"\n");
		}
	else
		{fprintf(transfile, "%c\n%10s\n%26s\n%6.2f\n", toupper(part.update), part.num, part.desc, part.price);
		fputs(ntrydt, transfile);
		fprintf(transfile,"\n");
		}
	printf("\nAnother transaction?[Y/N]: ");
	choice=getch();
	}
while(toupper(choice)=='Y');
fclose(transfile);
printf("\nAll transactions are saved in %s... Press any key to continue.", filename);
getch();
}
