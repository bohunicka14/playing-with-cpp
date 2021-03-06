#include "pch.h"

#include <cstdlib>
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <sstream> 
#include <iterator>
#include <assert.h>


using namespace std;

map<string, string> dictInput;
map<string, string> dictOutput;


// trim from start (in place)
void ltrim(string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void Split(string str, vector<string>& dictOutput, char delim = ' ')
{
	stringstream ss(str);
	string token;
	while (getline(ss, token, delim)) {
		dictOutput.push_back(token);
	}
}

void ReadFromTxt(string fileName, map<string, string>& dictionary)
{
	string line;
	ifstream dicFile(fileName);
	if (dicFile.is_open())
	{
		vector<string> words;
		while (getline(dicFile, line))
		{
			words.clear();
			Split(line, words, ';');
			assert(words.size() == 2);
			ltrim(words.at(1));
			dictionary.insert(pair<string, string>(words.at(0), words.at(1)));
		}
		dicFile.close();
	}
}

void PrintResults()
{
	if (dictOutput.size() == 0)
	{
		cout << "Ziadna zhoda" << endl;
		ofstream outputFile;
		outputFile.open("out.txt", std::ios_base::app);
		outputFile << "Ziadna zhoda" << endl;
		outputFile.close();
	}
	else if (dictOutput.size() == 1)
	{
		ofstream outputFile;
		outputFile.open("out.txt", std::ios_base::app);
		outputFile << dictOutput.begin()->first << " " << dictOutput.begin()->second << endl;
		outputFile.close();
		cout << dictOutput.begin()->first << " " << dictOutput.begin()->second << endl;
	}
	else
	{
		ofstream outputFile;
		outputFile.open("out.txt", std::ios_base::app);
		for (map<string, string>::iterator it = dictOutput.begin(); it != dictOutput.end(); ++it)
		{
			outputFile << it->first << endl;
			cout << it->first << endl;
		}
		outputFile.close();
	}
}

void FindContainigMatch(const string input)
{
	int inputSize = input.length();
	int numMatchingChars = 0;
	int i;

	for (map<string, string>::iterator it = dictInput.begin(); it != dictInput.end(); ++it)
	{
		if (it->first.length() < inputSize) continue;
		for (int startingPoint = 1; startingPoint < it->first.length() - 1; startingPoint++)
		{
			numMatchingChars = 0;
			i = startingPoint;
			if (i + input.length() >= it->first.length()) break;
			for (string::const_iterator sit = input.begin(); sit != input.end(); ++sit)
			{
				if (i == it->first.length() - 1) break;
				if (it->first.at(i) == *sit)
				{
					numMatchingChars++;
				}
				i++;
			}
			if (numMatchingChars == inputSize)
			{
				dictOutput.insert(pair<string, string>(it->first, it->second));
				break;
			}
		}
	}
}

void FindEdgeMatch(const string input, bool startOfInput)
{
	int inputSize = input.length();
	int numMatchingChars = 0;
	int i;

	for (map<string, string>::iterator it = dictInput.begin(); it != dictInput.end(); ++it)
	{
		if (it->first.length() < inputSize) continue;
		if (startOfInput)
		{
			i = 0;
		}
		else
		{
			i = it->first.length() - inputSize;
		}
		for (string::const_iterator sit = input.begin(); sit != input.end(); ++sit)
		{
			if (it->first.at(i) == *sit)
			{
				numMatchingChars++;
			}
			i++;
		}
		if (numMatchingChars == inputSize)
		{
			dictOutput.insert(pair<string, string>(it->first, it->second));
		}
		numMatchingChars = 0;
	}
}

int main(int argc, char** argv)
{
	ReadFromTxt("slovnik.txt", dictInput);
	string userInput;

	while (true)
	{
		dictOutput.clear();
		cout << endl;
		cout << "Please, choose from the following menu!" << endl;
		cout << "<starting>" << endl;
		cout << "<containing>" << endl;
		cout << "<ending>" << endl;
		cout << "<stop>" << endl;
		cout << endl;
		getline(cin, userInput);

		if (userInput.compare("<starting>") == 0)
		{
			getline(cin, userInput);
			FindEdgeMatch(userInput, true);
			PrintResults();
		}
		else if (userInput.compare("<containing>") == 0)
		{
			getline(cin, userInput);
			FindContainigMatch(userInput);
			PrintResults();
		}
		else if (userInput.compare("<ending>") == 0)
		{
			getline(cin, userInput);
			FindEdgeMatch(userInput, false);
			PrintResults();
		}
		else if (userInput.compare("<stop>") == 0)
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