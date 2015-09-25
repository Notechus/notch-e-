#include "renderable2d.h"

namespace notche
{
	namespace graphics
	{

		Renderable2D::Renderable2D(maths::vec3 position_, maths::vec2 size_, maths::vec4 color_, Shader& shader_)
			:position(position_), size(size_), color(color_), shader(shader_)
		{
			vertexArray = new VertexArray();

			GLfloat vertices[] =
			{
				0, 0, 0,
				0, size.y, 0,
				size.x, size.y, 0,
				size.x, 0, 0
			};

			GLfloat colors[] =
			{
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};

			GLushort indices[] =
			{
				0, 1, 2,
				2, 3, 0
			};

			vertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			vertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			indexBuffer = new IndexBuffer(indices, 6);
		}

		Renderable2D::~Renderable2D()
		{
			delete vertexArray;
			delete indexBuffer;
		}

	}
}