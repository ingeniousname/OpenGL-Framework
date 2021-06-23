#include <iostream>
#include "App.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const float ASPECT_RATIO = (float)WIDTH / (float)HEIGHT;

int main()
{
	App window(WIDTH, HEIGHT, "2D app");
	while (!window.isClosed())
	{
		window.update();
	}
	return 0;
}