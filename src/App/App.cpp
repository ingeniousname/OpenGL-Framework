#include "App.h"
#include "src/Sample/sample_triangle.h"
#include "src/OBJLoader/OBJLoader.h"
#include <cmath>


App::App(int width, int height) : camera(width, height, false)
{
	if (!glfwInit())
		std::cout << "error initializing glfw" << std::endl;
	window = glfwCreateWindow(width, height, "my window", nullptr, nullptr);
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
	//Call(glEnable(GL_CULL_FACE));
	Call(glCullFace(GL_BACK));

	renderer = new Renderer;
    //entity.setRenderInfo(get_sample_triangle_data());
    VertexData data = getVertexDataFromOBJ("res/models/untitled.obj");
    entity.setRenderInfo(buildRenderInfoFromData(data));
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
	renderer->updateProjectionViewMatrix(camera.getProjectionViewMatrix({0, 0, -20}));
    entity.update({0, 0, 0}, {fmod(100 * glfwGetTime(), 360), 0, 0}, {1, 1, 1});
	//renderer->updateProjectionViewMatrix(glm::mat4x4(1.0f));

}

void App::draw()
{
	clear(0.f, 0.f, 0.f, 0.f);
    renderer->draw(entity);
	glfwSwapBuffers(window);
	glfwPollEvents();
}
