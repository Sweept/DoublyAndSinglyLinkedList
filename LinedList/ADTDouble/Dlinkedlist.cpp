#include "Dlinkedlist.h"
#include <iostream>
using namespace std;

linkedlist::linkedlist()
{
	head = nullptr;
	size = 0;
}
linkedlist::linkedlist(int val)
{
	head = new node;
	head->data = val;
	head->next = head;
	head->prev = head;
	size = 1;
}
void linkedlist::printList()
{
	cout << "Size of the list is :" << size << endl;
	if (head == nullptr)
	{
		cout << "The list is empty" << endl;
		return;
	}
	node * currentNode = head;
	while (1)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->next;

		if (currentNode == head) {
			break;
		}
	}

}

void linkedlist::append(int val)
{
	node * newNode = new node;
	if (nullptr == newNode)
	{
		return;
	}
	newNode->data = val;
	newNode->next = head;

	if (head == nullptr)
	{
		head = newNode;
		newNode->prev = head;
		newNode->next = head;
	}
	else
	{
		node *last = head->prev;
		last->next = newNode;
		newNode->prev = last;
		newNode->next = head;
		head->prev = newNode;
	}
	size++;
}
void linkedlist::pushFront(int val)
{
	node * newNode = new node;
	if (nullptr == newNode)
	{
		return;
	}
	newNode->data = val;

	if (head == nullptr)
	{
		head = newNode;
		newNode->next = head;
		newNode->prev = head;
	}
	else
	{
		newNode->next = head;
		head->prev->next = newNode;
		newNode->prev = head->prev;
		head->prev = newNode;
		head = newNode;
	}
	size++;
}
void linkedlist::pop()
{
	node * toPop = head;
	if (head != nullptr)
	{
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
	}
	if (toPop)
	{
		if (toPop == head)
		{
			head = nullptr;
		}
		delete toPop;
		size--;
	}
}
void linkedlist::popback()
{

	if (head) {
		node *last = head->prev;
		last->prev->next = head;
		head->prev = last->prev;
		if (last == head)
		{
			head = nullptr;
		}
		delete last;
		size--;
	}
}
void linkedlist::insert(int index, int val) 
{
	if (index > size) {
		cout << "The index is too big." << endl;
		return;
	}
	node * newNode = new node;
	newNode->data = val;
	node * currentnode = head;
	
	if (head) 
	{
		for (int i = 0; i < index; i++) 
		{
			currentnode = currentnode->next;
		}
		newNode->next = currentnode->next;
		newNode->prev = currentnode;
		currentnode->next->prev = newNode;
		currentnode->next = newNode;
		size++;
	}
}
void linkedlist::deleteDuplicates(int val) 
{
	node * outercurrentnode = head;
	while (outercurrentnode->next != head)
	{
		//node * prevnode = outercurrentnode;
		node * innercurrentnode = outercurrentnode->next;
		while (innercurrentnode != nullptr)
		{
			if(outercurrentnode->data == innercurrentnode->data)
			{
				innercurrentnode->next->prev = innercurrentnode->prev;
				innercurrentnode->prev->next = innercurrentnode->next;
				node * temp = innercurrentnode->next;
				delete innercurrentnode;
				innercurrentnode = temp;
				size--;
				continue;
			}
			//prevnode = innercurrentnode;
			innercurrentnode = innercurrentnode->next;
			
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
	node * currentnode = head->prev;
	for (int i = 0; i < M; i++)
	{
		currentnode = currentnode->prev;
	}
	return currentnode;
}
std::ostream& operator << (std::ostream& stream, linkedlist& list) {
	list.printList();
	return stream;
};
void linkedlist::reverseList()
{
	node* current = head;
	while (1)
	{
		node* temp;
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		//traverse
		current = temp;
		if (current == head) {
			break;
		}
	}

	head = head->next;
}



