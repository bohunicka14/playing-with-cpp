#include "pch.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include <fstream>


Queue::Queue()
{
	m_front = m_rear = NULL;
}


Queue::~Queue()
{
	while (m_front != NULL)
	{
		Node *temp = m_front;
		m_front = m_front->next;
		delete temp;
	}
	m_rear = NULL;
}

void Queue::Insert(Item n) 
{
	Node *temp = new Node;
	if (temp == NULL) 
	{
		cout << "Overflow" << endl;
		return;
	}
	temp->data = n;
	temp->next = NULL;

	//for first node
	if (m_front == NULL) 
	{
		m_front = m_rear = temp;
	}
	else 
	{
		m_rear->next = temp;
		m_rear = temp;
	}
	cout << n.quantity << "   " << n.price << " has been inserted successfully." << endl;
}

void Queue::DeleteItem()
{
	if (m_front == NULL) {
		cout << "underflow" << endl;
		return;
	}

	cout << m_front->data.quantity << "  " << m_front->data.price << " is being deleted " << endl;
	if (m_front == m_rear)
		m_front = m_rear = NULL;
	else
		m_front = m_front->next;
}

void Queue::Display()
{
	if (m_front == NULL) 
	{
		cout << "Empty." << endl;
		return;
	}

	Node *temp = m_front;
	while (temp) 
	{
		cout << temp->data.quantity << " units\t@\t" << temp->data.price << " SKK" << endl;
		temp = temp->next;
	}
	cout << "Sumar\t " << Sum() << "SKK" << endl;
	cout << endl;
}

void Queue::WriteToFile(string filename, string itemName) 
{
	ofstream outputFile;
	outputFile.open(filename, std::ios_base::app);
	
	Node *temp = m_front;
	while (temp)
	{
		outputFile << itemName << " :" << temp->data.quantity << " units\t@\t" << temp->data.price << " SKK" << endl;
		temp = temp->next;
	}
	 

}

double Queue::Sum() 
{
	double result = 0.0;
	Node* temp = m_front;
	while (temp) 
	{
		result += temp->data.price;
		temp = temp->next;
	}
	return result;
}

int Queue::ItemNum() 
{
	int result = 0;
	Node * temp = m_front;
	while (temp) 
	{
		result += temp->data.quantity;
		temp = temp->next;
	}
	return result;
}
