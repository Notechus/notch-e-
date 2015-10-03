#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <time.h>

#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\maths\maths.h"

#include "src\graphics\simple2drenderer.h"
#include "src\graphics\batchrenderer2d.h"
#include "src\graphics\static_sprite.h"
#include "src\graphics\sprite.h"
#include "src\utils\timer.h"

#include "src\graphics\layers\tilelayer.h"

using namespace notche;

const int width = 960; //1024
const int height = 540; //768

#define BATCH_RENDERER 1

int main()
{
	graphics::Window window("Notche", width, height);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	maths::mat4 ortho = maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	graphics::Shader* s = new graphics::Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	graphics::Shader* s2 = new graphics::Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	graphics::Shader& shader = *s;
	graphics::Shader& shader2 = *s2;
	shader.enable();
	shader2.enable();

	//shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniform2f("light_pos", maths::vec2(4.0f, 1.5f));
	shader2.setUniform2f("light_pos", maths::vec2(4.0f, 1.5f));
	//shader.setUniform4f("colour", maths::vec4(0.2f, 0.3f, 0.8f, 1.0f));

	graphics::Sprite sprite(0, 0, 1, 1, maths::vec4(1, 1, 1, 1));
	//graphics::BatchRenderer2D renderer;
	srand(time(NULL));
	graphics::TileLayer layer(&shader);
	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			layer.add(new graphics::Sprite(x, y, 0.09f, 0.09f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	graphics::TileLayer layer2(&shader2);
	layer2.add(&sprite);
	maths::vec3 sprite_pos(0.0f, 8.0f, 0.0f);
	sprite.setPosition(sprite_pos);
	float y_velocity = 0.0f; // initial y velocity
	float gravity = 0.01f; // do want to fall too fast
	bool jumped = false;

	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		//maths::mat4 mat = maths::mat4::translation(maths::vec3(5, 5, 5));
		//mat = mat * maths::mat4::rotation(time.elapsed() * 50.0f, maths::vec3(0, 0, 1));
		//mat = mat * maths::mat4::translation(maths::vec3(-5, -5, -5));
		//shader.setUniformMat4("ml_matrix", mat);
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", maths::vec2((float) (x * 32.0f / 960.0f - 16.0f), (float) (9.0f - y * 18.0f / 540.0f)));
		shader2.setUniform2f("light_pos", maths::vec2((float) (x * 32.0f / 960.0f - 16.0f), (float) (9.0f - y * 18.0f / 540.0f)));
		layer.render();
		layer2.render();
		/*
		renderer.begin();
		renderer.submit(&sprite);
		renderer.end();
		renderer.flush();
		*/
		window.input(sprite_pos, jumped, gravity, y_velocity);
		sprite.setPosition(sprite_pos);
		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			std::cout << "FPS: " << frames << std::endl;
			frames = 0;
		}
	}
	delete s;
	delete s2;

	system("PAUSE");
	return 0;
}