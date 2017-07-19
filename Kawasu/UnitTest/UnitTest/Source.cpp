#include <iostream>
#include "DynamicArray.h"
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

//=======================================================================
//					Unit Testing the DynamicArray
//=======================================================================

void TestDynamicArray()
{
	printf("====================================================\n");
	printf("	   DYNAMIC ARRAY FUNCTIONS TEST");
	printf("\n====================================================\n\n");

	DynamicArray<int> myArray(3);

	cout << "Initail Sizes" << endl;
	cout << "Array size is: " << myArray.Size() << endl;
	cout << "Array capacity is: " << myArray.Capacity() << endl << endl;

	cout << "Adding Initial Values" << endl << endl;
	myArray.PushBack(9);
	myArray.PushBack(8);
	myArray.PushBack(7);
	myArray.PushBack(6);
	myArray.PushBack(5);

	myArray.PushFront(1);

	cout << "Sizes are" << endl;
	cout << "Used is: " << myArray.Size() << endl;
	cout << "Capacity is: " << myArray.Capacity() << endl;

	cout << endl << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n-------------------------------------------------------------------\n");

	int value = myArray.PopBack();
	printf("\nPopping last value\n");
	cout << endl << "Value popped\n" << value << endl;
	cout << "\nValues are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nRemoving a value\n");

	value = myArray.Remove(3);
	cout << endl << "Value removed\n" << value << endl;
	cout << "\nValues are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nPopping a value\n");
	
	value = myArray.PopFront();
	cout << endl << "Value popped\n" << value << endl;
	cout << "\nValues are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nChanging a value at an index\n");

	myArray[1] = -5;

	cout << "\nIndex 1 changed to" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n-------------------------------------------------------------------\n");

	cout << "\nCurrent sizes are" << endl << endl;
	cout << "Used is: " << myArray.Size() << endl;
	cout << "Capacity is: " << myArray.Capacity() << endl;

	printf("\n-------------------------------------------------------------------\n");
	printf("\nShrinking the capacity of the array\n");
	myArray.Shrink();
	cout << "\nUsed is: " << myArray.Size() << endl;
	cout << "Capacity is: " << myArray.Capacity() << endl;

	printf("\n-------------------------------------------------------------------\n");
	printf("\nClearing the array's elements\n\n");
	myArray.Clear();
	cout << "Used is: " << myArray.Size() << endl;
	cout << "Capacity is: " << myArray.Capacity() << endl;
}
void TestDynamicArrayConstructors()
{
	printf("\n====================================================\n");
	printf("	   DYNAMIC ARRAY CONSTRUCTOR TEST");
	printf("\n====================================================\n\n");
	DynamicArray<float> array1(4);
	array1.PushBack(3.5f);
	array1.PushBack(1.5f);
	array1.PushBack(2.5f);
	array1.PushBack(5.5f);

	DynamicArray<float> copy(array1);
	cout << "Copy is" << endl << endl;
	for (int i = 0; i < copy.Size(); ++i)
	{
		cout << copy[i] << endl;
	}
}

//=======================================================================
//					Unit Testing the Stack
//=======================================================================

