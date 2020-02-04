#include <iostream>
#include "tLL.h"

using std::cout;
using std::cin;
using std::endl;

//template<typename T) 
//void print(LinkedList<T> list);

template<typename T>
void listVal(LinkedList<T> list);

int main()
{
	LinkedList<int> linkList1;
	LinkedList<int> linkList2;

	char mumbo;
	int jumbo;

	if (linkList1.isEmpty())
	{
		cout << "Nice\n\n" << endl;
	}
	if (linkList2.isEmpty())
	{
		cout << "Very Nice\n\n" << endl;
	}

	cout << "Please select input a number: ";
	cin >> jumbo;
	linkList1.pushF(jumbo);
	cout << "\n\n" << jumbo << " has been added to the list.\n\n";

	cout << "Checking LL1...";
	if (linkList1.isEmpty())
	{
		cout << "Empty.";
	}
	else
	{
		cout << linkList1.front() << " confirmed.";
	}

	cout << "\n\nGenerating random numbers...\n\n";
	for (int i = 0; i < 9; i++)
	{
		linkList1.pushL(rand() % 15);
	}

	listVal(linkList1);
	cout << "Press any key to clear the list";
	cin >> mumbo;
	linkList1.clearList();
	cout << "Test";
	


	return 0;
}

template<typename T>
void listVal(LinkedList<T> l)
{
	for (auto i = l.start(); i != l.end(); ++i)
	{
		std::cout << (*i) << " ";
	}
}