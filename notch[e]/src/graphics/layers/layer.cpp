#include "layer.h"

namespace notche
{
	namespace graphics
	{

		Layer::Layer(Renderer2D* renderer_, Shader* shader_, maths::mat4 projectionMatrix_)
			:renderer(renderer_), shader(shader_), projectionMatrix(projectionMatrix_)
		{
			shader->enable();
			shader->setUniformMat4("pr_matrix", projectionMatrix);
			shader->disable();
		}

		Layer::~Layer()
		{
			delete shader;
			delete renderer;
			for (auto& i : renderables)
			{
				delete i;
			}
		}

		void Layer::add(Renderable2D* renderable)
		{
			renderables.push_back(renderable);
		}

		void Layer::render()
		{
			shader->enable();
			renderer->begin();
			int x = 0;
			for (const auto& i : renderables)
			{
				// renderer->submit(i);
				i->submit(renderer);
				renderer->pop();
			}
			renderer->end();
			renderer->flush();
		}
	}
}