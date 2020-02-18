//Machine Problem #7 In Data & File Structures (COMP 3083)
//Program Name: Addition Of Polynomials
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int bilang=0, haba=0, a=0, b=0;
struct term
	{int coef;
	int exp;
	term *next;
	term (int C, int E, term *T)
		:coef (C),
		exp (E),
		next (T)
		{}
	};
term *simula, *ikalawa, *ulo, *buntot, *sagot;
struct kabuuan
	{int coef;
	int exp;
	kabuuan *next;
	kabuuan *bago;
	};
kabuuan *Akabuuan, *Aulo, *Abuntot, *ATemp;
void titulo ()
{printf("\n\n\t\t --------------------------------------------- \n");
printf("\t\t|                                             |\n");
printf("\t\t| A D D I T I O N  O F  P O L Y N O M I A L S |\n");
printf("\t\t|                                             |\n");
printf("\t\t --------------------------------------------- \n");
}
void ekwasyon(int Coefficients, int Exponents, struct term *Polynomial)
{Polynomial=(term*)malloc(sizeof(term));
Polynomial->coef=Coefficients;
Polynomial->exp=Exponents;
Polynomial->next=NULL;
if (bilang==0)
	{ulo=Polynomial;				
	}
else
	{buntot->next=Polynomial;
	}
buntot=Polynomial;
bilang++;		
}
void Toint(int sukat, char Poly[], struct term *TTemp)
{int j, x, y;
for (int i=0; i<=sukat; i++)
	{if (Poly[i]!=' ')
		{if (Poly[i]=='-')
			{if (j%2==0)
				{x=-(Poly[i+1]-'0');
				}
			else if (j%2==1)
				{y=-(Poly[i+1]-'0');
				ekwasyon(x, y, TTemp);
				if (haba==0)
					{a++;
					}
				else b++;
				}
			i++;
			}
		else
			{if (j%2==0)
				x=+(Poly[i]-'0');
			else if (j%2==1)
				{y=+(Poly[i]-'0');
				ekwasyon(x, y, TTemp);
				if (haba==0)
					a++;
				else b++;
				}
			}
		j++;
		}
	}
}
int main()
{struct term *TFulo, *TSulo;
int size, x, y, number=0;
char poly[30];
titulo ();
while (haba<2)
	{printf("\n\n\n\t\t\tEnter a value: ");
	size=strlen(gets(poly));
	if (haba==0)
		Toint(size, poly, simula);			
	bilang=0;
	simula=ulo;
	TFulo=ulo;
	if (haba==1)
		Toint(size, poly, ikalawa);
	haba++;
	}
printf("\n\n\n\t\t\t");
ikalawa=ulo;
TSulo=ulo;
bilang=0;
simula=TFulo;
ikalawa=TSulo;
for (int j=0; j<a; j++)
	{for (int i=0; i<b; i++)
		{if (simula->exp==ikalawa->exp)
			{Akabuuan=(kabuuan*)malloc(sizeof(kabuuan));
			Akabuuan->coef=simula->coef+ikalawa->coef;
			Akabuuan->exp=simula->exp;
			number++;
			}
		ikalawa=ikalawa->next;		
		} 
	if (number==0)
		{Akabuuan=(kabuuan*)malloc(sizeof(kabuuan));
		Akabuuan->coef=simula->coef;
		Akabuuan->exp=simula->exp;
		}
	Akabuuan->next=NULL;
	if (bilang==0)
		{Akabuuan->bago=NULL;
		Aulo=Akabuuan;				
		}
	else
		{Akabuuan->bago=Abuntot;
		Abuntot->next=Akabuuan;
		}
	Abuntot=Akabuuan;
	bilang++;
	simula=simula->next;
	ikalawa=TSulo;
	number=0;
	}
simula=TFulo;
ikalawa=TSulo;
for (int i=0; i<b; i++)
	{for (int j=0; j<a; j++)
		{if (ikalawa->exp==simula->exp)
			number++;
		simula=simula->next;
		}
	if (number==0)
		{Akabuuan=(kabuuan*)malloc(sizeof(kabuuan));
		Akabuuan->coef=ikalawa->coef;
		Akabuuan->exp=ikalawa->exp;
		Akabuuan->next=NULL;
		Akabuuan->bago=Abuntot;
		Abuntot->next=Akabuuan;
		Abuntot=Akabuuan;
		}	
	ikalawa=ikalawa->next;
	simula=TFulo;
	number=0;
	}
Akabuuan=Aulo;
ATemp=Akabuuan->next;
Abuntot=Akabuuan->next;
do
	{while (ATemp!=NULL)
		{if (Akabuuan->exp<ATemp->exp)
			{(ATemp->bago)->next=ATemp->next;
			if (ATemp->next!=NULL)
				(ATemp->next)->bago=ATemp->bago;	
			ATemp->next=Akabuuan;
			if (Akabuuan->bago!=NULL)
				(Akabuuan->bago)->next=ATemp;	
			ATemp->bago=Akabuuan->bago;
			Akabuuan->bago=ATemp;
			Abuntot=ATemp;
			if (ATemp->bago==NULL)
				Aulo=ATemp;
			goto DITO;
			}
		ATemp=ATemp->next;
		}
	DITO:
	Akabuuan=Abuntot;
	if (Akabuuan!=NULL)
		{Abuntot=Abuntot->next;
		ATemp=Akabuuan->next;		
		}
	}
while (ATemp!=NULL || Akabuuan!=NULL);
ATemp=Aulo;
bilang=0;
while (ATemp!=NULL)
	{if (ATemp->coef!=0)
		{if (ATemp->exp==1)
			{if (ATemp->coef>0 && bilang>0)
				{if (ATemp->coef==1)
					{printf ("+x");												
					}
				else printf("+%dx", ATemp->coef);							
				}
			if (ATemp->coef<0 || bilang==0)
				{if (ATemp->coef==-1)
					printf("-x");
				if (ATemp->coef!=-1 || bilang==0)
					{printf("%dx", ATemp->coef);
					}
				}
			}
		if (ATemp->exp==0)
			{if (ATemp->coef>0 && bilang>0)
				{printf("+%d", ATemp->coef);	
				}
			if (ATemp->coef<0 || bilang==0)
				{printf("%d", ATemp->coef);
				}
			}
		if (ATemp->exp>1)
			{if (ATemp->coef>0 && bilang>0)
				{if (ATemp->coef==1)
					{printf("+x^%d", ATemp->exp);	
					}
				else printf("+%dx^%d", ATemp->coef, ATemp->exp);							
				}
			if (ATemp->coef<0 || bilang==0)
				{if (ATemp->coef==-1)
					{printf("-x^%d", ATemp->exp);
					}
				if (ATemp->coef!=-1 || bilang==0)
					{printf("%dx^%d", ATemp->coef, ATemp->exp);
					}
				}
			}
		bilang++;
		}
	ATemp=ATemp->next;
}
getch();
return 0;
}
