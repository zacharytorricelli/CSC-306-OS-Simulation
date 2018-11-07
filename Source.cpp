/****************************************************************************************************************************
*
* Zachary Torricelli
* CSC 306 Operating Systems Simulation Project
* Professor Shelly
*
* Using a random number generator, you will need to create (4) data sets of 100 random integers 
* each with values of 0 to 99. Additionally, you will need to create (1) data set of 100 random 
* integers values of 1 to 3. The latter is for priority of the insert priority queue.  
* You may create your data sets once and write them to a file for later reading in or you may create them each run.
*
* Create 8 registers.  4 inputs and 4 outputs. (Hint: same size as your data type)
* There will be two “runs” your main program. Single register and four registers. 
* Use looping to load/unload the queues from the data sets and to your output file. Each loop is a 
* clock cycle. Count your clock cycle for each of the two functions. Output these counts to your file.  
* Output your input and output data in 10 by 10 matrix to your file.
*	-> Run one uses a single register to input to queues and a single register output data.
*	-> Run two uses 4 registers to input to queues and 4 registers to output data to files
*
* Extra credit (25 points): 
* Single register input and 4 registers to output AND 4 registers to input and 1 register to output.
*
*
*****************************************************************************************************************************/



// Header files and using directive
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "stack.h"
#include "queue.h"
#include "priority.h"
#include "node.h"


using namespace std;


// Global variable for array size
const int SIZE = 100;

// Function prototypes
void fillArray(int[], int[], int[], int[], int[]);
void printArray(int[], int, ofstream&);
void singleRegisterSimulation(int[], int[], int[], int[], int[], ofstream&, ofstream&, ofstream&, ofstream&);
void fourRegisterSimulation(int[], int[], int[], int[], int[], ofstream&, ofstream&, ofstream&, ofstream&);


int main()
{


	// Sets the seed
	srand(time(NULL));


	// Variable declaration in the main function (dynamically allocated arrays)
	int *array1 = new int[SIZE];
	int *array2 = new int[SIZE];
	int *array3 = new int[SIZE];
	int *array4 = new int[SIZE];
	int *priorityArray = new int[SIZE];
	ofstream outDataLIFO;
	ofstream outDataFIFO;
	ofstream outDataSorted;
	ofstream outDataPriority;


	// Opens the files
	outDataLIFO.open("lifo.txt");
	outDataFIFO.open("fifo.txt");
	outDataSorted.open("sorted.txt");
	outDataPriority.open("priority.txt");


	// Default constructors to set the default values 
	stack();
	queue();

	
	// Calls the function fillArray to fill the 4 arrays
	fillArray(array1, array2, array3, array4, priorityArray);

	
	// Displays a message to the file for the first run
	outDataLIFO << "---------------------------------RUN 1---------------------------------" << endl << endl;
	outDataFIFO << "---------------------------------RUN 1---------------------------------" << endl << endl;
	outDataSorted << "---------------------------------RUN 1---------------------------------" << endl << endl;
	outDataPriority << "---------------------------------RUN 1---------------------------------" << endl << endl;


	
	// Calls the function printArray to print array1
	printArray(array1, 1, outDataLIFO);

	// Calls the function printArray to print array2
	printArray(array2, 2, outDataFIFO);

	// Calls the function printArray to print array3
	printArray(array3, 3, outDataSorted);

	// Calls the function printArray to print array4
	printArray(array4, 4, outDataPriority);

	// Calls the function printArray to print priorityArray
	printArray(priorityArray, 5, outDataPriority);

	// Calls the function to do the first run using a single register
	singleRegisterSimulation (array1, array2, array3, array4, priorityArray, outDataLIFO, outDataFIFO, 
		outDataSorted, outDataPriority);






	// Default constructors to set the default values 
	stack();
	queue();


	// Calls the function fillArray to fill the 4 arrays
	fillArray(array1, array2, array3, array4, priorityArray);


	// Displays a message to the file for the first run
	outDataLIFO << endl << "---------------------------------RUN 2---------------------------------" << endl << endl;
	outDataFIFO << "---------------------------------RUN 2---------------------------------" << endl << endl;
	outDataSorted << "---------------------------------RUN 2---------------------------------" << endl << endl;
	outDataPriority << "---------------------------------RUN 2---------------------------------" << endl << endl;



	// Calls the function printArray to print array1
	printArray(array1, 1, outDataLIFO);

	// Calls the function printArray to print array2
	printArray(array2, 2, outDataFIFO);

	// Calls the function printArray to print array3
	printArray(array3, 3, outDataSorted);

	// Calls the function printArray to print array4
	printArray(array4, 4, outDataPriority);

	// Calls the function printArray to print priorityArray
	printArray(priorityArray, 5, outDataPriority);

	// Calls the function to do the second run using four registers
	fourRegisterSimulation(array1, array2, array3, array4, priorityArray, outDataLIFO, outDataFIFO,
		outDataSorted, outDataPriority);



	// Closes the output files
	outDataLIFO.close();
	outDataFIFO.close();
	outDataSorted.close();
	outDataPriority.close();


	system("pause");
	return 0;

}



