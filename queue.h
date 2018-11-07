#pragma once
#include "node.h"
#include <cassert>
#include <iostream>

using namespace std;


class queue
{

private:

	// pointer to the front of the queue
	node * queueFront;

	// pointer to the rear of the queue
	node * queueRear;

	// counter variable
	int counter;

public:

	// const queueLinkedList& operator = (const queueLinkedList&);
	// Overload the assignment operator.


	// Function to determine whether the queue is empty.
	// Postcondition: Returns true if the queue is empty,
	//				  otherwise returns false.
	bool isEmptyQueue() const
	{

		return (queueFront == nullptr);


	}


	// Function to determine whether the queue is full.
	// Postcondition: Returns true if the queue is full,
	//				  otherwise returns false.
	bool isFullQueue() const
	{

		return false;

	}


	//void initializeQueue();
	// Function to initialize the queue to an empty state.
	// Postcondition: The queue is empty.


	// Function to return the first element of the queue.
	// Precondition: The queue exists and is not empty.
	// Postcondition: If the queue is empty, the program
	//				  terminates; otherwise, the first
	//				  element of the queue is returned.
	int front() const
	{

		assert(queueFront != nullptr);
		return queueFront->info;

	}


	// Function to return the last element of the queue.
	// Precondition: The queue exists and is not empty.
	// Postcondition: If the queue is empty, the program
	//				  terminates; otherwise, the last
	//				  element of the queue is returned.
	int back() const
	{

		assert(queueRear != nullptr);
		return queueRear->info;

	}


	// Function to add queueElement to the queue.
	// Precondition: The queue exists and is not full.
	// Postcondition: The queue is changed and queueElement
	//				  is added to the queue.
	void addQueue(int newElement)
	{

		node * newNode;

		// create the node
		newNode = new node;

		// store the info
		newNode->info = newElement;

		// initialize the link field to nullptr
		newNode->link = nullptr;

		// if initially the queue is empty
		if (queueFront == nullptr)
		{
			queueFront = newNode;
			queueRear = newNode;

		}
		else           // add newNode at the end
		{

			queueRear->link = newNode;
			queueRear = queueRear->link;

		}

	}


	// Function to remove the first element of the queue.
	// Precondition: The queue exists and is not empty.
	// Postcondition: The queue is changed and the first
	//				  element is remove from the queue.
	void deleteQueue()
	{

		node * temp;

		if (!isEmptyQueue())
		{

			// make temp point to the first node
			temp = queueFront;

			// advance queueFront
			queueFront = queueFront->link;

			// delete the first node
			delete temp;

			// if after deletion the queue is empty
			if (queueFront == nullptr)

				// set queueRear to nullptr
				queueRear = nullptr;

		}
		else

			cout << "Cannot remove from an empty queue." << endl;

	}


	// Function to sort the queue in ascending order.
	void sortQueue(int newElement)
	{

		node * current;					// pointer to traverse the list

		node * trailCurrent = new node;	// pointer just before current

		node * newNode;					// pointer to create a node

		bool found;						// boolean variable

		newNode = new node;				// create the node

		newNode->info = newElement;		// store newItem in the node

		newNode->link = nullptr;		// set the link field of the node to nullptr


										// If the list is empty...
		if (queueFront == nullptr)
		{

			queueFront = newNode;
			queueRear = newNode;

		}
		else
		{

			current = queueFront;
			found = false;

			while (current != nullptr && !found)	// search the list
				if (current->info >= newElement)
					found = true;
				else
				{

					trailCurrent = current;
					current = current->link;

				}

			// If the item inserted is smaller than the smallest item in the list
			if (current == queueFront)
			{

				newNode->link = queueFront;
				queueFront = newNode;

			}

			// The item is to be inserted somewhere in the list
			else
			{

				trailCurrent->link = newNode;
				newNode->link = current;

				if (current == nullptr)
					queueRear = newNode;


			}

		} // end of else
	}






	// Default constructor
	queue()
	{

		// ssets the front and rear to nullptr
		queueFront = nullptr;
		queueRear = nullptr;

	}


	//queueLinkedList(const queueLinkedList& otherQueue);
	// Copy constructor

	//~queueLinkedList();
	// Destructor



};
