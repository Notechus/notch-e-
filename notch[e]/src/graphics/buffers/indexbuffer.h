#pragma once
#ifndef INDEXBUFFER_H_INCLUDED
#define INDEXBUFFER_H_INCLUDED

#include <GL/glew.h>

namespace notche
{
	namespace graphics
	{

		class IndexBuffer
		{
		private:
			GLuint bufferID;
			GLuint count;
		public:
			IndexBuffer(GLushort* data_, GLuint count_);

			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return count; };
		};
	}
}

#endif