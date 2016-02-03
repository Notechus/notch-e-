#pragma once
#ifndef RENDERER2D_H_INCLUDED
#define RENDERER2D_H_INCLUDED
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../maths/maths.h"
#include <vector>


namespace notche
{
	namespace graphics
	{
		class Renderable2D;
		class Renderer2D
		{
		protected:
			std::vector<maths::mat4> transformationStack;
			const maths::mat4* transformationBack;
		protected:
			Renderer2D()
			{
				transformationStack.push_back(maths::mat4::identity());
				transformationBack = &transformationStack.back();
			}
		public:
			void push(const maths::mat4& matrix, bool override = false)
			{
				if (override)
				{
					transformationStack.push_back(matrix);
				} else
				{
					transformationStack.push_back(transformationStack.back() * matrix);
					transformationBack = &transformationStack.back();
				}
			}
			void pop()
			{
				if (transformationStack.size() > 1)	transformationStack.pop_back();
				transformationBack = &transformationStack.back();
				//TODO: Add to log
			}
			virtual void begin() {}
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void end() {}
			virtual void flush() = 0;
		};

	}
}

#endif