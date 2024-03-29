#include <iostream>
#include "ResourceManager/ResourceHolder.h"
#include "App/App.h"
#include "Clock/Clock.h"

const int WIDTH = 800;
const int HEIGHT = 600;

App Application(WIDTH, HEIGHT);


int main()
{
	while (!Application.isClosed())
	{
		Application.update();
		Application.draw();
	}
	return 0;
}