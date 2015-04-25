#include <iostream>
#include "char_stack.h"

using namespace std;


int main(){
	char *Array=new char[255];
	int line=1;
	char_stack *Buffer = new char_stack();

	do{
	cin.getline(Array, 255);
	int length=cin.gcount();

	
	for(int i=0; i<length; i++){

	
	char charBuffer='\0';
	charBuffer=Array[i];


		if (charBuffer == '{' || charBuffer == '[' || charBuffer == '('){
			Buffer->push(charBuffer);
		}

		
		else if (charBuffer == '}' || charBuffer == ']' || charBuffer == ')'){
			if (Buffer->empty()){
				cout << "Error on line "<< line<<". Too many " << charBuffer<<endl;
				for (int j=0; j<=i; j++){
					cout<<Array[j];
							}
				cout<<endl<<"\t\t";
				for (int j=i+1; j<length; j++)
				{
				cout<<Array[j];
				}
				cout<<endl;
				return 0;
				}
			char Str = Buffer->pop();
			char InvStr;
			if (Str=='{')
				InvStr='}';
			else if (Str=='[')
				InvStr=']';
			else if (Str=='(')
				InvStr=')';


			if (!(charBuffer == InvStr))
			{
				
				cout << "Error on line "<< line << ": Read " 
				<< charBuffer << ", expected " << InvStr << ". Too many " << 					charBuffer<<endl;

				for (int j=0; j<=i; j++){
					cout<<Array[j];
							}
				cout<<endl<<'\t';
				for (int j=i+1; j<length; j++){
					cout<<Array[j];
								}
				cout<<endl;
				return 0;
			}
		}
	}

	line++;
	}while(!cin.peek()==cin.eof());
	line--;

	if (!(Buffer->empty()))
	{
		char ExtraBrackets = Buffer->pop();
		cout << "Error on line "<<line<<". Too many- " <<ExtraBrackets<<endl;
		cout<<Array;
		cout<<endl;
			
	}
	else{
		cout << "No Errors Found\n";
	}


	return 0;
}
