#include "vertexarray.h"

namespace notche
{
	namespace graphics
	{

		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &arrayID);
		}

		VertexArray::~VertexArray()
		{
			for (auto& i : buffers)
			{
				delete i;
			}
		}

		void VertexArray::addBuffer(Buffer* buffer, GLuint index)
		{
			bind();

			buffer->bind();
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

			buffer->unbind();
			unbind();


		}

		void VertexArray::bind() const
		{
			glBindVertexArray(arrayID);
		}

		void VertexArray::unbind() const
		{
			glBindVertexArray(0);
		}
	}
}