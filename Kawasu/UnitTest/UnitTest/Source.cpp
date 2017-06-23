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

	printf("\n----------------------------------------------------\n");

	int value = myArray.PopBack();
	printf("\nPopping last value\n");
	cout << endl << "Value popped\n" << value << endl;
	cout << "\nValues are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n----------------------------------------------------\n");

	printf("\nRemoving a value\n");

	value = myArray.Remove(3);
	cout << endl << "Value removed\n" << value << endl;
	cout << "\nValues are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n----------------------------------------------------\n");

	printf("\nPopping a value\n");
	
	value = myArray.PopFront();
	cout << endl << "Value popped\n" << value << endl;
	cout << "\nValues are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n----------------------------------------------------\n");

	printf("\nChanging a value at an index\n");

	myArray[1] = -5;

	cout << "\nIndex 1 changed to" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	printf("\n----------------------------------------------------\n");

	cout << "\nCurrent sizes are" << endl << endl;
	cout << "Used is: " << myArray.Size() << endl;
	cout << "Capacity is: " << myArray.Capacity() << endl;

	printf("\n----------------------------------------------------\n");
	printf("\nShrinking the capacity of the array\n");
	myArray.Shrink();
	cout << "Used is: " << myArray.Size() << endl;
	cout << "Capacity is: " << myArray.Capacity() << endl;

	printf("\n----------------------------------------------------\n");
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
	cout << "Copy is" << endl;
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

	printf("----------------------------------------------------\n");

	bool bIsEmpty = myStack.IsEmpty();

	if (bIsEmpty)
		printf("\nThe Stack is empty\n\n");
	else
		printf("\nThe Stack is not empty\n\n");

	printf("----------------------------------------------------\n");

	int nSize = myStack.Size();

	printf("\nThe Stack has %d elements\n", nSize);

	printf("----------------------------------------------------\n");

	cout << endl << "Current values are" << endl;

	for (int i = 0; i < myStack.m_pData.Size(); ++i)
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

	printf("\n----------------------------------------------------\n");

	cout << endl << "Current values are" << endl;

	for (int i = 0; i < myStack.m_pData.Size(); ++i)
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

	printf("\n----------------------------------------------------\n");

	myStack.Top();

}

//=======================================================================
//					Unit Testing the LinkedList
//=======================================================================

void TestLinkedList()
{
	printf("\n====================================================\n");
	printf("	   LINKED LIST FUNCTIONS TEST");
	printf("\n====================================================\n\n");

	LinkedList<int> myList;

	myList.PushFront(6);
	myList.PushFront(3);
	myList.PushFront(1);

	myList.PushBack(78);
	myList.PushBack(12);
	myList.PushBack(34);
	


}



int main()
{
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
