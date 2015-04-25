#include "char_stack.h"// contains the declarations of the variables and functions.


char_stack::char_stack() :capacity(100){
	Array = new char(capacity);
	top_index = -1; // top_index == -1 indicates the stack is empty.
}


void char_stack::push(char item){
	top_index++;
	Array[top_index] = item;

}

char char_stack::pop(){
	if (top_index>-1)
		top_index--;
	return Array[top_index + 1];
}

char char_stack::top(){
	return Array[top_index];
}

bool char_stack::empty(){
	return top_index == -1;

}


int char_stack::size(){
	return top_index + 1;

}