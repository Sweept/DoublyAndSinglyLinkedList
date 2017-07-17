#pragma once
#include <iostream>

struct node {
	double data;
	node* next;
};

class linkedlist
{
private:
	node* head;
	int size;

public:
	linkedlist();
	linkedlist(double val);
	void printList();
	void append(double val);
	void pushFront(double val);
	void pop();
	void popback();
	void delete(int index);
	void insert(int val, int index);
	void deleteDuplicates(int val);
	node * mtoLastElement(int M);
	friend std::ostream& operator<< (std::ostream& stream,  linkedlist& list);
	void reverseList();
};

