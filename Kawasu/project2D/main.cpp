#include "Application2D.h"
#include <iostream>
#include <time.h>

#include "LinkedList.h"

int main() {

	LinkedList<int> myList;
	myList.PushFront(3);
	myList.PushFront(2);
	myList.PushFront(1);

	Iter<int> iter;
	iter = myList.Begin(); //=
	while (iter != myList.End()) // != ==
	{
		std::cout << iter->value() << std::endl; //value()
		++iter; //++ --
	}


	srand(time(NULL));

	// allocation
	auto app = new Application2D();
	
	// initialise and loop
	app->run("AIE", 1036, 800, false);

	// deallocation
	delete app;

	return 0;
}