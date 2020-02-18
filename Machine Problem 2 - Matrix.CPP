//Machine Problem #2 In Data & File Structures (COMP 3083)
//Program Name: Matrix
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente

#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#define m 3
#define n 4
#define p 5
int main ()
{system("cls");
int matrix1[m][n], matrix2[n][p], prodmatrix[m][p], i, j, k, a=9, b=12;
printf("\n\n\t\t\t\t ------------- \n");
printf("\t\t\t\t|             |\n");
printf("\t\t\t\t| M A T R I X |\n");
printf("\t\t\t\t|             |\n");
printf("\t\t\t\t ------------- \n");
printf("\n\n\tInput the values for the first matrix:\n");
for (i=0; i<m; i++)
	{for (j=0; j<n; j++)
		{gotoxy(a, b);
		scanf ("%d", &matrix1[i][j]);
		a+=6;
		}
	b+=1;
	a=9;
	}
printf("\n\n\n\tInput the values for the second matrix:\n");
b+=5;
for (i=0; i<n; i++)
	{for (j=0; j<p; j++)
		{gotoxy(a, b);
		scanf ("%d", &matrix2[i][j]);
		a+=6;
		}
	b+=1;
	a=9;
	}
for (i=0; i<m; i++)
	{for (j=0; j<p; j++)
		{prodmatrix[i][j]=0;
		for (k=0; k<4; k++)
			{prodmatrix[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
printf("\n\n\n\tThe product of the first & second matrix:\n\n");
for (i=0; i<m; i++)
	{for (j=0; j<p; j++)
		{printf("        %3d   ", prodmatrix[i][j]);
		if (j==4)
			{printf("\n");
			}
		}
	}
getch();
}
