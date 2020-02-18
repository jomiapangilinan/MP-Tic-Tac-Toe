//Machine Problem #4 In Data & File Structures (COMP 3083)
//Program Name: Arithmetic Expressions
//Programmer's Names: Jomia Ann E. Pangilinan, Ioshua Jericho A. Surigao
//Course & Section: BSCS 1-FS1
//Professor: Professor Michael B. dela Fuente

#include <stdio.h>
#include <stack>
#include <string>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int kabuuan=0;
int nangunguna(string c)
{if(c.compare("+")==0 || c.compare("-")==0)
	return 1;
if(c.compare("*")==0 || c.compare("/")==0)
	return 2;
return 0;
}
vector<string> infixTOpostfix (const vector<string> infix)
{stack<string> aStack;
vector<string> postfix;
for(int i=0; i<infix.size(); i++)
	{string c=infix.at(i);
	if(c.compare("(")==0)
		aStack.push(c);
	else if(c.compare(")")==0)
		{while (aStack.top().compare("(")!=0)
			{postfix.push_back(aStack.top());
			aStack.pop();
			}
		aStack.pop();
		}
	else if(c.compare("+")==0 || c.compare("-")==0 || c.compare("*")==0 || c.compare("/")==0 )
		{while (!aStack.empty() && aStack.top().compare("(")!=0 && nangunguna(c)<=nangunguna(aStack.top()))
			{postfix.push_back(aStack.top());
			aStack.pop();
			}
		aStack.push(c);
		}
	else if(!c.empty())
		{postfix.push_back(c);
		}    
	}
while (!aStack.empty())
	{postfix.push_back(aStack.top());
	aStack.pop();
	}
return postfix;
}
vector<string> split(string s)
{vector<string> output;
string delimiter=" ";
int p=0;
string token;
while ((p=s.find(delimiter))!=string::npos)
	{token=s.substr(0, p);
	output.push_back(token);
	s.erase(0, p+delimiter.length());
	}
output.push_back(s);
return output;
}
int evaluate(vector<string> postfix)
{string p;
stack<int> stk;
int operator1, operator2, kinalabasan=0;
int bilangin=0;
for(int i=0; i<postfix.size(); i++)
	{p=postfix.at(i);
	if(isdigit(p[0]))
		{stk.push(atoi(p.c_str()));
		}
	else
		{operator1=stk.top();
		stk.pop();
		operator2=stk.top();
		stk.pop();
		if(p.compare("+")==0)
			kinalabasan=operator2+operator1;
		else if(p.compare("-")==0)
			kinalabasan=operator2-operator1;
		else if(p.compare("/")==0)
			kinalabasan=operator2/operator1;
		else if(p.compare("*")==0)
			kinalabasan=operator2*operator1;
		else if(p.compare("%")==0) 
			kinalabasan=operator2%operator1;
		else
			{printf("\n\n\nInvalid Operator!!!");
			return 0;

            }
		stk.push(kinalabasan);
		}
	}
return kinalabasan;
}
int main()
{string infix;
vector<string> postfix;
printf("\n\n\n\t\t\t ----------------------- \n");
printf("\t\t\t|                       |\n");
printf("\t\t\t|  E V A L U A T I O N  |\n");
printf("\t\t\t|          O F          |\n");
printf("\t\t\t|  A R I T H M E T I C  |\n");
printf("\t\t\t| E X P R E S S I O N S |\n");
printf("\t\t\t|                       |\n");
printf("\t\t\t ----------------------- \n");
printf("\n\n\nPlease enter an arithmetic expression in infix form seperated by spaces:\n");
getline(cin, infix);
if(!infix.empty() && infix.length()>0)
	{infix=infix.substr(0, infix.length());
	postfix=infixTOpostfix (split(infix));
	cout << "\n\n\nThe postfix notation of the expression is: ";
	for(int i=0; i<postfix.size(); i++)
		cout << postfix.at(i); 
	cout << endl;
	cout << "\n\n\nThe value of that expression is: " << evaluate(postfix) << endl;
	}
else
	cout << "\n\n\nInvalid expression!!!" << endl;
getch();
return 0;
}
