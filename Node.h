// Node.h;
// Written by : SENG1120 Alex Hunt c3310435
// Modified   : 2019-08-26

//Macroguards
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>
#include "Student.h"

using namespace std;
class Node
{
public:
	//Typedef Statement
	typedef Student value_type;
	
	//Default Constructor
	Node();
	
	//Specific Constructor
	Node(const value_type& initial_data);
	
	//Destructor
	~Node();
	
	//Pointer Mutators and Accessors (Setters and Getters)
	void set_next(Node* input_next);
	void set_prev(Node* input_prev);
	const Node* get_next() const;
	const Node* get_prev() const;
	Node* get_next();
	Node* get_prev();
	
	//Data Mutators and Accessors (Setters and Getters)
	void set_data(const value_type& input_data);
	value_type get_data() const;
	
//Member Variables
private:
	value_type data;	//Pointer to payload (or NULL)
	Node* next;			//Pointer to next (or NULL)
	Node* prev;			//Pointer to prev (or NULL)
	Node* current;		//Pointer to current (or NULL)
};

#endif
