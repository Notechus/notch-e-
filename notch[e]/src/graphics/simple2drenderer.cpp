#include "simple2drenderer.h"

namespace notche
{
	namespace graphics
	{

		void Simple2DRenderer::submit(const Renderable2D* renderable)
		{
			renderQueue.push_back((StaticSprite*) renderable);
		}

		void Simple2DRenderer::flush()
		{
			while (!renderQueue.empty())
			{
				const StaticSprite* sprite = renderQueue.front();
				sprite->getVAO()->bind();
				sprite->getIBO()->bind();

				sprite->getShader().setUniformMat4("ml_matrix", maths::mat4::translation(sprite->getPosition()));
				glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

				sprite->getIBO()->unbind();
				sprite->getVAO()->unbind();

				renderQueue.pop_front();
			}
		}
	}
}