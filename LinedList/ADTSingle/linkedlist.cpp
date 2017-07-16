#include "linkedlist.h"
#include <iostream>
using namespace std;

linkedlist::linkedlist()
{
	head = nullptr;
	size = 0;
}
linkedlist::linkedlist(double val)
{
	head = new node;
	head->data = val;
	head->next = nullptr;
	size = 1;
}
void linkedlist::printList()
{
	cout << "Size of the list is :" << size << endl;
	if (head == nullptr) 
	{
		cout << "The list is empty" << endl;
	}
	node *currentNode = head;
	while (currentNode != nullptr)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}

}

void linkedlist::append(double val)
{
	node *newNode = new node;
	if (nullptr == newNode)
	{
		return;
	}
	newNode->data = val;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		node *last = head;
		while (last->next != nullptr)
		{
			last = last->next;
		}
		last->next = newNode;
	}
	size++;
}
void linkedlist::pushFront(double val)
{
	node *newNode = new node;
	if (nullptr == newNode)
	{
		return;
	}
	newNode->data = val;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	size++;
}
void linkedlist::pop()
{
	node * toPop = head;
	if (head != nullptr)
	{
		head = head->next;
	}
	if (toPop)
	{
		delete toPop;
	}
	size--;
}
void linkedlist::popback()
{

	if (head) {
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
		} else 
		{
			node* prevnode = head;
			node *currentnode = head->next;
			while (currentnode->next != nullptr)
			{
				prevnode = currentnode;
				currentnode = currentnode->next;
			}
			delete currentnode;
			prevnode->next = nullptr;
		}
		size--;
	}
}
void linkedlist::insert(int val, int index)
{
	if (index > size) {
		cout << "The index is too big." << endl;
		return;
	}
	node * newNode = new node;
	newNode->data = val;
	node * currentnode = head;
	for (int i = 0; i < index; i++)
	{
		currentnode = currentnode->next;
	}
	newNode->next = currentnode->next;
	currentnode->next = newNode->next;
	size++;
}
void linkedlist::deleteDuplicates(int val)
{
	node * outercurrentnode = head;
	for (int i = 0; i < size; i++)
	{
		node * prevnode = outercurrentnode;
		node * innercurrentnode = outercurrentnode->next;
		for (int j = i + 1; j < size; j++)
		{
			if (outercurrentnode->data == innercurrentnode->data)
			{
				prevnode->next = innercurrentnode->next;
				delete innercurrentnode;
				innercurrentnode = prevnode->next;
				continue;
			}
			prevnode = innercurrentnode;
			innercurrentnode = innercurrentnode->next;
			size--;
		}

		outercurrentnode = outercurrentnode->next;
	}
}
node * linkedlist::mtoLastElement(int M) 
{
	if (M >= size) {
		cout << "The index is too big." << endl;
		return nullptr;
	}
	node * currentnode = head;
	for (int i = 0; i < size - M; i++) {
		currentnode = currentnode->next;
		return currentnode;
	}
}

std::ostream& operator << (std::ostream& stream,  linkedlist& list) {
	list.printList();
	return stream;
};

void linkedlist::reverseList()
{
	node* prev = NULL;
	node* current = head;
	while (current != NULL)
	{
		node* temp;
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev;
}





