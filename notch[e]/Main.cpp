#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <time.h>

#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\maths\maths.h"

#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"

#include "src\graphics\renderer2d.h"
#include "src\graphics\renderable2d.h"
#include "src\graphics\simple2drenderer.h"
#include "src\graphics\batchrenderer2d.h"
#include "src\graphics\static_sprite.h"
#include "src\graphics\sprite.h"

using namespace notche;

const int width = 960; //1024
const int height = 540; //768

void check_position(maths::vec3& position, bool& jumped)
{
	//total height - 8.0 total width - 15.0 for cube size (1,1)
	if (position.x < 0.0f) position.x = 0.0f;
	if (position.z < 0.0f) position.z = 0.0f;
	if (position.x > 15.0f) position.x = 15.0f;
	if (position.y > 8.0f) position.y = 8.0f;
	if (position.y >= 2.5f) //necesseary to validate jump
	{
		jumped = true;
	}
	else if (position.y <= 0.0f)
	{
		jumped = false;
		position.y = 0.0f;
	}
}

#define BATCH_RENDERER 1

int main()
{
	graphics::Window window("Notche", width, height);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	maths::mat4 ortho = maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	graphics::Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", maths::mat4::translation(maths::vec3(4, 3, 0)));
	shader.setUniform2f("light_pos", maths::vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", maths::vec4(0.2f, 0.3f, 0.8f, 1.0f));

	std::vector<graphics::Renderable2D*> sprites;

	srand(time(NULL));

	for (float y = 0; y < 9.0f; y += 0.05)
	{
		for (float x = 0; x < 16.0f; x += 0.05)
		{
			sprites.push_back(new
#if BATCH_RENDERER
				graphics::Sprite
#else
				graphics::StaticSprite
#endif
				(x, y, 0.04f, 0.04f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)
#if !BATCH_RENDERER
				, shader
#endif

				));
		}
	}

#if BATCH_RENDERER
	graphics::Sprite sprite(0, 0, 1, 1, maths::vec4(1, 1, 1, 1));
	graphics::BatchRenderer2D renderer;
#else
	graphics::StaticSprite sprite(0, 0, 1, 1, maths::vec4(1, 1, 1, 1), shader);
	graphics::Simple2DRenderer renderer;
#endif

	maths::vec3 sprite_pos(0.0f, 8.0f, 0.0f);
	sprite.setPosition(sprite_pos);
	float speed = 1.0f;
	float y_velocity = 0.0f; // initial y velocity
	float gravity = 0.01f; // do want to fall too fast

	float t = 0.0f;
	float dt = 0.1f;

	float currentTime = 0.0f;
	float accumulator = 0.0f;

	bool jumped = false;


	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", maths::vec2((float) (x * 16.0f / (float) width), (float) (9.0f - y * 9.0f / (float) height)));
		/*
#if BATCH_RENDERER
		renderer.begin();
		#endif
		renderer.submit(&sprite);
		#if BATCH_RENDERER
		renderer.end();
		#endif
		*/

#if BATCH_RENDERER
		renderer.begin();
#endif
		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.submit(sprites[i]);
		}
#if BATCH_RENDERER
		renderer.end();
#endif
		renderer.flush();
		/*
		if (sprite_pos.y > 0.0f) //move to physics method
		{
		// update position
		//sprite_pos.y -= y_velocity;
		//std::cout << sprite_pos.y << std::endl;
		// update velocity and gravity
		y_velocity += gravity;
		if (sprite_pos.y <= 0.0f)y_velocity = 0.0f;
		}
		if (window.isKeyPressed(GLFW_KEY_W))
		{
		//sprite_pos.y += 0.1f * speed;
		check_position(sprite_pos, jumped);
		}
		if (window.isKeyPressed(GLFW_KEY_S))
		{
		//sprite_pos.y -= 0.1f * speed;
		check_position(sprite_pos, jumped);
		}
		if (window.isKeyPressed(GLFW_KEY_A))
		{
		sprite_pos.x -= 0.1f * speed;
		check_position(sprite_pos, jumped);
		}
		if (window.isKeyPressed(GLFW_KEY_D))
		{
		sprite_pos.x += 0.1f * speed;
		check_position(sprite_pos, jumped);
		}
		if (window.isKeyPressed(GLFW_KEY_SPACE))
		{
		if (sprite_pos.y <= 3.0f)
		{
		if (!jumped)
		{//seems to be working
		sprite_pos.y += 0.5f;
		check_position(sprite_pos, jumped);
		}
		}
		}
		if (window.isKeyPressed(GLFW_KEY_LEFT_SHIFT))
		{
		speed = 1.0f;
		}
		else
		{
		speed = 2.0f;
		}
		sprite.setPosition(sprite_pos);
		check_position(sprite_pos, jumped);*/
		window.update();
	}

	system("PAUSE");
	return 0;
}