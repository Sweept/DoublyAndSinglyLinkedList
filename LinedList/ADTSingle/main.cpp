#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{

	linkedlist l;
	linkedlist l1(5);

	cout << "l is :" << endl;
	l.printList();
	cout << "l1 is :" << endl;
	l1.printList();
	cout << endl;

	for (int i = 5; i < 10; i++)
		l.append(i);

	cout << " l is :" << endl;
	l.printList();
	cout << endl;

	std::string one("one");
	std::string two("two");
	std::string combine = one + two;
	cout << combine.c_str();

	for (int i = 4; i > 0; i--)
		l.pushFront(i);

	cout << " l is :" << endl;
	l.printList();
	cout << endl;

	l.pop();
	l.pop();

	cout << l;
	cout << " l is :" << endl;
	l.printList();
	cout << endl;

	l.reverseList();

	l.popback();

	cout << "l is :" << endl;
	l.printList();
	cout << endl;

	cout << "l is :" << endl;
	l.printList();
	cout << endl;

	cout << "Provide a node value you want to add to front." << endl;
	cout << "Provide a node value you want to add to end." << endl;
	cout << "Provide a node value you want to add to specific location." << endl;
	cout << "Enter a node value then enter your position." << endl;

	cout << "Enter your Mth position." << endl;

	return 0;
}