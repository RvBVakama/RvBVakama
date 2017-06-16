#include "Application2D.h"
#include <iostream>
#include <time.h>

int main() {
	srand(time(NULL));

	// allocation
	auto app = new Application2D();
	
	// initialise and loop
	app->run("AIE", 1036, 800, false);

	// deallocation
	delete app;

	return 0;
}