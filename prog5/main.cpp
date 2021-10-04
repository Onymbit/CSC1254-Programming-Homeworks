/*
        Author: W. Douglas Lafield
        main.cpp
*/
#include <iostream>
#include <fstream>
#include "Stack.h"

#define BUFFER_LENGTH 100
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

/***************************************************/

/* prototypes */
long long int expon(long long int b, long long int e);
long long int intRoot(long long int n);
bool isOperator(string s);
long long int letterToNum(string letter);
char numToLetter(long long int num);
int precedence(string oper);

/***************************************************/

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		cout << "You must enter a filename by command line." << endl;
		cout << "The command should be as follows:" << endl;
		cout << argv[0] << " [file containing roster]." << endl;
		return 0;
	}
	
	/* read file */
	ifstream f;
	f.open(argv[1]);
	if(!f)
	{
		cout << "File " << argv[1] << " does not exist." << endl;
		return 0;
	}
	
	int numOfLines;
	
	f >> numOfLines;
	
	long long int letters[26];
	for(int i = 0; i < 26; i++)
		letters[i] = 0;
		
	for(int lineNum = 0; lineNum < numOfLines; lineNum++)
	{ /* for each line in the file */
		
		string command, letter;
		
		f >> command >> letter;
		
		if(command == "print")
		{ /* if command is print */
			
			cout << letter << " = " << letters[letterToNum(letter)] << endl;

		} /* if command is print */
		
		if(command == "root")
		{ /* if command is root */
			
			if(letters[letterToNum(letter)] < 0)
				cout << "Sqrt(" << letters[letterToNum(letter)] << ") is undefined" << endl;
			else
				cout << "Sqrt(" << letters[letterToNum(letter)] << ") = " << intRoot(letters[letterToNum(letter)]) << endl;
			
		} /* if command is root */
		
		if(command == "let")
		{ /* if command is let */
			
			string equalSign;
			long long int value;
			
			f >> equalSign >> value;
			
			letters[letterToNum(letter)] = value;
			
		} /* if command is let */
		
		if(command == "calc")
		{ /* if command is calc */
			
			/* your code goes here */
			long long int endValue=0;
			string temp,buffer="";
			Stack <string> s;
			f>>temp>>temp;
			while(temp!=";"){
				if(temp=="("){
					s.push(temp);
				}
				else if(temp==")"){
					while(s.top()!="("){
						buffer+=s.top();
						s.pop();
					}
					s.pop();
				}
				else if(!isOperator(temp)){
					buffer+=temp;
				}
				else{
				
					while(!s.isEmpty() &&(string)s.top()!="(" && precedence(s.top())>=precedence(temp)){
						buffer+=s.top();
						s.pop();
					}
					s.push(temp);
				}
				f>>temp;
			}
			while(!s.isEmpty()){
				buffer+=s.top();
				s.pop();
			}
			//cout<<"TEST: "<<buffer<<endl;
			Stack <long long int> s2;
			long long int operand1,operand2;
			string tempStr;
			
			for(int j=0;j<buffer.length();j++){
				tempStr=buffer[j];
				if(!isOperator(tempStr)){
					s2.push(letters[letterToNum((tempStr))]);	
				}	
				else{
					operand2=s2.top();
					s2.pop();
					operand1=s2.top();
					s2.pop();
					if(tempStr=="+"){
						//cout<<operand1<<" + "<<operand2<<" = "<<(operand1+operand2)<<endl;
						s2.push(operand1+operand2);
					}
					else if(tempStr=="-"){
						//cout<<operand1<<" - "<<operand2<<" = "<<(operand1-operand2)<<endl;
						s2.push(operand1-operand2);
					}
					else if(tempStr=="*"){
						//cout<<operand1<<" * "<<operand2<<" = "<<(operand1*operand2)<<endl;
						s2.push(operand1*operand2);
					}
					else if(tempStr=="/"){
						//cout<<operand1<<" / "<<operand2<<" = "<<(operand1/operand2)<<endl;
						s2.push(operand1/operand2);
					}
					else if(tempStr=="%"){
						//cout<<operand1<<" % "<<operand2<<" = "<<(operand1%operand2)<<endl;
						s2.push(operand1%operand2);
					}
					else if(tempStr=="^"){
						//cout<<operand1<<"^"<<operand2<<" = "<<(expon(operand1,operand2))<<endl;
						s2.push(expon(operand1,operand2));
					}
					
				}
			}
			endValue=s2.top();
			

			letters[letterToNum(letter)] = endValue;
		} /* if command is calc */
		
	} /* for each line in the file */
	
	f.close();
	
	cout << "Done." << endl;
	
	return 0;
} /* main */

/***************************************************/

char numToLetter(long long int num)
{
	return 'A' + num;
} /* num to letter */

/***************************************************/

long long int letterToNum(string letter)
{
	return letter[0] - 'A';
} /* letter to num */

/***************************************************/

int precedence(string oper)
{
	if(oper[0] == '+' || oper[0] == '-')
		return 2;
	if(oper[0] == '*' || oper[0] == '/' || oper[0] == '%')
		return 3;
	if(oper[0] == '^')
		return 4;
	cout << "ERROR" << endl;
	return -1;
	
} /* precedence */

/***************************************************/

long long int expon(long long int b, long long int e)
{
	if(e < 0)
		return 0;
	if(e == 0)
		return 1;
	if(e == 1)
		return b;
	if(e % 2 == 1)
		return b * expon(b, e - 1);
	return expon(b * b, e / 2);
} /* exponent */

/***************************************************/

bool isOperator(string s)
{
	return (s == "+" || s == "-" || s == "*" || s == "/" || s == "%" || s == "^");
} /* is operator */

/***************************************************/

long long int intRoot(long long int n)
{
	if(n == 0 || n == 1)
		return n;
		
	/* make initial guess = n/2 */
	long long int estimate = n / 2;
	
	/* apply newton's method */
	long long int diff = (estimate * estimate - n) / (2 * estimate);
	while(diff > 0)
	{
		estimate = estimate - diff;
		diff = (estimate * estimate - n) / (2 * estimate);
	}
	
	/* decrease until guess^2 <= n */
	while(estimate * estimate > n)
		estimate--;
		
	/* increase until (guess + 1)^2 >= n */
	while((estimate + 1) * (estimate + 1) < n)
		estimate++;
		
	return estimate;
	
} /* int square root */

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
