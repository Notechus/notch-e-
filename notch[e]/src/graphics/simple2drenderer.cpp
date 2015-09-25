#include "simple2drenderer.h"

namespace notche
{
	namespace graphics
	{

		void Simple2DRenderer::submit(const Renderable2D* renderable)
		{
			renderQueue.push_back(renderable);
		}

		void Simple2DRenderer::flush()
		{
			while (!renderQueue.empty())
			{
				const Renderable2D* renderable = renderQueue.front();
				renderable->getVAO()->bind();
				renderable->getIBO()->bind();

				renderable->getShader().setUniformMat4("ml_matrix", maths::mat4::translation(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

				renderable->getVAO()->unbind();
				renderable->getIBO()->unbind();

				renderQueue.pop_front();
			}
		}
	}
}