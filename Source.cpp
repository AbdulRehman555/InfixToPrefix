#include<iostream>
#include<string>
#include "MyStack.h"

using namespace std;
static int precedence(char ch) {
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}
bool isOperator(char ch) {
	if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
		return true;
	return false;
}
bool isOperand(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >='0' && ch <= '9' ))
		return true;
	return false;
}
string reversePolish(string Notation) {
	MyStack stack;
	string postfixNotation="";
	for (int i = 0; i < Notation.length(); i++) {
		if (isOperator(Notation[i])) {
			while (stack.retTop() != '#' && stack.retTop() != '(' && (precedence(Notation[i])<= precedence(stack.retTop())))
				postfixNotation += stack.pop();
			stack.push(Notation[i]);
		}
		else if (isOperand(Notation[i])) {
			postfixNotation += Notation[i];										
		}
		else if (Notation[i] == '(') {
			stack.push(Notation[i]);
		}
		else if (Notation[i] == ')') {
			while (stack.retTop() != '#' && stack.retTop() != '(') {
				postfixNotation += stack.pop();
			}
			stack.pop();
		}
	}
	while (stack.retTop() != '#') {
		postfixNotation += stack.pop();
	}
	return postfixNotation;
}
int main() {
	string infix="";
	string prefix = "";
	string reverseNotation = "";
	cout << "Enter the infix Notation:";
	getline(cin, infix);
	for (int i = infix.length(); i >= 0; i--) {
		char token = infix[i];
		if (token == '(')
			infix[i] = ')';
		if (token == ')')
			infix[i] = '(';
		reverseNotation += infix[i];
	}
	string postfix=reversePolish(reverseNotation);
	for (int i = postfix.length(); i >= 0; i--) {
		prefix += postfix[i];
	}
	cout << "Prefix Notation:" << prefix << endl;
	system("pause");
	return 0;
}