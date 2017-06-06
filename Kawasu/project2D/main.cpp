#include "Application2D.h"

int main() {
	
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1036, 800, false);

	// deallocation
	delete app;

	return 0;
}