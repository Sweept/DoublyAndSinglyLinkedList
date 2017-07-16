#include <iostream>
#include <string>

using namespace std;

struct node
{
	string name;

	node *next;
	//node *prev;
};

void pushFront(node *&head, string newPersonName, bool addToTail = true)
{
	node *newNode = new node;
	if (NULL == newNode)
	{
		return;
	}
	newNode->name = newPersonName;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

void pushBack(node *&head, string newPersonName)
{
	node *newNode = new node;
	if (NULL == newNode)
	{
		return;
	}
	newNode->name = newPersonName;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		node *last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = newNode;
	}
}

void deleteNode(node *&head, string nametoDelete)
{
	//first detach the node from list and then delete
	node *prevNode = NULL;
	node *currentNode = head;
	while (currentNode != NULL)
	{
		if (currentNode->name == nametoDelete)
		{
			if (prevNode == NULL)
			{
				head = currentNode->next;
			}
			else
			{
				prevNode->next = currentNode->next;
			}
			delete currentNode;
			break;
		}
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
}

void printList(node *head)
{
	node *currentNode = head;
	while (currentNode != NULL)
	{
		cout << currentNode->name << endl;
		currentNode = currentNode->next;
	}
}

int main()
{
	node *head = NULL;

	pushFront(head, "sri");
	pushFront(head, "emerson");
	pushFront(head, "bezly");
	pushFront(head, "sri1");
	pushFront(head, "emerson1");
	pushFront(head, "bezly1");
	pushFront(head, "sri2");
	pushFront(head, "emerson2");
	pushFront(head, "bezly2");
	pushFront(head, "sri3");
	pushFront(head, "emerson3");
	pushFront(head, "bezly3");
	printList(head);
	deleteNode(head, "emerson2");
	printList(head);
	deleteNode(head, "sri");
	printList(head);

}