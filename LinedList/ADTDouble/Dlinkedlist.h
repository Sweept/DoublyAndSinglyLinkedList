#pragma once
#include <iostream>

struct node {
	int data;
	node* next;
	node* prev;
};

class linkedlist
{
private:
	node* head;
	int size;

public:
	linkedlist();
	linkedlist(int val);
	void printList();
	void append(int val);
	void pushFront(int val);
	void pop();
	void popback();
	void insert(int index, int val);
	void deleteDuplicates(int val);
	node * mtoLastElement(int M);
	friend std::ostream& operator<< (std::ostream& stream, linkedlist& list);
	void reverseList();
};

