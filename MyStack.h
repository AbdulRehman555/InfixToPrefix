#pragma once
#include<iostream>
#include<string>

class MyStack {
	char data;
	MyStack *next;
	MyStack *top;
public:
	MyStack() :data(0), next(NULL), top(NULL) {}
	bool isempty();
	void push(int);
	char pop();
	char retTop();
};
