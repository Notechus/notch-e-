#pragma once
#ifndef SIMPLE2DRENDERER_H_INCLUDED
#define SIMPLE2DRENDERER_H_INCLUDED

#include <deque>
#include "renderer2d.h"

namespace notche
{
	namespace graphics
	{

		class Simple2DRenderer : public Renderer2D
		{
		private:
			std::deque<const Renderable2D*> renderQueue;
		public:
			virtual void submit(const Renderable2D* renderable) override;
			virtual void flush() override;
		};

	}
}

#endif