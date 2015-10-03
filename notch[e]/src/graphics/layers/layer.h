#pragma once
#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include "../renderable2d.h"
#include "../renderer2d.h"

namespace notche
{
	namespace graphics
	{

		class Layer
		{
		protected:
			Renderer2D* renderer;
			std::vector<Renderable2D*> renderables;
			Shader* shader;
			maths::mat4 projectionMatrix;
		protected:
			Layer(Renderer2D* renderer_, Shader* shader_, maths::mat4 projectionMatrix_);
		public:
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			virtual void render();
		};
	}
}

#endif