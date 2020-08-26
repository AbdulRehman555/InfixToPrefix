#include "MyStack.h"
#include<iostream>
#include<string>

using namespace std;


void MyStack::push(int value) {
	MyStack *ptr = new MyStack;
	ptr->data = value;
	ptr->next = top;
	top = ptr;
}

char MyStack::pop() {

	if (isempty())
		cout << "Stack is Empty" << endl;
	else {
		char temp = top->data;
		MyStack *ptr = top;
		top = top->next;
		delete(ptr);
		return temp;
	}

}

char MyStack::retTop()
{
	if (top != NULL)
		return top->data;
	return '#';
}

bool MyStack::isempty() {
	if (top == NULL)
		return true;
	else
		return false;
}
