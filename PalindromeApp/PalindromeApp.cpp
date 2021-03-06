// PalindromeApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Stack.h"
#include "Stack.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <sstream> 
#include <iterator>

bool IsPalindrome(Stack<char> s1, Stack<char> s2) 
{
	int length = s1.Length();
	for (int i = 0; i < length; i++) 
	{
		if (s1.Top() != s2.Top()) return false;
		s1.Pop(); s2.Pop();
	}
	return true;
}

void RemoveSpaces(string &str)
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] == ' ') str.erase(i, 1);
}

int main()
{
	string userInput;

	Stack<char> stack1;
	Stack<char> stack2;

	while (true)
	{
		cout << endl;
		cout << "Please, choose from the following menu!" << endl;
		cout << "a : create 2 new stacks" << endl;
		cout << "b : clear stacks" << endl;
		cout << "c : read string from input" << endl;
		cout << "d : write contents of the first stack" << endl;
		cout << "e : write contents of the second stack" << endl;
		cout << "f : decide wheter the input string is palindrome or not" << endl;
		cout << "x : end" << endl;
		cout << endl;
		getline(cin, userInput);

		if (userInput.compare("a") == 0)
		{
			
		}
		else if (userInput.compare("b") == 0)
		{
			while (!stack1.IsEmpty()) 
			{
				stack1.Pop();
			}
			while (!stack2.IsEmpty())
			{
				stack2.Pop();
			}
		}
		else if (userInput.compare("c") == 0)
		{
			getline(cin, userInput);
			RemoveSpaces(userInput);

			for (string::iterator it = userInput.begin(); it != userInput.end(); it++)
			{
				stack1.Push(*it);
			}
			for (int i = userInput.length() - 1; i >= 0; i--)
			{
				stack2.Push(userInput.at(i));
			}
		}
		else if (userInput.compare("d") == 0)
		{
			cout << "Stack1: ";
			stack1.Print();
			cout << endl;
		}
		else if (userInput.compare("e") == 0)
		{
			cout << "Stack2: ";
			stack2.Print();
			cout << endl;
		}
		else if (userInput.compare("f") == 0)
		{
			ofstream outputFile;
			outputFile.open("vystup.txt", std::ios_base::app);
			if (IsPalindrome(stack1, stack2))
			{
				stack1.Print();
				cout << " je palindrom." << endl;
				string str;
				stack1.ToString(str);
				outputFile << str << " je palindrom." << endl;
			}
			else 
			{
				stack1.Print();
				cout << " nie je palindrom." << endl;
				string str;
				stack1.ToString(str);
				outputFile << str << " nie je palindrom." << endl;
			}
			outputFile.close();
		}
		else if (userInput.compare("x") == 0)
		{
			return 0;
		}
		else
		{
			cout << "Wrong input given. Please, try again!";
		}
	}
	return 0;
}
