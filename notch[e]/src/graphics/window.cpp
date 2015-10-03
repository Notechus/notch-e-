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
			glfwSwapInterval(1.0);

			//initialize GLEW
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Coult not initialize GLEW" << std::endl;
				system("EXIT");
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		}

		void Window::input(maths::vec3& sprite_pos, bool& jumped, const float& gravity, float& y_velocity)
		{
			float speed = 1.0f;

			if (sprite_pos.y > 0.0f) //move to physics method
			{
				// update position
				sprite_pos.y -= y_velocity;
				//std::cout << sprite_pos.y << std::endl;
				// update velocity and gravity
				y_velocity += gravity;
				if (sprite_pos.y <= 0.0f) y_velocity = 0.0f;
			}
			if (isKeyPressed(GLFW_KEY_W))
			{
				//sprite_pos.y += 0.1f * speed;
				check_position(sprite_pos, jumped);
			}
			if (isKeyPressed(GLFW_KEY_S))
			{
				//sprite_pos.y -= 0.1f * speed;
				check_position(sprite_pos, jumped);
			}
			if (isKeyPressed(GLFW_KEY_A))
			{
				sprite_pos.x -= 0.1f * speed;
				check_position(sprite_pos, jumped);
			}
			if (isKeyPressed(GLFW_KEY_D))
			{
				sprite_pos.x += 0.1f * speed;
				check_position(sprite_pos, jumped);
			}
			if (isKeyPressed(GLFW_KEY_SPACE))
			{
				if (sprite_pos.y <= 3.0f)
				{
					if (!jumped)
					{//seems to be working
						sprite_pos.y += 0.5f;
						check_position(sprite_pos, jumped);
					}
				}
			}
			if (isKeyPressed(GLFW_KEY_LEFT_SHIFT))
			{
				speed = 1.0f;
			}
			else
			{
				speed = 2.0f;
			}
			if (isKeyPressed(GLFW_KEY_R))
			{
				sprite_pos.y = 8.0f;
				check_position(sprite_pos, jumped);
			}
			check_position(sprite_pos, jumped);
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

		//non-member functions
		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->keys[key] = action != GLFW_RELEASE;
		}

		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->mouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->mouseX = xpos;
			win->mouseY = ypos;
		}

		void check_position(maths::vec3& position, bool& jumped)
		{
			//total height - 8.0 total width - 15.0 for cube size (1,1)
			if (position.x < -16.0f) position.x = -16.0f;
			if (position.z < 0.0f) position.z = 0.0f;
			if (position.x > 15.0f) position.x = 15.0f;
			if (position.y > 8.0f) position.y = 8.0f;
			if (position.y >= 2.5f) //necesseary to validate jump
			{
				jumped = true;
			}
			else if (position.y <= 0.0f)
			{
				jumped = false;
				position.y = 0.0f;
			}
		}
	}
}