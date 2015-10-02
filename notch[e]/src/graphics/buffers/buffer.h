#pragma once
#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

#include <GL/glew.h>

namespace notche
{
	namespace graphics
	{

		class Buffer
		{
		private:
			GLuint bufferID;
			GLuint componentCount;
		public:
			Buffer(GLfloat* data_, GLsizei count_, GLuint componentCount_);
			~Buffer();
			void bind() const;
			void unbind() const;

			inline GLuint getComponentCount() const { return componentCount; };
		};
	}
}

#endif