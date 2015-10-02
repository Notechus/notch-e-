#pragma once
#ifndef RENDERER2D_H_INCLUDED
#define RENDERER2D_H_INCLUDED

#include <GL/glew.h>
#include "../maths/maths.h"
#include "renderable2d.h"

namespace notche
{
	namespace graphics
	{

		class Renderer2D
		{
		protected:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};

	}
}

#endif