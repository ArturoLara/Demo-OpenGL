#include "window.h"
#include <iostream>

#include "../utils/windowutils.h"

namespace gfx
{

	Window::Window() :
		theWidth(0),
		theHeight(0),
		aFullscreen(false),
		aWindow(NULL)
	{
		if (!glfwInit())
		{
			std::cout << "[CORE] Failed to initialize GLFW" << std::endl;
		}

		const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		utils::windowWidth = mode->width;
		utils::windowHeight = mode->height;

		utils::widthScale = utils::baseWindowWidth / utils::windowWidth;
		utils::heightScale = utils::baseWindowHeight / utils::windowHeight;

		utils::windowAspect = utils::windowWidth / utils::windowHeight;

		setViewport();
	}

	Window::~Window()
	{
		if (aWindow != NULL)
		{
			glfwTerminate();
		}
	}

	bool Window::init(const std::string &screenTitle, int window_width, int window_height, bool isFullscreen)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);

		// Create window
		aWindow = glfwCreateWindow(window_width, window_height, screenTitle.c_str(),
				isFullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);

		// Create renderer for window
		glfwMakeContextCurrent(aWindow);

		if (!aWindow)
		{
			std::cout << "[CORE] Window could not be created!" << std::endl;
			glfwTerminate();
			return false;
		}

		std::cout << "[CORE] Window created" << std::endl;

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}
		glViewport(utils::viewportX, utils::viewportY, utils::viewportWidth, utils::viewportHeight);



		theWidth = window_width;
		theHeight = window_height;


		// Setup callbacks
		glfwSetWindowSizeCallback(aWindow, windowResize);
		glfwSetErrorCallback(ErrorCallback);
		glfwSwapInterval(0);

		std::cout << "[CORE] OpenGL context created" << std::endl;

		std::cout << "[CORE] " << glGetString(GL_VERSION) << std::endl;

		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glLineWidth(1);

		glfwSetWindowUserPointer(aWindow, this);

		return true;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::pollEvents()
	{
		glfwPollEvents();
	}

	void Window::swap()
	{
		glfwSwapBuffers(aWindow);
	}

	bool Window::isClosed() const
	{
		return glfwWindowShouldClose(aWindow) == 1;
	}

	void Window::setSize(int width, int height)
	{
		theWidth = width;
		theHeight = height;
	}

	void Window::setClearColorNormalized(float r, float g, float b)
	{
		glClearColor(r, g, b, 1.0f);
	}

	void Window::setClearColor(int r, int g, int b)
	{
		float red, green, blue;
		red = r / 255.0f;
		green = g / 255.0f;
		blue = b / 255.0f;

		glClearColor(red, green, blue, 1.0f);
	}

	void Window::setViewport()
	{
		// figure out the largest area that fits in this resolution at the desired aspect ratio
		utils::viewportWidth = utils::windowWidth;
		utils::viewportHeight = (int)(utils::viewportWidth / utils::baseAspectRatio + 0.5f);

		if (utils::viewportHeight > utils::windowHeight)
		{
		   //It doesn't fit our height, we must switch to pillarbox then
			utils::viewportHeight = utils::windowHeight ;
			utils::viewportWidth = (int)(utils::viewportHeight * utils::baseAspectRatio + 0.5f);
		}

		// set up the new viewport centered in the backbuffer
		utils::viewportX = (utils::windowWidth  / 2) - (utils::viewportWidth / 2);
		utils::viewportY = (utils::windowHeight / 2) - (utils::viewportHeight / 2);

	}

	void windowResize(GLFWwindow *window, int width, int height)
	{
		Window *windowClass = (Window*)glfwGetWindowUserPointer(window);
		windowClass->setSize(width, height);

		utils::windowWidth = width;
		utils::windowHeight = height;

		utils::widthScale = utils::baseWindowWidth / utils::windowWidth;
		utils::heightScale = utils::baseWindowHeight / utils::windowHeight;

		utils::windowAspect = utils::windowWidth / utils::windowHeight;

		windowClass->setViewport();
	}

	void ErrorCallback(int, const char* err_str)
	{
		std::cout << "GLFW Error: " << err_str << std::endl;
	}

} // namespace gfx