// Function to fill the arrays
void fillArray(int array1[], int array2[], int array3[], int array4[], int priorityArray[])
{

	// For loop to fill the array with random numbers
	for (int i = 0; i < SIZE; i++)
	{

		// Fills the arrays with random numbers between 0 and 100
		array1[i] = rand() % (100 - 0) + 0;
		array2[i] = rand() % (100 - 0) + 0;
		array3[i] = rand() % (100 - 0) + 0;
		array4[i] = rand() % (100 - 0) + 0;

		// Fills the array with random nu,bers between 0 and 4
		priorityArray[i] = rand() % (3 - 0) + 1;

	}


}


// Function to print the arrays.
void printArray(int array[], int label, ofstream &outData)
{

	// Function variable declaration
	int column = 10;


	if (label != 5)
	{
		// Label for array
		outData << "\t\tArray " << label << endl;

	}
	else
	{
		// Label for priorityAray
		outData << "\t\tPriority Array " << endl;

	}


	// For loop to output the Array in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		// prints the array
		outData << setw(4) << array[i] << setw(4);

		if ((i + 1) % column == 0)
		{

			// Adds a line of space
			outData << endl;

		}

	}


	// Adds two lines of space
	outData << endl << endl;

}


// Single register clock cycle function with 4 different kinds of queue
void singleRegisterSimulation(int array1[], int array2[], int array3[], int array4[], int priorityArray[], 
	ofstream &outDataLIFO, ofstream &outDataFIFO, ofstream &outDataSorted, ofstream &outDataPriority)
{


	// Variable declaration in the function
	int column = 10;
	int inRegisterOne = 0;
	int outRegisterOne = 0;
	int inClockCycle = 0;
	int outClockCycle = 0;

	// Creates objects of the classes
	stack implementStack;
	queue implementQueue;
	queue implementSorted;
	priority implementPriority;


	// Labels for the output file
	outDataLIFO << "\t\tLIFO " << endl;
	outDataFIFO << "\t\tFIFO " << endl;
	outDataSorted << "\t\tSorted " << endl;


	// For loop to add the first 10 elements to the data structure
	for (int i = 0; i < column; i++)
	{

		
		implementStack.push(array1[i]);
		inClockCycle++;

		implementQueue.addQueue(array2[i]);
		inClockCycle++;

		implementSorted.sortQueue(array3[i]);
		inClockCycle++;

		implementPriority.insertPriority(array4[i], priorityArray[i]);
		inClockCycle++;

	}


	// For loop to add and go through the rest of the elements
	for (int j = column; j < SIZE; j++)
	{

		// LIFO Stack
		inRegisterOne = array1[j];
		outRegisterOne = implementStack.top();
		outClockCycle++;

		// Pops of an element of the stack
		implementStack.pop();
		// Pushes the next element on the stack
		implementStack.push(inRegisterOne);
		inClockCycle++;
			
		// Outputs the top element of the stack
		outDataLIFO << setw(2) << outRegisterOne << setw(2) << " ";


		// If statement to output the stack in a 10x10 chart
		if ((j + 1) % column == 0)
		{

			// Adds a line of space
			outDataLIFO << endl;

		}


	

		// FIFO Queue
		inRegisterOne = array2[j];
		outRegisterOne = implementQueue.front();
		outClockCycle++;

		// Removes an element on the queue
		implementQueue.deleteQueue();
		// Adds the next element to the queue
		implementQueue.addQueue(inRegisterOne);
		inClockCycle++;

		// Outputs the top element of the stack
		outDataFIFO << setw(2) << outRegisterOne << setw(2) << " ";


		// If statement to output the stack in a 10x10 chart
		if ((j + 1) % column == 0)
		{

			// Adds a line of space
			outDataFIFO << endl;

		}




		// Sorted Queue
		inRegisterOne = array3[j];
		outRegisterOne = implementSorted.front();
		outClockCycle++;

		// Removes an element on the queue
		implementSorted.deleteQueue();
		// Adds the next element to the queue
		implementSorted.sortQueue(inRegisterOne);
		inClockCycle++;

		// Outputs the top element of the stack
		outDataSorted << setw(2) << outRegisterOne << setw(2) << " ";


		// If statement to output the stack in a 10x10 chart
		if ((j + 1) % column == 0)
		{

			// Adds a line of space
			outDataSorted << endl;

		}

		

		// Priority Queue
		inRegisterOne = array4[j];
		outRegisterOne = implementPriority.priorityFront();
		outClockCycle++;

		// Removes an element on the queue
		implementPriority.deleteQueue();
		// Adds the next element to the queue
		implementPriority.insertPriority(inRegisterOne, priorityArray[j]);
		inClockCycle++;

		
	}



	// For loop to display the last 10 elements
	for (int i = 0; i < column; i++)
	{

		// LIFO Stack
		outRegisterOne = implementStack.top();
		outClockCycle++;

		implementStack.pop();

		// Outputs the top element of the stack
		outDataLIFO << setw(2) << outRegisterOne << setw(2) << " ";

		
	
		// FIFO Queue
		outRegisterOne = implementQueue.front();
		outClockCycle++;

		implementQueue.deleteQueue();

		// Outputs the top element of the stack
		outDataFIFO << setw(2) << outRegisterOne << setw(2) << " ";



		// Sorted Queue
		outRegisterOne = implementSorted.front();
		outClockCycle++;

		implementSorted.deleteQueue();

		// Outputs the top element of the stack
		outDataSorted << setw(2) << outRegisterOne << setw(2) << " ";



		// Priority Queue
		outRegisterOne = implementPriority.priorityFront();
		outClockCycle++;

		implementPriority.deleteQueue();

	
	}

		
		// Calls the print function from the priority class
		implementPriority.printPriority(outDataPriority);
		
		outDataLIFO << endl << endl;
		outDataLIFO << endl << "In Clock Cycle: " << inClockCycle << endl;
		outDataLIFO << "Out Clock Cycle: " << outClockCycle << endl << endl;

		outDataFIFO << endl << endl;
		outDataFIFO << endl << "In Clock Cycle: " << inClockCycle << endl;
		outDataFIFO << "Out Clock Cycle: " << outClockCycle << endl << endl;

		outDataSorted << endl << endl;
		outDataSorted << endl << "In Clock Cycle: " << inClockCycle << endl;
		outDataSorted << "Out Clock Cycle: " << outClockCycle << endl << endl;

		outDataPriority << endl << endl;
		outDataPriority << endl << "In Clock Cycle: " << inClockCycle << endl;
		outDataPriority << "Out Clock Cycle: " << outClockCycle << endl << endl;

	
}


