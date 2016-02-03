#pragma once
#ifndef GROUP_H_INCLUDED
#define GROUP_H_INCLUDED

#include "../renderable2d.h"

namespace notche
{
	namespace graphics
	{
		class Group : public Renderable2D
		{
		private:
			std::vector<Renderable2D*> renderables;
			maths::mat4 transformationMatrix;
		public:
			Group(const maths::mat4& transform);
			void add(Renderable2D* renderable);
			void submit(Renderer2D* renderer) const override;
		};
	}
}

#endif