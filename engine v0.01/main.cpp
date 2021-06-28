#include <iostream>
#include "App/App.h"
#include "engine v0.01/Clock/Clock.h"
#include "engine v0.01/Entity/Entity.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const float ASPECT_RATIO = (float)WIDTH / (float)HEIGHT;

const double MILISECONDS_PER_UPDATE = double(100) / double(60);


void clear(float r, float g, float b, float a)
{
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


int main()
{
	if (!glfwInit())
		std::cout << "error initializing glfw" << std::endl;
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "my window", NULL, NULL);
	if (!window)
	{
		std::cout << "error with the window creation" << std::endl;
	}
	Call(glfwMakeContextCurrent(window));

	GLenum status = glewInit();
	if (status != GLEW_OK)
		std::cout << "error initializing glew" << std::endl;

	Call(glEnable(GL_TEXTURE_2D));
	Call(glEnable(GL_DEPTH_TEST));
	Call(glCullFace(GL_BACK));

	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(WIDTH), static_cast<float>(HEIGHT), 0.0f, -1.0f, 1.0f);
	SpriteRenderer renderer(projection);

	Texture tex1("tetris.png");

	int FPS_counter = 0;
	int update_counter = 0;
	double lag = 0;
	Clock tick_clock, FPS_clock;
	std::queue<DrawRequest> drawQueue;

	Entity tetrimino(glm::vec2(100.0f, 100.0f), glm::vec2(30.0f, 30.0f), 0.0f, &tex1, 2, 0);

	while (!glfwWindowShouldClose(window))
	{
		int* width = new int;
		int* height = new int;
		glfwGetWindowSize(window, width, height);
		glViewport(0, 0, *width, *height);



		lag += tick_clock.getTime();
		tick_clock.reset();
		do
		{
			lag -= MILISECONDS_PER_UPDATE;
			update_counter++;
		} while (lag >= MILISECONDS_PER_UPDATE);

		tetrimino.sendDrawRequest(drawQueue);

		clear(0.0f, 255.0f, 255.0f, 1.0f);
		//renderer.draw(tex1, glm::vec2(100.0f, 100.0f), glm::vec2(200.0f, 100.0f), glm::vec3(1.0f, 1.0f, 1.0f));
		while (!drawQueue.empty())
		{
			renderer.draw(drawQueue.front());
			drawQueue.pop();
		}

		glfwSwapBuffers(window);
		glfwPollEvents();



		if (FPS_clock.getTime() > 1000.0f)
		{
			std::cout << "FPS: " << FPS_counter << ", updates: " << update_counter << std::endl;
			FPS_counter = 0;
			update_counter = 0;
			FPS_clock.reset();
		}
		else FPS_counter++;
		
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}