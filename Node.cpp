// Node.cpp;
// Written by : SENG1120 Alex Hunt c3310435
// Modified   : 2019-08-26

#include "Node.h"

//Default Constructor
Node::Node()
{
	next = NULL;
}

//Specified Constructor
// Set 'data' to the memory address of 'initialData'
Node::Node(const value_type& initial_data)
{
	data = initial_data;
	next = NULL;
	prev = NULL;
	current = NULL;
}

//Destructor
Node::~Node()
{
	next = NULL;
}

//Accessors/Getters
//Two getter methods are required for a linked list (Const version and non const version)
//Compiler will figure out which one is best to use
Node::value_type Node::get_data() const
{
	return data;
}

const Node* Node::get_next() const
{
	return next;
}

const Node* Node::get_prev() const
{
	return prev;
}

Node* Node::get_next()
{
	return next;
}

Node* Node::get_prev()
{
	return prev;
}

//Mutators/Setters
//set_data requires the const value_type memory address of the argument 
//So that the newly set 'data' will be persistent beyond its call

void Node::set_data(const value_type& input_data)
{
	data = input_data;
}

void Node::set_next(Node* input_next)
{
	next = input_next;
}

void Node::set_prev(Node* input_prev)
{
	prev = input_prev;
}
