#include "tilelayer.h"

namespace notche
{
	namespace graphics
	{

		TileLayer::TileLayer(Shader* shader_)
			: Layer(new BatchRenderer2D(), shader_, maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
		{

		}

		TileLayer::~TileLayer()
		{

		}
	}
}