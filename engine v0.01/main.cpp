#include <iostream>
#include "engine v0.01/App/App.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const float ASPECT_RATIO = (float)WIDTH / (float)HEIGHT;


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
	double curr_time = glfwGetTime();

	GLenum status = glewInit();
	if (status != GLEW_OK)
		std::cout << "error initializing glew" << std::endl;

	Call(glEnable(GL_TEXTURE_2D));
	Call(glEnable(GL_DEPTH_TEST));
	Call(glCullFace(GL_BACK));

	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(WIDTH), static_cast<float>(HEIGHT), 0.0f, -1.0f, 1.0f);
	SpriteRenderer renderer(projection);

	Texture tex1("creeper.png");

	while (!glfwWindowShouldClose(window))
	{
		int* width = new int;
		int* height = new int;
		glfwGetWindowSize(window, width, height);
		glViewport(0, 0, *width, *height);


		double time = glfwGetTime();
		clear(0.0f, 255.0f, 255.0f, 1.0f);



		renderer.draw(tex1, glm::vec2(100.0f, 100.0f), glm::vec2(100.0f, 100.0f), glm::vec3(1.0f, 1.0f, 1.0f));

		curr_time = time;
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}