// Four register clock cycle function with 4 different kinds of queue
void fourRegisterSimulation(int array1[], int array2[], int array3[], int array4[], int priorityArray[],
	ofstream &outDataLIFO, ofstream &outDataFIFO, ofstream &outDataSorted, ofstream &outDataPriority)
{


	// Variable declaration in the function
	int column = 10;
	int inRegisterOne = 0;
	int inRegisterTwo = 0;
	int inRegisterThree = 0;
	int inRegisterFour = 0;
	int outRegisterOne = 0;
	int outRegisterTwo = 0;
	int outRegisterThree = 0;
	int outRegisterFour = 0;
	int inClockCycle = 0;
	int outClockCycle = 0;

	// Creates objects of the classes
	stack implementStack;
	queue implementQueue;
	queue implementSorted;
	priority implementPriority;


	// Labels for the output file
	outDataLIFO << "\t\tLIFO " << endl;
	outDataFIFO << "\t\tFIFO " << endl;
	outDataSorted << "\t\tSorted " << endl;


	// For loop to add the first 10 elements to the data structure
	for (int i = 0; i < column; i++)
	{

		implementStack.push(array1[i]);
		implementQueue.addQueue(array2[i]);
		implementSorted.sortQueue(array3[i]);
		implementPriority.insertPriority(array4[i], priorityArray[i]);
		inClockCycle++;

	}


	// For loop to add and go through the rest of the elements
	for (int j = column; j < SIZE; j++)
	{

		// LIFO Stack
		inRegisterOne = array1[j];
		
		// FIFO Queue
		inRegisterTwo = array2[j];

		// Sorted Queue
		inRegisterThree = array3[j];

		// Priority Queue
		inRegisterFour = array4[j];


		// Sets the output register to the data structure
		outRegisterOne = implementStack.top();
		outRegisterTwo = implementQueue.front();
		outRegisterThree = implementSorted.front();
		outRegisterFour = implementPriority.priorityFront();
		outClockCycle++;


		// Removes an element off the data structure
		implementStack.pop();
		implementQueue.deleteQueue();
		implementSorted.deleteQueue();
		implementPriority.deleteQueue();


		// Adds the next element to the data structure
		implementStack.push(inRegisterOne);
		implementQueue.addQueue(inRegisterTwo);
		implementSorted.sortQueue(inRegisterThree);
		implementPriority.insertPriority(inRegisterFour, priorityArray[j]);
		inClockCycle++;


		// Outputs the top element of the data structure
		outDataLIFO << setw(2) << outRegisterOne << setw(2) << " ";
		outDataFIFO << setw(2) << outRegisterTwo << setw(2) << " ";
		outDataSorted << setw(2) << outRegisterThree << setw(2) << " ";


		// If statement to output the stack in a 10x10 chart
		if ((j + 1) % column == 0)
		{

			// Adds a line of space
			outDataLIFO << endl;
			outDataFIFO << endl;
			outDataSorted << endl;
			outDataPriority << endl;

		}


	}



	// For loop to display the last 10 elements
	for (int i = 0; i < column; i++)
	{


		// Sets the output register to the data structure
		outRegisterOne = implementStack.top();
		outRegisterTwo = implementQueue.front();
		outRegisterThree = implementSorted.front();
		outRegisterFour = implementPriority.priorityFront();
		outClockCycle++;


		// Removes an element off the data structure
		implementStack.pop();
		implementQueue.deleteQueue();
		implementSorted.deleteQueue();
		implementPriority.deleteQueue();


		// Outputs the top element of the data structure
		outDataLIFO << setw(2) << outRegisterOne << setw(2) << " ";
		outDataFIFO << setw(2) << outRegisterTwo << setw(2) << " ";
		outDataSorted << setw(2) << outRegisterThree << setw(2) << " ";
		

	}


	// Calls the print function from the priority class
	implementPriority.printPriority(outDataPriority);

	outDataLIFO << endl << endl;
	outDataLIFO << endl << "In Clock Cycle: " << inClockCycle << endl;
	outDataLIFO << "Out Clock Cycle: " << outClockCycle << endl << endl;

	outDataFIFO << endl << endl;
	outDataFIFO << endl << "In Clock Cycle: " << inClockCycle << endl;
	outDataFIFO << "Out Clock Cycle: " << outClockCycle << endl << endl;

	outDataSorted << endl << endl;
	outDataSorted << endl << "In Clock Cycle: " << inClockCycle << endl;
	outDataSorted << "Out Clock Cycle: " << outClockCycle << endl << endl;

	outDataPriority << endl << endl;
	outDataPriority << endl << "In Clock Cycle: " << inClockCycle << endl;
	outDataPriority << "Out Clock Cycle: " << outClockCycle << endl << endl;


}