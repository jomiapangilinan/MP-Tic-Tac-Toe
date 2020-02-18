//Machine Problem #9 In Data & File Structures 
//Program Name: Tree Recovery
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
char preorder[20], inorder[20];
int z;
struct treereco
	{char node;
	treereco *kaliwa;
	treereco *kanan;
	};
treereco *nodes, *hnode;
void ugat ()
{nodes=(treereco*)malloc(sizeof(treereco));
hnode=nodes;
nodes->node=preorder[0];
nodes->kaliwa=NULL;
nodes->kanan=NULL;
}
void anak (int r, int j, struct treereco *nnode)
{if (r>j)
	{if (nnode->kaliwa!=NULL)
		{for (int a=0; a<z; a++)
			{if ((nnode->kaliwa)->node==inorder[a])
				{anak (a, j, nnode->kaliwa);					
				}
			}
		}
	else
		{nodes=(treereco*)malloc(sizeof(treereco));
		nnode->kaliwa=nodes;
		nodes->node=inorder[j];
		nodes->kaliwa=NULL;
		nodes->kanan=NULL;
		}
	}
else
	{if (nnode->kanan!=NULL)
		{for (int a=0; a<z; a++)
			{if ((nnode->kanan)->node==inorder[a])
				{anak (a, j, nnode->kanan);					
				}
			}
		}
	else
		{nodes=(treereco*)malloc(sizeof(treereco));
		nnode->kanan=nodes;
		nodes->node=inorder[j];
		nodes->kaliwa=NULL;
		nodes->kanan=NULL;	
		}		
	}
}
void postorder (struct treereco *fnode)
{if (fnode!=NULL)
	{postorder (fnode->kaliwa);
	postorder (fnode->kanan);
	printf("%c", fnode->node);
	}
}
void puno ()
{int i, j, r;
z=strlen(preorder);
for (i=0; i<z; i++)
	{if (preorder[0]==inorder[i])
		{r=i;
		ugat ();		
		}
	}
for (i=1; i<z; i++)
	{for (j=0; j<z; j++)
		{if (preorder[i]==inorder[j])
			{anak (r, j, hnode);
			}
		}
	}
}
void titulo ()
{printf("\n\n\t\t -------------------------- \n");
printf("\t\t|                          |\n");
printf("\t\t| T R E E  R E C O V E R Y |\n");
printf("\t\t|                          |\n");
printf("\t\t -------------------------- \n");
}
int main()
{FILE *treerecfile;
char name[20];
titulo ();
printf ("\n\nEnter the filename: ");
HERE: gets(name);
treerecfile=fopen(name, "r");
if (treerecfile==NULL)
	{printf("File does not exist!\nEnter another filename: ");
	goto HERE;
	}
printf("\n");
while (!feof(treerecfile))
	{fscanf(treerecfile,"%s%s", preorder, inorder);
	puno ();	
	postorder (hnode);
	printf("\n");
	}
fclose(treerecfile);
getch();
}
