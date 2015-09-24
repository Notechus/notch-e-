#pragma once
#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace notche {
	namespace input {

#define MAX_KEYS		1024
#define MAX_BUTTONS		32

		class Input {
		private:
			static bool keys[MAX_KEYS];
			static bool mouseButtons[MAX_BUTTONS];
			static double mouseX, mouseY;

		public:
			static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		};
	}
}
#endif