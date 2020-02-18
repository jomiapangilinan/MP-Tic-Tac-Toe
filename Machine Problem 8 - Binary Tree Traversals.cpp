//Machine Problem #8 In Data & File Structures 
//Program Name: Binary Tree Traversals
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int numero=0;
struct BiTreTrans
	{char node;
	BiTreTrans *kaliwa;
	BiTreTrans *kanan;
	};
BiTreTrans *bnd, *tbnd, *hnd, *temp[30];
void ugat (char baryabol)
{bnd=(BiTreTrans*)malloc(sizeof(BiTreTrans));
hnd=bnd;
tbnd=bnd;
bnd->node=baryabol;
}
void Lanak (char baryabol)
{bnd=(BiTreTrans*)malloc(sizeof(BiTreTrans));
tbnd->kaliwa=bnd;
bnd->node=baryabol;
}
void Ranak (char baryabol)
{bnd=(BiTreTrans*)malloc(sizeof(BiTreTrans));
tbnd->kanan=bnd;
bnd->node=baryabol;
}
void ipapasok (char baryabol)
{int a=0;
bnd=hnd;
while (baryabol!=bnd->node)
	{temp[a]=bnd->kanan;
	bnd=bnd->kaliwa;
	while (bnd==NULL)
		{bnd=temp[a];
		a--;	
		}
	a++;
	}
tbnd=bnd;	
}
void preorder (struct BiTreTrans *trnd)
{if (trnd!=NULL)
	{printf("%c ", trnd->node);
	preorder (trnd->kaliwa);
	preorder (trnd->kanan);
	}
}
void inorder (struct BiTreTrans *trnd)
{if (trnd!=NULL)
	{inorder (trnd->kaliwa);
	printf("%c ", trnd->node);
	inorder(trnd->kanan);
	}	
}
void postorder (struct BiTreTrans *trnd)
{if (trnd!=NULL)
	{postorder (trnd->kaliwa);
	postorder (trnd->kanan);
	printf("%c ", trnd->node);
	}
}
int fanksyon (char nodes[])
{int c, bilang=0;
c=strlen(nodes);
for (int b=0; b<c; b++)
	{if (nodes[b]!=',' && nodes[b]!='(' && nodes[b]!=')')
		{if (tolower(nodes[b])=='n' && tolower(nodes[b+1])=='u')
			{printf("NULL      ");
			b+=4;
			}
		if (nodes[b+1]==',' || nodes[b+1]==')')
			{if (bilang==0 && numero==0)
				ugat (nodes[b]);
			if (bilang==0 && numero>0)
				ipapasok (nodes[b]);
			if (bilang==1 && numero>=0)
				Lanak (nodes[b]);
			if (bilang==2 && numero>=0)
				Ranak (nodes[b]);
			bnd->kaliwa=NULL;
			bnd->kanan=NULL;				
			printf("%c         ", nodes[b]);
			}			
		bilang++;
		}	
	}
printf("\n");
}
void titulo ()
{printf("\n\n\t\t ------------------------------------------- \n");
printf("\t\t|                                           |\n");
printf("\t\t| B I N A R Y  T R E E  T R A V E R S A L S |\n");
printf("\t\t|                                           |\n");
printf("\t\t ------------------------------------------- \n");
}
int main()
{FILE *btt;
char pangalan[20], nds[20];
titulo ();
printf("\n\nEnter the file name: ");
HERE: gets(pangalan);
	  if ((btt=fopen(pangalan, "r"))!=NULL)
		{printf("\nNode      L-Subtree R-Subtree\n");
		while (fgets(nds, sizeof nds, btt)!=NULL)
			{fanksyon (nds);
			numero++;
			}
		printf("\nRoot of the tree: %c", hnd->node);	
		printf("\nPreorder Traversals: ");	
		preorder (hnd);
		printf("\nInorder Traversals: ");
		inorder (hnd);		
		printf("\nPostorder Traversals: ");
		postorder (hnd);
		fclose(btt);
		}
else 
	{printf("File does not exist!\nEnter another filename: ");
	goto HERE;
	}
getch();
}
