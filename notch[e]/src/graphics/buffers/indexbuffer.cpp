#include "indexbuffer.h"

namespace notche
{
	namespace graphics
	{

		IndexBuffer::IndexBuffer(GLushort* data_, GLuint count_) :count(count_)
		{
			glGenBuffers(1, &bufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count_ * sizeof(GLfloat), data_, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
		}
		void IndexBuffer::unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

	}
}