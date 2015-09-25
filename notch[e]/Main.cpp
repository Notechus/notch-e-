#include <iostream>
#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\maths\maths.h"

#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"

#include "src\graphics\renderer2d.h"
#include "src\graphics\renderable2d.h"
#include "src\graphics\simple2drenderer.h"

using namespace notche;

int main()
{

	graphics::Window window("Notche", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	graphics::Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	maths::mat4 ortho = maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	graphics::Renderable2D sprite(maths::vec3(5, 5, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), shader);
	graphics::Renderable2D sprite2(maths::vec3(7, 1, 0), maths::vec2(2, 3), maths::vec4(0.2f, 0, 1, 1), shader);
	graphics::Simple2DRenderer renderer;

	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", maths::mat4::translation(maths::vec3(4, 3, 0)));
	shader.setUniform2f("light_pos", maths::vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", maths::vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", maths::vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}

	system("PAUSE");
	return 0;
}