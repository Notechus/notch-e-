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

		class Renderable2D
		{
		protected:
			maths::vec3 position;
			maths::vec2 size;
			maths::vec4 color;

			VertexArray* vertexArray;
			IndexBuffer* indexBuffer;
			Shader& shader;
		public:
			Renderable2D(maths::vec3 position_, maths::vec2 size_, maths::vec4 color_, Shader& shader_);
			virtual ~Renderable2D();

			inline const VertexArray* getVAO() const { return vertexArray; }
			inline const IndexBuffer* getIBO() const { return indexBuffer; }
			inline Shader& getShader() const { return shader; }
			inline const maths::vec3& getPosition() const { return position; }
			inline const maths::vec2& getSize() const { return size; }
			inline const maths::vec4& getColor() const { return color; }
		};
	}
}

#endif