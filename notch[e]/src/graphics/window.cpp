#include "window.h"

namespace notche
{
	namespace graphics
	{

		//initialize statics
		/*bool Window::keys[MAX_KEYS];
		bool Window::mouseButtons[MAX_BUTTONS];
		double Window::mouseX;
		double Window::mouseY;*/

		Window::Window(const char *name_, int width_, int height_)
		{
			name = name_;
			width = width_;
			height = height_;
			init();

			for (int i = 0; i < MAX_KEYS; i++)
			{
				keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				mouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::init()
		{

			//initialize GLFW
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW" << std::endl;
				system("EXIT");
			}
			else
			{
				std::cout << "success" << std::endl;
			}

			//create window with given parameters
			window = glfwCreateWindow(width, height, name, NULL, NULL);
			if (!window)
			{
				std::cout << "failed to create window" << std::endl;
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(window);
			//set user pointer for later use
			glfwSetWindowUserPointer(window, this);

			//resize callback
			glfwSetWindowSizeCallback(window, windowResize);
			//key callback
			glfwSetKeyCallback(window, keyCallback);
			//mouse button callback
			glfwSetMouseButtonCallback(window, mouseButtonCallback);
			//cursor pos callback
			glfwSetCursorPosCallback(window, cursorPosCallback);

			//initialize GLEW
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Coult not initialize GLEW" << std::endl;
				system("EXIT");
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		}

		void Window::input()
		{

		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
			{
				std::cout << "OpenGL error: " << error << std::endl;
			}

			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(window) == 1;
		}

		bool Window::isKeyPressed(int keycode) const
		{

			if (keycode >= MAX_KEYS)
			{
				return false;
			}
			return keys[keycode];
		}

		bool Window::isMouseButtonPressed(int button) const
		{
			if (button >= MAX_BUTTONS)
			{
				return false;
			}
			return mouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y) const
		{
			x = mouseX;
			y = mouseY;
		}

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->keys[key] = action != GLFW_RELEASE;
		}

		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mouseX = xpos;
			win->mouseY = ypos;
		}
	}
}