#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <sstream> 
#include <iterator>
#include <assert.h>
#include "Queue.h"


using namespace std;

void SellTheGoods(Queue &q, int quantity) 
{
	if (q.ItemNum() < quantity)
	{
		cout << "Nedostatok tovaru." << endl;
	}
	else
	{
		if (q.m_front->data.quantity > quantity)
		{
			q.m_front->data.quantity -= quantity;
		}
		else
		{
			while (q.m_front->data.quantity < quantity)
			{
				quantity -= q.m_front->data.quantity;
				q.DeleteItem();
			}
			if (quantity != 0)
			{
				q.m_front->data.quantity -= quantity;
			}
		}
	}
}

void BuyTheGoods(Queue &q, int quantity, double price) 
{
	Item newItem;
	newItem.price = price; newItem.quantity = quantity;
	q.Insert(newItem);
}

void ReadFromFile(Queue &q1, Queue &q2, Queue &q3, string filename)
{
	int type, quantity;
	double price;
	char operationType;
	string inputType;

	ifstream inputFile(filename);

	while (inputFile >> inputType >> quantity >> price) 
	{
		type = (int)(inputType.at(0)) - 48;
		operationType = inputType.at(1);

		if (operationType == 'K') 
		{
			switch (type)
			{
				case 1:
					BuyTheGoods(q1, quantity, price); break;
				case 2:
					BuyTheGoods(q2, quantity, price); break;
				case 3:
					BuyTheGoods(q3, quantity, price); break;
			}
		}
	}
}

int main()
{	
	char userInput;

	Queue q1;
	Queue q2;
	Queue q3;


	while (true)
	{
		cout << endl;
		cout << "Please, choose from the following menu!" << endl;
		cout << "<i> : vypis inventar danej polozky"  << endl;
		cout << "<k> : nakup k kusov danej polozky" << endl;
		cout << "<p> : predaj k kusov danej polozky" << endl;
		cout << "<r> : nacitaj inventar zo suboru" << endl;
		cout << "<s> : vypis statistiku zbozia" << endl;
		cout << "<w> : zapis inventar do suboru" << endl;
		cout << "<e> : exit" << endl;
		cout << endl;
		
		cin >> userInput;

		if (userInput == 'i')
		{
			cout << "Zadaj typ polozky." << endl;
			int type;
			cin >> type;

			switch (type) 
			{
				case 1: q1.Display(); break;
				case 2: q2.Display(); break;
				case 3: q3.Display(); break;
			}
		}
		else if (userInput == 'k')
		{
			cout << "zadaj typ polozky (1, 2 alebo 3)" << endl;
			int type;
			cin >> type;
			cout << endl;

			cout << "zadaj pocet kusov" << endl;
			int quantity;
			cin >> quantity;
			cout << endl;

			cout << "zadaj cenu" << endl;
			double price;
			cin >> price;
			cout << endl;

			Item item;
			item.quantity = quantity;
			item.price = price;
			switch(type) 
			{
				case 1:
					q1.Insert(item); break;
				case 2:
					q2.Insert(item); break;
				case 3: 
					q3.Insert(item); break;
			}
		}
		else if (userInput == 'p')
		{
			cout << "zadaj typ polozky (1, 2 alebo 3)" << endl;
			int type;
			cin >> type;
			cout << endl;

			cout << "zadaj pocet kusov" << endl;
			int quantity;
			cin >> quantity;
			cout << endl;

			switch (type) 
			{
				case 1:
					SellTheGoods(q1, quantity); break;
				case 2:
					SellTheGoods(q2, quantity); break;
				case 3:
					SellTheGoods(q3, quantity); break;
			}
		}
		else if (userInput == 'r')
		{
			ReadFromFile(q1, q2, q3, "inventar.txt");
			cout << "Nacitanie inventaru zo suboru uspesne." << endl;
		}
		else if (userInput == 's')
		{
			cout << "Item 1" << endl;
			q1.Display(); 
			cout << "Item 2" << endl;
			q2.Display();
			cout << "Item 3" << endl;
			q3.Display();
		}
		else if (userInput == 'w')
		{
			q1.WriteToFile("output.txt", "Item 1");
			q2.WriteToFile("output.txt", "Item 2");
			q3.WriteToFile("output.txt", "Item 3");

			cout << "Zapis inventaru do suboru uspesne." << endl;
		}
		else
		{
			cout << "Wrong input given. Please, try again!";
		}
	}
	return 0;
}


