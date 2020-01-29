#include <iostream>
#include "tLL.h"

using std::cout;
using std::cin;
using std::endl;

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

	cout << "Generating random numbers...\n\n";
	for (int i = 0; i < 9; i++)
	{
		linkList1.pushL(rand() % 15);
	}
	
	cout << linkList1.



	return 0;
}