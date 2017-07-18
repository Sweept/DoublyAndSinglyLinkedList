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

node * delete(node *head, int index)
{
	//first detach the node from list and then delete
	if(head == NULL){
		return NULL;
	}
	node *prevNode = NULL;
	node *currentNode = head;
	for (int i = 0; i < index; i++){
		prevNode = currentNode;
		currentnode = currentNode->next;
	}
	if(currentNode == head){
		node * newHead = currentNode->next;
		delete currentNode;
		return newHead;
	}
	prevNode->next = currentNode->next;
	delete currentNode;
	return head;
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

Node* Insert(Node *head,int data)
{
  // Complete this method
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        return newNode;
    } else {
        Node * current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    return head;
}
==============================================================================
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node * newNode = new Node;
    newNode->data = data;
    
    if(head != NULL) {
        newNode->next = head;
    }
    return newNode;
}
==============================================================================
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    Node * currentNode = head;
    Node * prevNode = NULL;
    getListSize(head);
    if(head == NULL) {
        return newNode;
    } 
    if(position == 0) {
        newNode->next = head;
        return newNode;
   }
    for(int i = 0; i < position; i++){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    prevNode->next = newNode;
    newNode->next = currentNode;
    return head;
}
==============================================================================
Node* DeleteNth(Node *head, int position)
{
  // Complete this method
    //first detach the node from list and then delete
	if(head == NULL){
		return NULL;
	}
	if(position == 0){
		Node * newHead = head->next;
		delete head;
		return newHead;
	}
	Node *prevNode = NULL;
	Node *currentNode = head;
	for (int i = 0; i < position; i++){
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	prevNode->next = currentNode->next;
	delete currentNode;
	return head;
}
==============================================================================
void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    Node * currentNode = head;
    Node * prevNode = NULL;
    if(head == NULL) {
        return;
    }
    int size = 0;
    while (currentNode != NULL) {
        size++;
        currentNode = currentNode->next;
    }
    for(int index = size - 1; index >= 0; index--) {
        currentNode = head;
        for(int j = 0; j < index; j++) {
            currentNode = currentNode->next;
        }
        cout << currentNode->data << endl;
    }
}

==============================================================================
void printNth(Node *head, int index)
{
    Node * currentNode = head;
    for(int j = 0; j < index; j++) {
        currentNode = currentNode->next;
    }
    cout << currentNode->data << endl;
   
}

int getListSize(Node *head)
{
    int size = 0;
    Node * currentNode = head;
    while (currentNode != NULL) {
        size++;
        currentNode = currentNode->next;
    }
    return size;    
}

void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    if(head == NULL) {
        return;
    }
    int size = getListSize(head);
    //forward printing 
    for(int index = size - 1; index >= 0; index--) {
        printNth(head, index);
    }
}
===============================================================================
int getListSize(Node *head)
{
    int size = 0;
    Node * currentNode = head;
    while (currentNode != NULL) {
        size++;
        currentNode = currentNode->next;
    }
    return size;    
}

int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    Node * currentNode = head;
    int size = getListSize(head);
    int positionFromHead = size - positionFromTail-1;
    for(int j = 0; j < positionFromHead; j++) {
        currentNode = currentNode->next;
    }
    //cout << currentNode->data << endl;
    
    return currentNode->data;
}
===============================================================================
int getListSize(Node *head)
{
    int size = 0;
    Node * currentNode = head;
    while (currentNode != NULL) {
        size++;
        currentNode = currentNode->next;
    }
    return size;    
}
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    Node * outercurrentnode = head;
    int size = getListSize(head);
	for (int i = 0; i < size; i++)
	{
		Node * prevnode = outercurrentnode;
		Node * innercurrentnode = outercurrentnode->next;
		for (int j = i + 1; j < size; j++)
		{
			if (outercurrentnode->data == innercurrentnode->data)
			{
				prevnode->next = innercurrentnode->next;
				delete innercurrentnode;
				innercurrentnode = prevnode->next;
			    size--;
                j--;
				continue;
			}
            else
            {
                //in a sorted list when we have a mismatch, there will be no more matches later - they ae all higher
                //If not sorted just comment out the following break
                break;
            }
			prevnode = innercurrentnode;
			innercurrentnode = innercurrentnode->next;
            
		}

		outercurrentnode = outercurrentnode->next;
	}
    return head;
}
===============================================================================
bool has_cycle(Node* head) {
    Node * slow = head;
    Node * fast =  head;

    if(!head) return false;

    while(slow && fast && fast->next){
            slow = slow->next;
        /*Moving fast pointer two steps at a time */
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
    }
    return false;
}
===============================================================================
int FindMergeNode(Node *headA, Node *headB)
{
    Node *currentA = headA;
    Node *currentB = headB;

    //Do till the two nodes are the same
    while(currentA != currentB){
        //If you reached the end of one list start at the beginning of the other one
        //currentA
        if(currentA->next == NULL){
            currentA = headB;
        }else{
            currentA = currentA->next;
        }
        //currentB
        if(currentB->next == NULL){
            currentB = headA;
        }else{
            currentB = currentB->next;
        }
    }
    return currentA->data;
}
===============================================================================
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL){
        return newNode;
    }
    if(head->data >= data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    Node * currentNode = head;
    while(currentNode != NULL) {
        if(currentNode->data >= data) {
        }
        currentNode = currentNode->next;
    }
    return head;
}
===============================================================================
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    Node * currentNode = head;
    Node * prev = head;
    while(currentNode != NULL) {
        Node* temp = currentNode->next;
        currentNode->next = currentNode->prev;
        currentNode->prev = temp;
        prev = currentNode;
        currentNode = temp;
        
    }
    return prev;
}
