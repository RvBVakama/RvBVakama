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

	myArray.Insert(1, 4);

	cout << endl << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;

	}

	int value = myArray.PopBack();
	cout << endl << "Values popped " << value << endl;
	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	value = myArray.Remove(3);
	cout << endl << "Values removed were " << value << endl;
	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	value = myArray.PopFront();
	cout << endl << "Values popped were " << value << endl;
	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	myArray[1] = -5;

	cout << "index 1 changed to: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	cout << "Sizes are" << endl << endl;
	cout << "Used is: " << myArray.Size() << endl;
	cout << "Capacity is: " << myArray.Capacity() << endl;

	myArray.Shrink();
	cout << "Sizes are" << endl;
	cout << "Used is: " << myArray.Size() << endl;
	cout << "Capacity is: " << myArray.Capacity() << endl;

	myArray.Clear();
	cout << "Sizes are" << endl;
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

	//DynamicArray<float> copy2(array1);
	//copy2 = array1;
}

//=======================================================================
//					Unit Testing the Stack
//=======================================================================

void TestStack()
{
	printf("\n====================================================\n");
	printf("	   STACK FUNCTIONS TEST");
	printf("\n====================================================\n\n");

	Stack<int> myStack;
	DynamicArray<int> myArray(3);

	cout << "Adding initial values to a dynamic array" << endl << endl;
	myArray.PushBack(9);
	myArray.PushBack(8);
	myArray.PushBack(7);
	myArray.PushBack(6);
	myArray.PushBack(5);

	myStack.m_pData = myArray;

}

//=======================================================================
//					Unit Testing the LinkedList
//=======================================================================

void TestLinkedList()
{
	printf("\n====================================================\n");
	printf("	   LINKED LIST FUNCTIONS TEST");
	printf("\n====================================================\n\n");


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
