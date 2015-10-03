#pragma once
#ifndef RENDERABLE2D_H_INCLUDED
#define RENDERABLE2D_H_INCLUDED

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"
#include "../maths/maths.h"
#include "shader.h"

namespace notche
{
	namespace graphics
	{

		struct VertexData
		{
			maths::vec3 vertex;
			//maths::vec4 color;
			unsigned int color;
		};

		class Renderable2D
		{
		protected:
			maths::vec3 position;
			maths::vec2 size;
			maths::vec4 color;


		public:
			Renderable2D(maths::vec3 position_, maths::vec2 size_, maths::vec4 color_)
				:position(position_), size(size_), color(color_)
			{

			}
			virtual ~Renderable2D()
			{

			}

			inline const maths::vec3& getPosition() const { return position; }
			inline const maths::vec2& getSize() const { return size; }
			inline const maths::vec4& getColor() const { return color; }
			inline void setPosition(const maths::vec3 pos) { position = pos; }
			inline void setSize(const maths::vec2 size) { this->size = size; }
			inline void setColor(const maths::vec4 color) { this->color = color; }
		};
	}
}

#endif