#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
// #include <bits/stdc++.h>
#define MAX 100
using namespace std;
int z = 0, i = 0, j = 0, c = 0;
char a[50], ac[30], stk[50], act[10];


void check(ofstream &outfile)
{
    // Rule 1
	strcpy(ac,"REDUCE TO F -> ");
    // Reduction F -> (E)
	for (z = 0; z < c - 2; z++)
	{
        if(stk[z] == '(' && stk[z+1] == 'E' && stk[z+2] == ')')
		{
            stk[z] = 'F';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			i -= 2;
			// Printing action
			outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac  << "(E) "<< "\n";
		}
	}
    // Reduction F -> id
	for(z = 0; z < c - 1; z++)
	{
		if(stk[z] == 'i')
		{
			stk[z] = 'F';
			stk[z + 1] = '\0';
            i -= 1;
			// Printing action
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "id" << "\n";
		}

	}

    // Rule 2
	strcpy(ac,"REDUCE TO S -> ");

	//Reduction S -> F
    for(z = 0; z < c ; z++)
	{
		if(stk[z] == 'F' && stk[z+1] != '^' && a[j+1] != '^')
		{
			stk[z] = 'S';
			stk[z + 1] = '\0';
			outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "F" << "\n";
		}

	}
    // Reduction S -> F ^ S
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'F' && stk[z + 1] == '^' && stk[z + 2] == 'S')
		{
			stk[z] = 'S';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			i -= 2;
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "F ^ S" << "\n";
		}
	}


    // Rule 3
	strcpy(ac, "REDUCE TO T -> ");

    // Reduction T -> T*S
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'T' && stk[z + 1] == '*' && stk[z + 2] == 'S' && a[j+1] != '^')
		{
			stk[z]='T';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			i -= 2;
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "T * S" << "\n";
		}
	}

    // Reduction T -> T/S
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'T' && stk[z + 1] == '/' && stk[z + 2] == 'S' && a[j+1] != '^')
		{
			stk[z]='T';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			i -= 2;
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "T / S" << "\n";
		}
	}

    //Reduction T -> S
	for(z = 0; z < c; z++)
	{
		if(stk[z] == 'S' && a[j+1] != '^' && stk[z+1] != '^')
		{
			stk[z]='T';
			stk[z + 1]='\0';
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "S" << "\n";
		}
	}

    //Rule 4
	strcpy(ac, "REDUCE TO E -> ");

    //Reduction E -> E+T
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'T' && a[j+1] != '/' && a[j+1] != '*' && stk[z+3] != '*' && stk[z+3] != '/')
		{
			stk[z]='E';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			i -= 2;
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "E + T" << "\n";
		}
	}

    //Reduction E -> E-T
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'E' && stk[z + 1] == '-' && stk[z + 2] == 'T' && a[j+1] != '/' && a[j+1] != '*' && stk[z+3] != '*' && stk[z+3] != '/')
		{
			stk[z]='E';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			i -= 2;
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "E - T" << "\n";
		}
	}
    // Reduction E -> T
	for(z = 0; z < c; z++)
	{
		if(stk[z] == 'T' && a[j+1] != '/' && a[j+1] != '*' && stk[z+1] != '*' && stk[z+1] != '/')
		{
			stk[z]='E';
			stk[z + 1]='\0';
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "T" << "\n";
		}
	}
    // Rule 5
    strcpy(ac, "REDUCE TO P -> ");
    // Reduction P -> E
    for(z = 0; z < c; z++)
    {
        if(stk[z] == 'E' && a[j+1] != 'i' && a[j+1] != '+' && a[j+1] != '-' && a[j+1] != '*' && a[j+1] != '/' && a[j+1] != '^')
        {
            stk[z]='P';
            stk[z + 1]='\0';
            outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << ac << "E" << "\n";
        }
    }
}
void input(char s[])
{
    fstream my_file;
	my_file.open("input.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
		char ch;
        int i = 0;
		while (1) {
			my_file >> ch;
            s[i] = ch;
            i += 1;
			if (my_file.eof())
				break;
		}
	}
}
int main()
{
	ofstream outfile;
	outfile.open("output.txt");
    // Grammar
    outfile << "\nGrammar rule:\n";
    ifstream file;
    file.open("grammar.txt");
    string str;
    while (getline(file, str))
	{
        outfile << str << "\n";
    }
    file.close();

    // Sentence
    outfile << "\nSentence:\n";

    file.open("input.txt");
    while (!file.eof()){
        file >> a;
    }
    file.close();
    outfile << a;

    // Length
    c=strlen(a);





    strcpy(act,"SHIFT"); 

    outfile << "\n\n STACK \t\t\t\t INPUT \t\t\tACTION \n";
    outfile << "$\t\t\t" << a << "\t\t\t" << "$\n";

    for(i = 0; j < c; i++, j++)
	{
        if (a[j] == 'i')
		{
            stk[i] = a[j];
            stk[i+1] = a[j+1];
            stk[i+2] = '\0';
            a[j] = ' ';
            a[j+1] = ' ';
            i += 1;
            j += 1;
        }
        else
        {
            stk[i] = a[j];
            stk[i + 1] = '\0';
        }

		a[j] = ' ';
		
		
		outfile << "$" << stk << "\t\t\t" << a << "\t\t\t" << "SHIFT" << "\n";
		check(outfile);
	}

	if(stk[0] == 'P' && stk[1] == '\0')
		outfile << "\nAccept\n";
	else
		outfile << "\nReject\n";
	outfile.close();
    return 0;
}


