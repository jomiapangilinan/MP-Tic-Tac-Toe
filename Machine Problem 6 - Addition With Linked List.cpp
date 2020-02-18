//Machine Problem # 6 In Data and File Structures
//Program Name: Addition with Linked Lists
//Programmer's Names: Concepcion, Trishia Nicole, B.; Monteza, John Isaiah, A.; Pangilinan, Jomia Ann, E.; Pineda, Kenneth, M.
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define p printf

typedef struct ABC
	{int bilang;
	struct ABC *sunod;
	}numero;
void proseso ();
void adding (numero **hd, int i);
void trav (numero *hd);
void baliktad (numero **hd);
void tuos (char a[], numero **hd);
void addends (numero *hd1, numero *hd);
void free (numero **hd);
numero *head3;

int main()
{
p("\n\n\t\t ------------------------------------------------ \n");
p("\t\t|                                                |\n");
p("\t\t| A D D I T I O N  W I T H  L I N K E D  L I S T |\n");
p("\t\t|                                                |\n");
p("\t\t ------------------------------------------------ \n");
proseso();
getch();
}

void proseso()
{numero *head1=NULL, *head2=NULL;
char a[500], b[500];
p("\n\n\n\t\t\tEnter First Number\t: ");
gets(a);
p("\n\n\t\t\t\t\t\t   +");
p("\n\n\n\t\t\tEnter Second Number\t: ");
gets(b);
p("\n\n\t\t\t\t\t\t -----");
tuos (a, &head1);
tuos (b, &head2);
addends (head1, head2);
p("\n\n\n\t\t\tAnswer\t\t\t: ");
trav (head3);
free (&head1);
free (&head2);
}
void free (numero **hd)
{numero *temp;
while (*hd!=NULL)
	{temp=*hd;
	*hd=(*hd)->sunod;
	free (temp);
	}
*hd=NULL;
}
void adding (numero **hd, int i)
{numero *t;
t=(numero*)malloc(sizeof(numero));
t->sunod=NULL;
t->bilang=i;
if (*hd==NULL)
	{*hd=t;
	return;
	}
t->sunod=*hd;
*hd=t;
}
void trav (numero *hd)
{while(hd!=NULL)
	{p("%d", hd->bilang);
	hd=hd->sunod;
	}
}
void baliktad (numero **hd)
{numero *p, *q, *r;
if (*hd==NULL)
	return;
p=*hd;
if (p->sunod==NULL)
	return;
q=p->sunod;
if (q->sunod==NULL)
	{q->sunod=p;
	p->sunod=NULL;
	*hd=q;
	return;
	}
r=q->sunod;
while (r->sunod!=NULL)
	{q->sunod=p;
	p=q;
	q=r;
	r=r->sunod;
	}
q->sunod=p;
r->sunod=q;
(*hd)->sunod=NULL;
*hd=r;
}

void addends (numero *hd1, numero *hd2)
{int x, carry=0, sum=0;
baliktad (&hd1);
baliktad (&hd2);
while (hd1!=NULL && hd2!=NULL)
	{x=(hd1)->bilang+(hd2)->bilang+carry;
	sum=x%10;
	carry=x/10;
	adding (&head3, sum);
	hd1=(hd1)->sunod;
	hd2=(hd2)->sunod;
	}
if (hd1==NULL && hd2!=NULL)
	{while (hd2!=NULL)
		{x=(hd2)->bilang+carry;
		sum=x%10;
		carry=x/10;
		adding (&head3, sum);
		hd2=(hd2)->sunod;
		}
	}
else if (hd1!=NULL && hd2==NULL)
	{while (hd1!=NULL)
		{x=(hd1)->bilang+carry;
		sum=x%10;
		carry=x/10;
		adding (&head3, sum);
		hd1=(hd1)->sunod;
		}
	}
if (carry>0)
	adding (&head3, carry);
baliktad (&hd1);
baliktad (&hd2);
}
void tuos (char a[], numero **hd)
{int i=0;
while (a[i]!='\0')
	{adding (hd, a[i]-'0');
	i++;
	}
baliktad (hd);
}
