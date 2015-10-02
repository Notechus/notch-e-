#include "static_sprite.h"

namespace notche
{
	namespace graphics
	{
		StaticSprite::StaticSprite(float x, float y, float width, float height, const maths::vec4& color, Shader& shader_)
			:Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), color), shader(shader_)
		{
			vertexArray = new VertexArray();
			GLfloat vertices[] =
			{
				0, 0, 0,
				0, height, 0,
				width, height, 0,
				width, 0, 0
			};

			GLfloat colors[] =
			{
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};


			vertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			vertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] =
			{
				0, 1, 2,
				2, 3, 0
			};

			indexBuffer = new IndexBuffer(indices, 6);
		}

		StaticSprite::~StaticSprite()
		{
			delete vertexArray;
			delete indexBuffer;
		}
	}
}