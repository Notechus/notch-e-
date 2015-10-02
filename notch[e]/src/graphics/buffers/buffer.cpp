#include "buffer.h"

namespace notche
{
	namespace graphics
	{

		Buffer::Buffer(GLfloat* data_, GLsizei count_, GLuint componentCount_) :componentCount(componentCount_)
		{
			glGenBuffers(1, &bufferID);
			glBindBuffer(GL_ARRAY_BUFFER, bufferID);
			glBufferData(GL_ARRAY_BUFFER, count_ * sizeof(GLfloat), data_, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		Buffer::~Buffer()
		{
			glDeleteBuffers(1, &bufferID);
		}

		void Buffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		}
		void Buffer::unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

	}
}