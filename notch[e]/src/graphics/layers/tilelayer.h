#pragma once
#ifndef TILELAYER_H_INCLUDED
#define TILELAYER_H_INCLUDED

#include "layer.h"
#include "..\batchrenderer2d.h"

namespace notche
{
	namespace graphics
	{

		class TileLayer : public Layer
		{
		public:
			TileLayer(Shader* shader_);
			~TileLayer();
			//virtual void add(Renderable2D* renderable);
			//virtual void render();
		};
	}
}

#endif