#pragma once
#ifndef VERTEXARRAY_H_INCLUDED
#define VERTEXARRAY_H_INCLUDED

#include <GL/glew.h>
#include <vector>
#include "buffer.h"

namespace notche
{
	namespace graphics
	{

		class VertexArray
		{
		private:
			GLuint arrayID;
			std::vector<Buffer*> buffers;
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unbind() const;
		};
	}
}

#endif