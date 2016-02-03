#pragma once
#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "..\maths\maths.h"

namespace notche
{
	namespace graphics
	{

#define MAX_KEYS		1024
#define MAX_BUTTONS		32

		class Window
		{

		private:
			const char *name;
			int width, height;
			GLFWwindow* window;
			bool close;

			bool keys[MAX_KEYS];
			bool mouseButtons[MAX_BUTTONS];
			double mouseX, mouseY;

		public:
			Window(const char* name_, int width_, int height_);
			~Window();
			void input(maths::vec3& sprite_pos, bool& jumped, const float& gravity, float& y_velocity);
			void update();
			bool closed() const;
			void clear() const;
			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }
			bool isKeyPressed(int keycode) const;
			bool isMouseButtonPressed(int button) const;
			void getMousePosition(double& x, double& y) const;
		private:
			void init();
			friend void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
			friend void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
		};

		void windowResize(GLFWwindow *window, int width, int height);
		void check_position(maths::vec3& position, bool& jumped);
	}
}

#endif