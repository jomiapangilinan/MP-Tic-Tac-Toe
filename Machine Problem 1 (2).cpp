//Machine Problem #1 In Data & File Structures (COMP 3083)
//Program Name: String Concerto
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente

#include <stdio.h>
#include <conio.h>
#include<windows.h>
#include <ctype.h>
#include <string.h>
int main()
{system("cls");
char word[1000], str[2000], wrd[2000], answer;
int j=0, option;
do
	{system("cls");
	printf("\n\n\t\t\t ------------------------------ \n");
	printf("\t\t\t|                              |\n");
	printf("\t\t\t| S T R I N G  C O N C E R T O |\n");
	printf("\t\t\t|                              |\n");
	printf("\t\t\t ------------------------------ \n");
	printf("\n\n\t\t\t\t  M E N U \n");
	printf("\t\t\t\t  ------- \n");
	printf("\n\t\t\t(1) Vowels to Asterisks (Inverted)\n");
	printf("\n\t\t\t(2) Character Count\n");
	printf("\n\t\t\t(3) Opish\n");
	printf("\n\n\n\t\t\tWhat's your choice? Please type it here: ");
	scanf("%d", &option);
	if (option==1)
		{system("cls");
		printf("\n\n\n\t\t\t -------------------------------- \n");
		printf("\t\t\t|                                |\n");
		printf("\t\t\t| VOWELS TO ASTERISKS (INVERTED) |\n");
		printf("\t\t\t|                                |\n");
		printf("\t\t\t -------------------------------- \n");
		printf("\n\n\n\t\t\tEnter a word: ");
		scanf("%s", &word);
		strrev(word);
		printf("\n\n\n\t\t\t");
		for (int i=0; word[i]!='\0'; i++)
			{if (tolower (word[i])=='a' || tolower (word[i])=='e' || tolower (word[i])=='i' || tolower (word[i])=='o' || tolower (word[i])=='u')
				printf("*");
			else printf("%c", word[i]);
			}
		getch();
		}
	else if (option==2)
		{system("cls");
		printf("\n\n\n\t\t\t ----------------- \n");
		printf("\t\t\t|                 |\n");
		printf("\t\t\t| CHARACTER COUNT |\n");
		printf("\t\t\t|                 |\n");
		printf("\t\t\t ----------------- \n");
		printf("\n\n\n\t\t\tEnter a string: ");
		scanf("%s", &str);
		int i;
		for (i=0; i<strlen(str); i++)
			{if (str[i]==str[i+1])
				{j++;
				i++;
				}
			}
		printf("\n\n\n\t\t\t%d\n", j);
		printf("\n\n\n\t\t\t");
		for (i = 0; i<strlen(str); i++)
			{if (str[i]==str[i+1])
				{i++;
				printf("%c", str[i]);
				}
			}
		getch();
		}
	else if (option==3)
		{system("cls");
		j=1;
		printf("\n\n\n\t\t\t\t\t ------- \n");
		printf("\t\t\t\t\t|       |\n");
		printf("\t\t\t\t\t| OPISH |\n");
		printf("\t\t\t\t\t|       |\n");
		printf("\t\t\t\t\t------- \n");
		printf("\n\n\n\t\t\tEnter a sentence: ");
		scanf("%s", &wrd);
		printf("\n\n\n\t\t\t");
		for (int i=0; i<strlen(wrd); ++i)
			{if(tolower(wrd[i])=='b'||tolower(wrd[i])=='c'||tolower(wrd[i])=='d'||tolower(wrd[i])=='f'||tolower(wrd[i])=='g'||tolower(wrd[i])=='h'||tolower(wrd[i])=='j'||tolower(wrd[i])=='k'||tolower(wrd[i])=='l'||tolower(wrd[i])=='m'||tolower(wrd[i])=='n'||tolower(wrd[i])=='p'||tolower(wrd[i])=='q'||tolower(wrd[i])=='r'||tolower(wrd[i])=='s'||tolower(wrd[i])=='t'||tolower(wrd[i])=='v'||tolower(wrd[i])=='w'||tolower(wrd[i])=='x'||tolower(wrd[i])=='y'||tolower(wrd[i])=='z')
				{if (i==j)
					{if (tolower(wrd[i]) == tolower(wrd[i+1]))
						{printf("%c%cop", wrd[i], wrd[j]);
						++j;
						}
					else 
						{printf("%c%cop", wrd[i], wrd[i]);
						}
					}
				else if (tolower(wrd[i])!=tolower(wrd[j]))
					{printf("%cop", wrd[i]);
					++j;
					}
				}
			else
				{printf("%c", wrd[i]);
				++j;
				}
			}
		getch();
		}
	printf("\n\n\t\tDo you have another option? Please type it here: ");
	scanf(" %c", &answer);
	}
while (toupper (answer)=='Y');
getch();
}
