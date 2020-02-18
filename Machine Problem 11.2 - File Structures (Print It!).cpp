//Machine Problem #11.2 In Data & File Structures 
//Program Name: File Structures - Print It!
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct masterrecord
	{char partnum[50], partdesc[50];
	float partprice;
	}mast;
void titulo ()
{printf("\n\n\t\t --------------------------------------------------- \n");
printf("\t\t|                                                   |\n");
printf("\t\t| F I L E  S T R U C T U R E S  -  P R I N T  I T ! |\n");
printf("\t\t|                                                   |\n");
printf("\t\t --------------------------------------------------- \n");
}
int main ()
{FILE *mastfile, *temp;
char ans, filename[12], option;
titulo ();
printf("\n\nEnter source file: ");
HERE: scanf("%s", filename);
	  mastfile=fopen(filename, "r");
	  if (mastfile==NULL)
		{printf("File does not exist!\nPlease input another file name: ");
		goto HERE;
		}
printf("\nShow items in:\n(1)Screen\n(2)Printer\n(3)File\nWhats your choice? Please type it here: ");
scanf(" %c", &option);
switch (option)
	{case '1': {system("cls");
				printf("\n\t\t\t\tXYZ Company\n\n");
				printf("\t\t\t\t\t\t\t   Date: %s\n", __DATE__);
				printf("\t\t\t\t\t\t\t   Time: %s\n\n", __TIME__);
				printf("Part Number\t\t\tDescription\t\t\tPrice\n\n");
				while (fscanf(mastfile, "%s%s%f", mast.partnum, mast.partdesc, &mast.partprice)!=EOF)
					{printf("%10s\t", mast.partnum);
					printf("\t%24s\t", mast.partdesc);
					printf("\t%.2f\n", mast.partprice);
					}
				printf("\n\nNext...");
				break;
			   }
	case '2': {system("cls");
			   printf("\n\t\t\t\tXYZ Company\n\n");
			   printf("\t\t\t\tProduct Listing\n\n");
			   printf("Part Number\t\t\tDescription\t\t\tPrice\n\n");
			   while (fscanf(mastfile, "%s%s%f", mast.partnum, mast.partdesc, &mast.partprice)!=EOF)
					{printf("%10s\t", mast.partnum);
					printf("\t%24s\t", mast.partdesc);
					printf("\t%.2f\n", mast.partprice);
					}
			   printf("\nPage %d of %d\t\t\t\t\t\t   Date: %s\n", 1, 1, __DATE__);
			   printf("\n\nFile printed!...");
			   break;
			  }
	case '3': {system("cls");
			   printf("Enter target file: ");
			   DITO: scanf("%s", filename);
	  		   temp=fopen(filename, "w");
	  		   if (temp==NULL)
					{printf("File does not exist!\nPlease input another file name: ");
					goto DITO;
					}
			   while (fscanf(mastfile, "%s%s%f", mast.partnum, mast.partdesc, &mast.partprice)!=EOF)
					fprintf(temp, "%10s\t%24s\t%.2f\n", mast.partnum, mast.partdesc, mast.partprice);
			   fclose(temp);
			   temp=fopen(filename, "r");
			   printf("\n\nPart Number\t\t\tDescription\t\t\tPrice\n\n");
			   while (fscanf(temp, "%s%s%f", mast.partnum, mast.partdesc, &mast.partprice)!=EOF)
					{printf("%10s\t", mast.partnum);
					printf("\t%24s\t", mast.partdesc);
					printf("\t%.2f\n", mast.partprice);
					}
			   fclose(temp);
			   printf("\n\nFile saved in %s.", filename);
			   break;
			  }
	}
fclose(mastfile);
getch();
}
