#pragma once
#include <string>
using namespace std;

struct Item 
{
	int quantity;
	double price;
};

struct Node {
	Item data;
	Node *next;
};

class Queue
{
public:
	Queue();
	~Queue();

	Node *m_front, *m_rear;
	
	void Insert(Item n);
	void DeleteItem();
	void Display();
	void WriteToFile(string filename, string itemName);
	double Sum();
	int ItemNum();

};

