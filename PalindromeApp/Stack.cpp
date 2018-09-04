#include "pch.h"
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
Stack<T>::Stack()
{
	top = -1;
}

template <class T>
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::Push(T x) 
{
	if (top == MAX_SIZE - 1) { 
		cout << "Error: stack overflow" << endl;
		return;
	}
	data[++top] = x;
}

template <class T>
void Stack<T>::Pop() 
{
	if (top == -1) { 
		cout << "Error: No element to pop" << endl;
		return;
	}
	top--;
}

template <class T>
T Stack<T>::Top() 
{
	return data[top];
}

template <class T>
 bool Stack<T>::IsEmpty() 
{
	if (top == -1) return true;
	return false;
}

template <class T>
void Stack<T>::Print() 
{
	int i;
	for (i = 0; i <= top; i++)
		cout <<  data[i];
}

template <class T>
int Stack<T>::Length()
{
	return top;
}

template <class T>
void Stack<T>::ToString(string &str)
{
	if (top == -1) return;
	for (int i = 0; i <= top; i++) 
	{
		str += data[i];
	}
}




