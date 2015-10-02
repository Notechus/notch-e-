#pragma once
#ifndef BATCHRENDERER2D_H_INCLUDED
#define BATCHRENDERER2D_H_INCLUDED

#include "renderer2d.h"
#include "buffers/indexbuffer.h"

namespace notche
{
	namespace graphics
	{

#define RENDERER_MAX_SPRITES	60000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX		0
#define SHADER_COLOR_INDEX		1

		class BatchRenderer2D : public Renderer2D
		{
		private:
			GLuint VAO;
			GLuint VBO;
			VertexData* buffer;
			IndexBuffer* IBO; //60 000
			GLsizei indexCount;
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void begin();
			void end();
			void submit(const Renderable2D* renderable) override;
			void flush() override;
		private:
			void init();

		};
	}
}

#endif