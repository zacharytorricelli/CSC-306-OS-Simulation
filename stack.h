#pragma once
#include "node.h"
#include <cassert>
#include <iostream>

using namespace std;


class stack
{

public:

	//const stackLinkedList& operator = (const stackLinkedList&);
	// Overload the assignment operator


	// Function to initialize the stack to an empty state.
	// Postcondition: The stack elements are removed;
	//				  stackTop = nullptr;
	void initializeStack()
	{

		// pointer to delete the node
		node * temp;

		// while there are elements in the stack
		while (stackTop != nullptr)
		{

			// set temp to point to the current node
			temp = stackTop;

			// advance stackTop to the next node
			stackTop = stackTop->link;

			// deallocate memory occupied by temp
			delete temp;

		}

	}


	// Function to determine whether the stack is empty.
	// Postcondition: Returns true if the stack is empty,
	//				  otherwise returns false.
	bool isEmptyStack() const
	{

		return (stackTop == nullptr);

	}


	// Function to determine whether the stack is full.
	// Postcondition: Returns true if the stack is full,
	//				  otherwise returns false.
	bool isFullStack() const
	{

		return false;

	}


	// Function to add newItem to the stack.
	// Precondition: The stack exists and is not full.
	// Postcondition: The stack is changed and newItem
	//				  is added to the top of the stack.
	void push(int newItem)
	{

		// pointer to create the new node
		node * newNode;

		// create the node
		newNode = new node;

		// store newItem in the node
		newNode->info = newItem;

		// insert newNode before stackTop
		newNode->link = stackTop;

		// set stackTop to point to the top node
		stackTop = newNode;

	}


	// Function to return the top element of the stack.
	// Precondition: The stack exists and is not empty.
	// Postcondition: If the stack is empty, the program
	//				  terminates; otherwise, the top element
	//				  of the stack is returned.
	int top() const
	{

		// if the stack is empty, terminate the program
		assert(stackTop != nullptr);

		// return the top element
		return stackTop->info;

	}


	// Function to remove the top element of the stack.
	// Precondition: The stack exists and is not empty.
	// Postcondition: The stack is changed and the top
	//				  element is removed from the stack.
	void pop()
	{

		// pointer to deallocate memory
		node * temp;

		if (stackTop != nullptr)
		{

			// set temp to point to the top node
			temp = stackTop;

			// advance stackTop to the next node
			stackTop = stackTop->link;

			// delete the top node
			delete temp;

		}
		else
			cout << "Cannot remove from an empty stack." << endl;

	}


	// Default constructor
	// Postcondition: stackTop = nullptr;
	stack()
	{

		stackTop = nullptr;

	}


	//stackLinkedList(const stackLinkedList& otherStack);
	// Copy constructor

	//~stackLinkedList();
	// Destructor
	// Postcondition: All the elements of the stack are
	//				  removed from the stack.

private:

	node * stackTop;		// pointer to the stack

							//void copyStack(const stackLinkedList& otherStack);
							// Function to make a copy of otherStack.
							// Postcondition: A copy of otherStack is created and
							//				  assigned to this stack.

};