#include <iostream>
#include "Dlinkedlist.h"
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

	l.popback();

	cout << "l is :" << endl;
	l.printList();
	cout << endl;

	cout << "l is :" << endl;
	l.printList();
	cout << endl;

	cout << "Enter your Mth position." << endl;
	l.mtoLastElement(4);

	l.reverseList();

	return 0;
}