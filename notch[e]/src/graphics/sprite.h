#pragma once
#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "renderable2d.h"

namespace notche
{
	namespace graphics
	{
		class Sprite : public Renderable2D
		{
		private:
		public:
			Sprite(float x, float y, float width, float height, const maths::vec4& color);
		};
	}
}

#endif