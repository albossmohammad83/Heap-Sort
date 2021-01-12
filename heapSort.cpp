/*Mohammad Abdelrahman 
* FILE: heapSort.cpp
* CIS 279 Assignment 5 Heap Sort
* Date:  12/06/16
* Development Env:  Microsoft Visual Studio 2013
* DESCRIPTION:  Heap sort that sorts the items in an array into ascending order
* I'd like this Assignment to replace Assignment 4
*/

#include <math.h>
#include <iostream>
#include <string>
using namespace std;

typedef string ItemType;


//Get Index of the Left Child
int left(int i, int n)
{
	if (2 * i <= n)
	{
		//return 2*i;
		return (2 * i) + 1;
	}
	else{
		return -1;
	}
}

//Get Index of the Right Child
int right(int i, int n)
{
	if ((2 * i) + 1 <= n)
	{
		//return (2*i)+1;
		return 2 * (i + 1);
	}
	else{
		return -1;
	}
}

//Print the current Heap
void printHeap(ItemType a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

//Heapify method
void heapify(ItemType a[], int i, int n)
{
	int largest = i;
	//Find left and right child of the current node
	int leftChild = left(i, n);
	int rightChild = right(i, n);
	//If parent node has a left child
	if (leftChild <= n && leftChild != -1)
	{
		//Determine if left child is larger than the parent node
		if (a[leftChild] > a[i])
		{
			//Left child is larger
			largest = leftChild;
		}
		else{
			//Parent node is larger
			largest = i;
		}
	}
	//If parent node has a right child
	if (rightChild <= n && rightChild != -1)
	{
		//Determine if right child is larger than the parent node
		if (a[rightChild] > a[largest])
		{
			//Right child is larger
			largest = rightChild;
		}
	}
	if (largest != i)
	{
		//Swap current node with the largest child
		ItemType temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a, largest, n);
	}
}


//Create Max Heap
void createHeap(ItemType a[], int n)
{
	//Call heapify method for first half of the array
	for (int k = floor((n - 1) / 2); k >= 0; k--)
	{
		heapify(a, k, n - 1);
	}
	//Print heap
	printHeap(a, n);
	cout << "Initial rebuild to form a heap" << endl;
}

//Swap first and last node of the heap
void removeMax(ItemType a[], int n)
{
	ItemType max = a[0];
	a[0] = a[n - 1];
	a[n - 1] = max;
}

//heapsort method
void heapSort(ItemType a[], int n)
{
	//Print array
	printHeap(a, n);
	cout << "Original array" << endl;
	//Call create max heap to build max heap
	createHeap(a, n);

	//Swap each root node with last node and heapify again to get sorted array
	int size = n;
	for (int i = 1; i < n; i++)
	{
		//Remove Max from the Heap and Heapify again
		removeMax(a, size);
		printHeap(a, n);
		cout << "After swapping " << a[0] << " and " << a[size - 1] << endl;
		size--;
		if (size > 1)
		{
			heapify(a, 0, size - 1);
			printHeap(a, n);
			cout << "rebuild(0, anArray, " << size << ")" << endl;
		}
	}

}

//Main Method
int main()
{
	cout << "Example Test Run Output Display " << endl;
	string a[6] = { "D", "B", "A", "C", "F", "E" };
	heapSort(a, 6);
	for (int i = 0; i < 6; i++)
		cout << a[i] << " ";
	cout << " Sorted array" << endl << endl;


	string b[6] = { "25", "30", "20", "80", "40", "60" };
	heapSort(b, 6);
	for (int i = 0; i < 6; i++)
		cout << b[i] << " ";
	cout << " Sorted array" << endl;
}


/*
Example Test Run Output Display
D B A C F E Original array
F D E C B A Initial rebuild to form a heap
A D E C B F After swapping A and F
E D A C B F rebuild(0, anArray, 5)
B D A C E F After swapping B and E
D C A B E F rebuild(0, anArray, 4)
B C A D E F After swapping B and D
C B A D E F rebuild(0, anArray, 3)
A B C D E F After swapping A and C
B A C D E F rebuild(0, anArray, 2)
A B C D E F After swapping A and B
A B C D E F  Sorted array

25 30 20 80 40 60 Original array
80 40 60 30 25 20 Initial rebuild to form a heap
20 40 60 30 25 80 After swapping 20 and 80
60 40 20 30 25 80 rebuild(0, anArray, 5)
25 40 20 30 60 80 After swapping 25 and 60
40 30 20 25 60 80 rebuild(0, anArray, 4)
25 30 20 40 60 80 After swapping 25 and 40
30 25 20 40 60 80 rebuild(0, anArray, 3)
20 25 30 40 60 80 After swapping 20 and 30
25 20 30 40 60 80 rebuild(0, anArray, 2)
20 25 30 40 60 80 After swapping 20 and 25
20 25 30 40 60 80  Sorted array
Press any key to continue . . .
*/