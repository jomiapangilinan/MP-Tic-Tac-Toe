//Machine Problem #3 In Data & File Structures (COMP 3083)
//Program Name: Conway's Game Of Life
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXROW 15
#define MAXCOL 30
#define ALIVE 1
#define DEAD 0
struct conway
{int organism;
int neighbor;
}
cell[MAXROW+2][MAXCOL+2];
void twolinebox (int x1, int y1, int x2, int y2)
{int x, y;
gotoxy (x1, y1);
printf("É");
gotoxy (x2, y1);
printf("»");
for(y=y1+1; y<y2; y++)
	{gotoxy (x1, y);
	printf("º");
    gotoxy (x2, y);
	printf("º");
  	}
gotoxy (x1, y2);
printf("È");
gotoxy (x2, y2);
printf("¼"); 
for(x=x1+1; x<x2; x++)
	{gotoxy (x, y1);
	printf("Í"); 
    gotoxy (x, y2);
	printf("Í"); 
	}
gotoxy (x1+1, y1+1);
}
void printxy (int x, int y, char string[])
{gotoxy (x,y);
printf("%s", string);
}
void center (int y, char string[])
{int x=(80-strlen (string)+1)/2;
gotoxy (x, y);
printf("%s", string);
}
void initializeMatrix (void)
{int row, col;
for(row=-1; row<MAXROW+1; row++)
	{for(col=-1; col<MAXCOL+1; col++)
		{cell[row][col].organism=DEAD;
	 	cell[row][col].neighbor=0;
     	}
   	}
}
void showMatrix (void)
{int row, col;
twolinebox (1, 1, 80, 24);
for(row=0; row<MAXROW; row++)
	{for(col=0; col<MAXCOL; col++)
		{gotoxy (5+col, 5+row);
		printf("²");
		if(cell[row][col].organism==ALIVE)
			{gotoxy (5+col, 5+row);
	   		printf("%c", cell[row][col].organism);
			}
     	}
   	}
}
void inputOrganism (void)
{int org, row, col, err, a;
initializeMatrix ();
do
	{clrscr();
    showMatrix ();
    gotoxy (5, 3);
	printf("Input number of organism to display (1-30 only): ");
    gotoxy (55, 3);
	scanf("%d", &org);
    }
while(org<1 || org>30);
for(a=1; a<=org; a++)
	{clrscr();
    showMatrix ();
    do
		{do
			{gotoxy (36, 6);
			printf("Input cell row position of organism %d", a);
	 		printxy (36, 7, "row: (1-15)only\> ");
	 		gotoxy (55, 7);
			scanf("%d", &row);
			row--;
       		}
		while(row>15 || row<0);
       	do
			{gotoxy (36, 9);
			printf("Input cell column position of organism %d", a+1);
	 		gotoxy (36, 10);
			printf("col: (1-30)only\> ");
	 		gotoxy (55, 10);
			scanf("%d", &col);
			col--;
       		}
		while(col>30 || col<0);
       	if(cell[row][col].organism==ALIVE)
			{gotoxy (36, 20);
			printf("cell[%d][%d] is already occupied!", row+1, col+1);
	 		gotoxy (36, 21);
			printf("Try other cell...");
	 		getch();
	 		gotoxy (36, 20);
			clreol ();
	 		gotoxy (36, 21);
			clreol ();
       		}
      	}
	while(cell[row][col].organism==ALIVE);
    cell[row][col].organism=ALIVE;
    showMatrix ();
    }
}
void checkCell (void)
{int row, col;
for(row=0; row<MAXROW; row++)
	{for(col=0; col<MAXCOL; col++)
		{cell[row][col].neighbor=0;  
	  	if(cell[row-1][col-1].organism==ALIVE)
	     	cell[row][col].neighbor++;
	  	if(cell[row-1][col].organism==ALIVE)
	    	cell[row][col].neighbor++;
	  	if(cell[row][col-1].organism==ALIVE)
	    	cell[row][col].neighbor++;
	  	if(cell[row][col+1].organism==ALIVE)
	     	cell[row][col].neighbor++;
	  	if(cell[row+1][col].organism==ALIVE)
	     	cell[row][col].neighbor++;
	  	if(cell[row+1][col-1].organism==ALIVE)
	     	cell[row][col].neighbor++;
	  	if(cell[row-1][col+1].organism==ALIVE)
	     	cell[row][col].neighbor++;
	  	if(cell[row+1][col+1].organism==ALIVE)
	    	 cell[row][col].neighbor++;
      	}
    }
for(row=0; row<MAXROW; row++)
	{for(col=0; col<MAXCOL; col++)
		{if(cell[row][col].organism==ALIVE)
			{if(cell[row][col].neighbor<2) 
				cell[row][col].organism=DEAD; 
	     	else if(cell[row][col].neighbor>3) 
				cell[row][col].organism=DEAD; 
	  		}
	  	else 
	    	if(cell[row][col].neighbor==3) 
				cell[row][col].organism=ALIVE;  
		}
    }
}
void showGeneration (void)
{int gen, g;
clrscr();
showMatrix ();
gotoxy (5, 3);
printf("Enter number of generation you want to see...");
gotoxy (5, 4);
printf("gen:\> ");
gotoxy (12, 4);
scanf("%d", &gen);
for(g=1; g<=gen; g++)
	{clrscr();
	showMatrix ();
	gotoxy (36, 10);
	printf("GENERATION %d", g);
	checkCell ();
    getch();
    }
}
void welcome (void)
{clrscr();
twolinebox (1, 1, 80, 24);
gotoxy (36, 8);
printf("WELCOME");
gotoxy (38, 10);
printf("to");
gotoxy (36, 12);
printf("CONWAY'S");
gotoxy (37, 14);
printf("GAME");
gotoxy (38, 16);
printf("of");
gotoxy (37, 18);
printf("LIFE");
gotoxy (26, 23);
printf("press any key to continue...");
getch();
clrscr();
twolinebox (1, 1, 80, 24);
center (3, "CONWAYS GAME OF LIFE");
printxy (5, 5, "RULE OF THE GAME");
printxy (5, 7, "If in one generation,");
printxy (10, 8, "an empty cell has exactly three neighboring cells containing");
printxy (10, 9, "organisms, then a new organism is born in that cell in the ");
printxy (10, 10, "next generation.");
printxy (5, 11, "If in one generation,");
printxy (10, 12, "an organism has fewer than two neighboring cells containing");
printxy (10, 13, "organisms, then it dies from isolation before the");
printxy (10, 14, "next generation and its cell become empty.");
printxy (5, 15, "If in one generation,");
printxy (10, 16, "an organism has more than three neighboring cells containing");
printxy (10, 17, "organisms, then it dies from overcrowding before the");
printxy (10, 18, "next generation and its cell become empty.");
printxy (5, 19, "All other organisms survive unchanged to the next generation.");
center (21, "Press any key to continue...");
getch();
}
void main()
{char opt;
textmode (BW80);
do
	{clrscr();
   	welcome ();
   	inputOrganism ();
   	showGeneration ();
   	gotoxy (5, 22);
   	printf("Try again? [Y/N] ");
   	opt=getch();
   	}
while(toupper(opt)=='Y');
exit(1);
}