void TestStack()
{
	printf("\n====================================================\n");
	printf("	   STACK FUNCTIONS TEST");
	printf("\n====================================================\n\n");

	Stack<int> myStack(5);

	cout << "Adding some values to a new dynamic array" << endl << endl;
	myStack.Push(9);
	myStack.Push(8);
	myStack.Push(7);
	myStack.Push(6);
	myStack.Push(5);

	printf("-------------------------------------------------------------------\n");

	bool bIsEmpty = myStack.IsEmpty();

	if (bIsEmpty)
		printf("\nThe Stack is empty\n\n");
	else
		printf("\nThe Stack is not empty\n\n");

	printf("-------------------------------------------------------------------\n");

	int nSize = myStack.Size();

	printf("\nThe Stack has %d elements\n\n", nSize);

	printf("-------------------------------------------------------------------\n");

	cout << endl << "Current values are" << endl;

	for (int i = 0; i < myStack.Size(); ++i)
	{
		cout << myStack.m_pData[i] << endl;
	}

	myStack.Push(99);

	printf("\nPushed value '99' onto the stack\n");

	cout << endl << "Updated values are" << endl;

	for (int i = 0; i < myStack.Size(); ++i)
	{
		cout << myStack.m_pData[i] << endl;
	}

	printf("\n-------------------------------------------------------------------\n");

	cout << endl << "Current values are" << endl;

	for (int i = 0; i < myStack.Size(); ++i)
	{
		cout << myStack.m_pData[i] << endl;
	}

	printf("\nPopping off 3 values\n");
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();

	cout << endl << "Leftover values are" << endl;

	for (int i = 0; i < myStack.Size(); ++i)
	{
		cout << myStack.m_pData[i] << endl;
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nCollecting the top element in the array\n");

	int nStackTop = myStack.Top();

	cout << endl << "Current values are" << endl;

	for (int i = 0; i < myStack.Size(); ++i)
	{
		cout << myStack.m_pData[i] << endl;
	}

	cout << endl << "Collected value " << nStackTop << endl;

	printf("\n-------------------------------------------------------------------\n");

	printf("\nCollecting the second top element in the array\n");

	int nStackSecondTop = myStack.SecondFromTop();

	cout << endl << "Current values are" << endl;

	for (int i = 0; i < myStack.Size(); ++i)
	{
		cout << myStack.m_pData[i] << endl;
	}

	cout << endl << "Collected value " << nStackSecondTop << endl;

	printf("\n-------------------------------------------------------------------\n");

	printf("\nPopping off the remaining values\n");
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();

	cout << endl << "Current values are" << endl;

	if (myStack.Size() == 0)
	{
		printf("\nnone\n");
	}
	else
	{
		for (int i = 0; i < myStack.Size(); ++i)
		{
			cout << myStack.m_pData[i] << endl;
		}
	}

	bIsEmpty = myStack.IsEmpty();

	if (bIsEmpty)
		printf("\nThe Stack is empty\n");
	else
		printf("\nThe Stack is not empty\n");
}

//=======================================================================
//					Unit Testing the LinkedList
//=======================================================================

void TestLinkedList()
{
	printf("\n====================================================\n");
	printf("	   LINKED LIST FUNCTIONS TEST");
	printf("\n====================================================\n");

	LinkedList<int> myList;

	Iter<int> iter;

	printf("\nCreating and populating a new LinkedList . . .\n");

	myList.PushFront(6);
	myList.PushFront(3);
	myList.PushFront(1);

	myList.PushBack(78);
	myList.PushBack(12);
	myList.PushBack(34);
	myList.PushBack(34);
	
	printf("\nTesting operator overloads, peek at the code to see!\n");	

	cout << endl << "Current values are" << endl;

	iter = myList.Begin(); //=

	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; // --
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nInserting with a value which creates a node and assigns it a value\n");

	//moving the iter back to the start	
	iter = myList.Begin(); //=
	
	cout << endl << "Current values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	int nInsertValue = 5;

	int nInsertIndex = 2;

	myList.Insert(nInsertValue, nInsertIndex);
	
	cout << endl << "Inserting a new node with value " << nInsertValue << " at index " << nInsertIndex << endl;

	//moving the iter back to the start	
	iter = myList.Begin(); //=

	cout << endl << "Updated values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nInserting with a node which already has a value\n");

	//moving the iter back to the start	
	iter = myList.Begin(); //=

	cout << endl << "Current values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	ListNode<int>* newNodeOne = new ListNode<int>;

	newNodeOne->data = 30;

	int nInsertIndexOne = 3;

	myList.Insert(newNodeOne, nInsertIndexOne);

	cout << endl << "Inserting a new node with value " << newNodeOne->data << " at index " << nInsertIndexOne << endl;

	//moving the iter back to the start	
	iter = myList.Begin(); //=

	cout << endl << "Updated values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	myList.Delete(newNodeOne);

	printf("\n-------------------------------------------------------------------\n");

	//ListNode<int>* newNodeCatch;// = new ListNode<int>;

	printf("\nCatching the first node\n");

	ListNode<int>* newNodeCatch = myList.First();

	printf("\nNode caught!\n");

	cout << newNodeCatch->data << endl;

	printf("\n-------------------------------------------------------------------\n");

	printf("\nCatching the last node\n");

	newNodeCatch = myList.Last();

	printf("\nNode caught!\n");

	cout << newNodeCatch->data << endl;

	printf("\n-------------------------------------------------------------------\n");

	printf("\nCounting how many nodes exist\n");

	int nCount = myList.Count();

	printf("\nThere are %d nodes!\n", nCount);

	myList.Delete(newNodeCatch);

	printf("\n-------------------------------------------------------------------\n");
	
	//printf("\nDeleting a node\n");
	//
	////moving the iter back to the start		
	//iter = myList.Begin(); //=
	//
	//cout << endl << "Current values are" << endl;
	//while (iter != myList.End()) // != ==
	//{
	//	std::cout << iter.value() << std::endl; //value()
	//	++iter; //++ --
	//}
	//
	//printf("\nDeleting the node\n");
	//
	//myList.Delete(newNode);
	//
	////moving the iter back to the start		
	//iter = myList.Begin(); //=
	//
	//cout << endl << "Updated values are" << endl;
	//while (iter != myList.End()) // != ==
	//{
	//	std::cout << iter.value() << std::endl; //value()
	//	++iter; //++ --
	//}
	//
	//printf("\n-------------------------------------------------------------------\n");

	printf("\nErasing a node, this uses the Delete function\n");

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Current values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\nErasing the node\n");

	myList.Erase(iter, 4);

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Updated values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nRemoving all node with the same value\n");

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Current values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	int nRemoveValue = 34;

	printf("\nRemoving all nodes with value %d\n", nRemoveValue);

	myList.Remove(nRemoveValue);

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Updated values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nPopping a node of the back\n");

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Current values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\nPopping the node of the back!\n");

	myList.PopBack();

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Updated values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nPopping a node of the front\n");

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Current values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\nPopping the node of the front!\n");

	myList.PopFront();

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Updated values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\n-------------------------------------------------------------------\n");

	printf("\nClearing the array\n");

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Current values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\nClearing!\n");

	myList.Clear();

	//moving the iter back to the start		
	iter = myList.Begin(); //=

	cout << endl << "Updated values are" << endl;
	while (iter != myList.End()) // != ==
	{
		std::cout << iter.value() << std::endl; //value()
		++iter; //++ --
	}

	printf("\n-------------------------------------------------------------------\n");
}

#define _CRTDBG_MAP_ALLOC _CrtDumpMemoryLeaks
#include <stdlib.h>  
#include <crtdbg.h>  

int main()
{
	// Memory leak checker
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// DYNAMIC ARRAY
	// Testing all the functions that Dynamic Array possesses
	TestDynamicArray();
	// Testing all the constructors that Dynamic Array possesses
	TestDynamicArrayConstructors();
	
	// STACK
	// Testing all the functions that Stack possesses
	TestStack();

	// LINKEDLIST
	// Testing all the functions that Linked List possesses
	TestLinkedList();
	
	system("pause");

	return 0;
}