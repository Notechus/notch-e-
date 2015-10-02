#pragma once
#ifndef STATICSPRITE_H_INCLUDED
#define STATICSPRITE_H_INCLUDED

#include "renderable2d.h"

namespace notche
{
	namespace graphics
	{
		class StaticSprite : public Renderable2D
		{
		private:
			VertexArray* vertexArray;
			IndexBuffer* indexBuffer;
			Shader& shader;
		public:
			StaticSprite(float x, float y, float width, float height, const maths::vec4& color, Shader& shader_);
			~StaticSprite();

			inline const VertexArray* getVAO() const { return vertexArray; }
			inline const IndexBuffer* getIBO() const { return indexBuffer; }
			inline Shader& getShader() const { return shader; }
		};
	}
}
#endif