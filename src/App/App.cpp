#include "App.h"
#include "Sample/sample_triangle.h"


App::App(int width, int height) : camera(width, height, true)
{
	if (!glfwInit())
		std::cout << "error initializing glfw" << std::endl;
	window = glfwCreateWindow(width, height, "my window", NULL, NULL);
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

	renderer = new Renderer;
    sample = get_sample_triangle_data();

}

App::~App()
{
	delete renderer;
	glfwDestroyWindow(window);
	glfwTerminate();
}

void App::clear(float r, float g, float b, float a)
{
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void App::update()
{
	//renderer->updateProjectionViewMatrix(camera.getProjectionViewMatrix());
}

void App::draw()
{
	clear(0.f, 0.f, 0.f, 0.f);
    renderer->draw(sample);
	glfwSwapBuffers(window);
	glfwPollEvents();
}
