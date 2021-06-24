#include "App.h"


App::App(int width, int height, const char* name) : width(width), height(height)
{
	if (!glfwInit())
		std::cout << "error initializing glfw" << std::endl;
	window = glfwCreateWindow(width, height, "my window", NULL, NULL);
	if (!window)
	{
		std::cout << "error with the window creation" << std::endl;
	}
	Call(glfwMakeContextCurrent(window));
	curr_time = glfwGetTime();

	GLenum status = glewInit();
	if (status != GLEW_OK)
		std::cout << "error initializing glew" << std::endl;

	Call(glEnable(GL_TEXTURE_2D));
	Call(glEnable(GL_DEPTH_TEST));
	Call(glCullFace(GL_BACK));

	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);

	color_shader = Shader(std::vector<std::string>{"Shader/ColorVertex.vs", "Shader/ColorFragment.fs"}, std::vector<unsigned int>{GL_VERTEX_SHADER, GL_FRAGMENT_SHADER});
	color_shader.bind();
	color_shader.setUniformMat4fv("projection", projection);
	

}

App::~App()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

glm::vec3 App::clear(float r, float g, float b, float a)
{
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	return (glm::vec3(r, g, b) / 255.0f);
}

void App::update()
{
	int* width = new int;
	int* height = new int;
	glfwGetWindowSize(window, width, height);
	glViewport(0, 0, *width, *height);
	

	double time = glfwGetTime();
	glm::vec3 background = this->clear(255, 255, 255, 1.0f);


	curr_time = time;
	glfwSwapBuffers(window);
	glfwPollEvents();
	if (glfwWindowShouldClose(window))
		closed = true;
}
