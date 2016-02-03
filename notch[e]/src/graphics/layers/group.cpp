#include "group.h"

namespace notche
{
	namespace graphics
	{
		Group::Group(const maths::mat4& transform)
			:transformationMatrix(transform)
		{
			
		}

		void Group::add(Renderable2D* renderable)
		{
			renderables.push_back(renderable);
		}

		void Group::submit(Renderer2D* renderer) const
		{
			renderer->push(transformationMatrix);

			for(const Renderable2D* rend : renderables)
			{
				rend->submit(renderer);
			}
			renderer->pop();
		}
	}
}