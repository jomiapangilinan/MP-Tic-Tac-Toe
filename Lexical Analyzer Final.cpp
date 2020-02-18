#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(){
	
	#define p printf
	#define s scanf
	//clrscr();

	char key[100];
	int ans;
	
	
	do{
	p("\n\nPrinciples on Programming Languages\n");
	p("BSCS 2-FS1\nGroup 2\n");
	p("\n\t=== LEXICAL ANALYZER ===\n");
	
	
	p("\nEnter string here => ");
	s(" %s", &key);
	
	
	
	if(key[0] == 'B'){
		if(key[1] == 'O')
			if(key[2] == 'O')
				if(key[3] == 'L')
					if(key[4] == 'E')
						if(key[5] == 'A')
							if(key[6] == 'N')
								if(key[7] == '\0')
								p("BOOLEAN IS A DATA TYPE");
							else
							p("%s IS INVALID", key);
						else
						p("%s IS INVALID", key);
					else
					p("%s IS INVALID", key);
				else
				p("%s IS INVALID", key);
			else
			p("%s IS INVALID", key);
		else
		p("%s IS INVALID", key);
	}
	
	
	if(key[0] == 'C'){
		if(key[1] == 'H')
			if(key[2] == 'A')
				if(key[3] == 'R')
					p("CHAR IS A DATA TYPE");
				else
				p("%s IS INVALID", key);
					
							
		else if(key [2] == 'O')
				if(key[3] == 'O')
					if(key[4] == 'S')
						if(key[5] == 'E')
							p("CHOOSE IS A KEYWORD");
						else
						p("%s IS INVALID", key);
					else
					p("%s IS INVALID", key);
				else
				p("%s IS INVALID", key);
			else
			p("%s IS INVALID", key);
				
		else if(key [1] == 'O')
				if(key [2] == 'N')
					if(key [3] == 'T')
						if(key [4] == 'I')
							if(key [5] == 'N')
								if(key [6] == 'U')
									if(key [7] == 'E')
										p("CONTINUE IS A KEYWORD");
									else
									p("%s IS INVALID", key);
								else
								p("%s IS INVALID", key);
							else
							p("%s IS INVALID", key);
						else
						p("%s IS INVALID", key);
					else
					p("%s IS INVALID", key);
				else
				p("%s IS INVALID", key);
							
	}
	
	
	if(key[0] == 'D'){
		if(key[1] == 'E')
			if(key[2] == 'F')
				if(key[3] == 'A')
					if(key[4] == 'U')
						if(key[5] == 'L')
							if(key[6] == 'T')
								p("DEFAULT IS A KEYWORD");
							else
							p("%s IS INVALID", key);
						else
						p("%s IS INVALID", key);
					else
					p("%s IS INVALID", key);
				else
				p("%s IS INVALID", key);
			else
			p("%s IS INVALID", key);
			
		
		else if(key[1] == 'O')
				if(key[2] == 'U')
					if(key[3] == 'B')
						if(key[4] == 'L')
							if(key[5] == 'E')
								p("DOUBLE IS A DATA TYPE");
							else
							p("%s IS INVALID", key);
						else
						p("%s IS INVALID", key);
					else
					p("%s IS INVALID", key);
				else
				p("%s IS INVALID", key);
	}
	
	if(key[0] == 'I'){
		if(key[1] == 'N')
			if(key[2] == '\0')
				p("IN IS A KEYWORD");
			
			
			else if(key[2] == 'T')
					p("INT IS A DATA TYPE");
				else
				p("%s IS INVALID", key);
	}
	
	
	if(key[0] == 'J'){
		if(key[1] == 'U')
			if(key[2] == 'M')
				if(key[3] == 'P')
					p("JUMP IS A KEYWORD");
				else
				p("%s IS INVALID", key);
			else
			p("%s IS INVALID", key);
		else
		p("%s IS INVALID", key);
	}
	
	
	if(key[0] == 'O'){
		if(key[1] == 'U')
			if(key[2] == 'T')
				p("OUT IS A KEYWORD");
			else
			p("%s IS INVALID", key);
		else
		p("%s IS INVALID", key);
	}
	
	
	if(key[0] == 'R'){
		if(key[1] == 'E')
			if(key[2] == 'P')
				if(key[3] == 'E')
					if(key[4] == 'A')
						if(key[5] == 'T')
							p("REPEAT IS A KEYWORD");
						else
						p("%s IS INVALID", key);
					else
					p("%s IS INVALID", key);
				else
				p("%s IS INVALID", key);
			else
			p("%s IS INVALID", key);
		
			else if(key[1] == 'O')
					if(key[2] == 'L')
						if(key[3] == 'L')
							p("ROLL IS A KEYWORD");
						else
						p("%s IS INVALID", key);
					else
					p("%s IS INVALID", key);
	}
	
	
	if(key[0] == 'S'){
		if(key[1] == 'T')
			if(key[2] == 'O')
				if(key[3] == 'P')
					p("STOP IS A KEYWORD");
				else
				p("%s IS INVALID", key);

		
			else if(key[2] == 'R')
					if(key[3] == 'I')
						if(key[4] == 'N')
							if(key[5] == 'G')
								p("STRING IS A DATA TYPE");
							else
							p("%s IS INVALID", key);
						else
						p("%s IS INVALID", key);
					else
					p("%s IS INVALID", key);
		}
		
			
		if(key[0] == 'T'){
			if(key[1] == 'H')
				if(key[2] == 'I')
					if(key[3] == 'S')
						if(key[4] == '\0')
							p("THIS IS A KEYWORD");
				
						
						if(key[4] == 'T')
								if(key[5] == 'H')
									if(key[6] == 'E')
										if(key[7] == 'N')
											p("THISTHEN IS A KEYWORD");
										else
										p("%s IS INVALID", key);
									else
									p("%s IS INVALID", key);
								else
								p("%s IS INVALID", key);
		}
		
		p("\n\nRepeat? Press [1] YES   [2] NO\n=> ");
		s("%d", &ans);
		
	}while(ans != 2);
	
	
	p("\nSystem terminated...");
	getch();
	return 0;
}

