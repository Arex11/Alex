// Course: SENG1120
// Written by : SENG1120 Alex Hunt c3310435
// Modified   : 2019-08-26

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <cstdlib>
#include <iostream>

#include "Node.h"

using namespace std;

class LinkedList 
{
	public:
		// TYPEDEF declaration continued from Node.h
		typedef Node::value_type value_type;
		
		// CONSTRUCTORS
		LinkedList();
		
		LinkedList(value_type& data);
		
		// DESTRUCTOR
		~LinkedList();
		

		// MEMBER FUNCTIONS
		// addToHead() operation
		void addToHead(value_type& data);
		
		// addToTail() operation
		void addToTail(value_type& data);
		
		
		// remove() operation		
		void removeFromHead(const char* value_type = "");
		void removeFromTail(const char* value_type = "");
		void removeFromCurrent(const char* value_type = "");
		void remove(const char* value_type = "");
		
		bool list_search(const value_type data);
		void list_clear();
		concatenate(Node *A, Node *B);
		
		// count() operation
		int count(const char* value_type = "");

		void forward();
		void back();
		void moveToHead();
		void moveToTail();
		value_type get_current();
		std::size_t size();
		
		//bool concatenate(LinkedList& l1, LinkedList& l2);
		
		
		// MEMBER OPERATORS
		LinkedList& operator += (const LinkedList& l1);
		LinkedList& operator -= (const LinkedList& l2);
		
		Node* head;
		Node* tail;
		Node* current;
		
	// PRIVATE MEMBER VARIABLES
	private:
	Node* firstList;
	Node* secondList;
	int length;
	std::size_t list_length;
};
// NON-MEMBER OUTPUT OPERATOR
std::ostream& operator << ( std::ostream& out, LinkedList& l1);

#endif
