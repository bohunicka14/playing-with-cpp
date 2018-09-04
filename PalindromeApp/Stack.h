#pragma once

#include <string>
using namespace std;

#define MAX_SIZE 21

template<class T> class Stack
{
public:
	Stack();
	~Stack();

	void Push(T x);
	void Pop();
	T Top();
	bool IsEmpty();
	void Print();
	int Length();
	void ToString(string &str);

private:
	T data[MAX_SIZE];  
	int top;  
};

