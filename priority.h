#pragma once
#include "node.h"
#include "queue.h"
#include <cassert>
#include <iostream>
#include <iomanip>


using namespace std;



class priority : public queue
{

private:

	// pointer to the front of the queue
	node *front;


public:

	// Function to insert in the priority queue
	void insertPriority(int newElement, int priority)
	{

		node *temp = new node;
		node * newNode = new node;
		temp->info = newElement;
		temp->priority = priority;

		if (front == nullptr || priority < front->priority)
		{

			temp->link = front;
			front = temp;

		}
		else
		{
			newNode = front;
			while (newNode->link != nullptr && newNode->link->priority <= priority)
			{

				newNode = newNode->link;

			}

			temp->link = newNode->link;
			newNode->link = temp;

		}

	}

	// Function to return the first element of the queue.
	// Precondition: The queue exists and is not empty.
	// Postcondition: If the queue is empty, the program
	//				  terminates; otherwise, the first
	//				  element of the queue is returned.
	int priorityFront() const
	{

		assert(front != nullptr);
		return front->info;

	}


	// Function to print the priority queue
	void printPriority(ofstream &outData)
	{

		// Variable declaration in the function
		int column = 0;
		node *temp = new node;
		temp = front;

		// Outputs a label to the file
		outData << "\t\tPriority " << endl;

		if (front == nullptr)
		{
			outData << "The queue is empty!" << endl;
		}
		else
		{

			while (temp != nullptr)
			{

				column++;
				outData << setw(3) << temp->info << " " << setw(3);

				// If statement to put queue in a 10x10 chart
				if ((column % 10) == 0)
				{

					// Adds a line of space
					outData << endl;

				}

				temp = temp->link;
			}

		}

	}


};
