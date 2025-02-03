#include "App.h"
#include "src/OBJLoader/OBJLoader.h"
#include <cmath>


App::App(int width, int height) : camera(width, height, false)
{
	if (!glfwInit())
		std::cout << "error initializing glfw" << std::endl;
	window = std::unique_ptr<GLFWwindow, GLFWwindowDeleter>(glfwCreateWindow(width, height, "my window", nullptr, nullptr));
	if (!window)
	{
		std::cout << "error with the window creation" << std::endl;
	}
	Call(glfwMakeContextCurrent(window.get()));

	GLenum status = glewInit();
	if (status != GLEW_OK)
		std::cout << "error initializing glew" << std::endl;

	Call(glEnable(GL_TEXTURE_2D));
	Call(glEnable(GL_DEPTH_TEST));
	Call(glEnable(GL_CULL_FACE));
	Call(glCullFace(GL_BACK));

	ResourceHolder::get().Models.setFolder("res/models/");
    ResourceHolder::get().Models.load("untitled.obj");

    ResourceHolder::get().Shaders.setFolder("");
    ResourceHolder::get().Shaders.load("Color");


	renderer = std::make_unique<Renderer>(ResourceHolder::get().Shaders.getPointer("Color"));
    entity.setRenderInfo(ResourceHolder::get().Models.get("untitled.obj"));
}

App::~App()
{
	glfwTerminate();
}

void App::clear(float r, float g, float b, float a)
{
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void App::update()
{
	renderer->getShader().setUniformMat4fv("VP", camera.getProjectionViewMatrix({0, 0, -20}));
    entity.update({0, 0, 0}, {fmod(100 * glfwGetTime(), 360), 0, 0}, {1, 1, 1});

}

void App::draw()
{
	clear(0.f, 0.f, 0.f, 0.f);
    renderer->draw(entity);
	glfwSwapBuffers(window.get());
	glfwPollEvents();
}
