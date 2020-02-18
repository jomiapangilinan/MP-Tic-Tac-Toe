//Machine Problem # 5: President's Advisers
//Submitted by: Concepcion, Trishia Nicole, B.; Monteza, John Isaiah, A.; Pangilinan, Jomia Ann, E.; Pineda, Kenneth, M.
//BSCS 1-FS1
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define p printf
#define s scanf
int adviser[13]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}, go, interval, choose[5], x, y;

void chosen (int go)
{if(go>13)
	p("\n\n\n\t\t\tInvalid!");
else
	{p("\n\n\n\t\t\tInterval\t: ");
	s("%d", &interval);
	for (int i=go-1; y<5; i++)
		{if (adviser[i]!=0)
			{++x;
			if (x==interval)
				{ choose[y]=adviser[i];
				adviser[i]=0;
				++y;
				x=0;
				}
			}
		if (i==12)
			i = -1;
		}
	}
p("\n\n\n\t\t\tChosen Advisers\t: ");
for (int i=0; i<4; ++i)
	p("%d, ", choose[i]);
	p("%d", choose[4]);

}
int main()
{p("\n\n\n\t\t\t ---------------------------------------- \n");
p("\t\t\t|                                        |\n");
p("\t\t\t| P R E S I D E N T ' S  A D V I S E R S |\n");
p("\t\t\t|                                        |\n");
p("\t\t\t ---------------------------------------- \n");
system("COLOR f0");
p("\n\n\n\t\t\tStart\t\t: ");
s("%d", &go);
chosen (go);
getch();
}

