// Course: SENG1120
// Written by : SENG1120 Alex Hunt c3310435
// Modified   : 2019-08-26


#include <iostream>
#include<cstdlib>
#include<set>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

// Create a new empty LinkedList
LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	list_length = 0;
}

// Create a new LinkedList with data
LinkedList::LinkedList(value_type& data)
{
	head = new Node(data);
	tail = head;
	current = tail;
	list_length = 1;
}

// Destructor - Ensures all nodes are removed from the Heap when a LinkedList is deleted
LinkedList::~LinkedList()
{
	//head = NULL;
	
	while(head != NULL)
	{
		removeFromHead();
	}
	tail = NULL;
}

// Checks to see if the LinkedListis empty and then adds a new head pointer node to the heap
void LinkedList::addToHead(value_type& data)
{
	if(list_length == 0)
	{
		head = new Node(data);
		tail = head;
		current = tail;
		list_length = 1;
	}
	else{
		// Create new node on the heap
		Node* newHead = new Node(data);
		// Set the heads "prev" pointer to the new head and set the next nodes "next" 
		// pointer to the node at the current head
		head->set_prev(newHead);
		newHead->set_next(head);
		// Set the head (from the list) to the new node
		head = newHead;
		// Increment the list
		list_length++;
		// Set this temp to NULL
		newHead = NULL;
	}
}

// Checks to see if the LinkedListis empty and then adds a new tail pointer node to the heap
void LinkedList::addToTail(value_type& data)
{
	if(list_length == 0)
	{
		head = new Node(data);
		tail = head;
		current = tail;
		list_length = 1;
	}
	else
	{
	// Create new node on the heap
		Node* newTail = new Node(data);
		// Set the tails "next" pointer to the new tail and set the next nodes "prev" 
		// pointer to the node at the current tail
		tail->set_next(newTail);
		newTail->set_prev(tail);
		// Set the tail (from the list) to the new node
		tail = newTail;
		// Increment the list
		list_length++;
		// Set this temp to NULL
		newTail = NULL;
	}
}


// Checks to see if the LinkedListis empty and then removes final node
void LinkedList::removeFromHead(const char* value_type)
{
	// Do nothing for an empty list
	if (list_length == 0)
	{
		return;
	}
	
	// Remove final node if only 1 node is in the list
	else if(list_length == 1)
	{
		delete head;
		head = NULL;
		tail = NULL;
		list_length--;
		return;
	}
	
	else
	{
		// Make a temp head pointer and set it as the current head
		Node* newHead = new Node();
		
		// Rearrange the head pointer for the list
		head = newHead->get_next();
		
		//Remove the temp head
		delete newHead;
		
		//Decrement the list length
		//list_length--;
		
		//Set tehmp to NULL
		newHead = NULL;
	}
}


void LinkedList::removeFromTail(const char* value_type)
{
	// Do nothing for an empty list
	if (list_length == 0)
	{
		return;
	}
	
	// Remove final node if only 1 node is in the list
	else if(list_length == 1)
	{
		delete head;
		head = NULL;
		tail = NULL;
		list_length--;
		return;
	}
	
	else
	{
		// Make a temp tail pointer and set it as the current tail
		Node* newTail = new Node();
		
		// Rearrange the head pointer for the list
		tail = newTail->get_prev();
		
		//Remove the temp head
		delete newTail;
		
		//Decrement the list length
		//list_length--;
		
		//Set tehmp to NULL
		newTail = NULL;
	}
}


void LinkedList::remove(const char* value_type)
{	
	// Do nothing for an empty list
	if (list_length == 0)
	{
		return;
	}
	
	// Remove final node if only 1 node is in the list
	else if(list_length == 1)
	{
		delete head;
		head = NULL;
		tail = NULL;
		list_length--;
		return;
	}
	
	else
	{
		// Make a temp head pointer and set it as the current head
		Node* newHead = head;
		
		// Rearrange the head pointer for the list
		head = newHead->get_next();
		
		//Remove the temp head
		delete newHead;
		
		//Decrement the list length
		list_length--;
		
		//Set tehmp to NULL
		newHead = NULL;
	}
}


// Precondition: None
// Postcondition: the list is empty & both head and tail are NULL
void LinkedList::list_clear()
{
	while (head != NULL)
	{
		remove();
	}
}


int LinkedList::count(const char* value_type)
{
	int answer = 0;
	for (current = head; current != NULL; current = current->get_next())
	{
		answer++;
	}
	return answer;
}


void LinkedList::forward()
{
	current = current -> get_next();
}


void LinkedList::back()
{
	current = current -> get_prev();
}


void LinkedList::moveToHead()
{
	current = head;
}


void LinkedList::moveToTail()
{
	current = tail;
}


LinkedList::value_type LinkedList::get_current()
{
	return current -> get_data();
}


std::size_t LinkedList::size()
{
	return list_length;
}

// Preconditions: None
// Postconditions: Current points to the first node storing the target, and true is returned. If not present, current is NULL and false is returned.
bool LinkedList::list_search(const value_type data)
{
	for (current = head; current != NULL; current = current->get_next())
	{
		if (data == current->get_data())
		{
			return true;
		}
	}
	// else
	return false;
}


/* int length(Node *head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->get_next();
    }
    return len;
}


Node* concatenate(Node *A, Node *B) 
{
    int m = length(A);  //O(m)
    int n = length(B);  //O(n)
    Node* head2 = B;
    for(int i=0;i<m;i++) {
        B = head2;
        for(int j=0;j<n;j++) {
            if(A == B) {
                return A;
            }
            B = B->get_next();
        }
        A = A->get_next();
    }
    return NULL;
} */


LinkedList& LinkedList::operator += (const LinkedList& l1)
{
	Node* current = l1.head;
	
    while (current != NULL) 
	{ // traverses the linked list until the last element
		current = current->get_next(); // goes to the next node
    }
	return *this;   
}


LinkedList& LinkedList::operator -= (const LinkedList& l2)
{
	return *this;
}


// Overloaded output operator 
std::ostream& operator << ( std::ostream& out, LinkedList& l1)
{
	/* out << "Need to Write Code for << ";
	return out; */
	
	
	Node* current = l1.head;
	while (current != NULL) 
    { // traverses the linked list until the last element
          out << current->get_data() << ""; // prints the content of node pointed to by current
          current = current->get_next(); // goes to the next node
    }   
        out << " " << endl; 
    return out;
}
