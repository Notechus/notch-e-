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
#include "src\graphics\layers\group.h"

using namespace notche;
using namespace graphics;
using namespace maths;

const int width = 960; //1024
const int height = 540; //768


int main()
{
	graphics::Window window("Notche", width, height);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader* s2 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s;
	Shader& shader2 = *s2;
	shader.enable();
	shader2.enable();

	//shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader2.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	//shader.setUniform4f("colour", maths::vec4(0.2f, 0.3f, 0.8f, 1.0f));

	Sprite sprite(0, 0, 1, 1, vec4(1, 1, 1, 1));
	BatchRenderer2D renderer;
	srand(time(NULL));
	TileLayer layer(&shader);


	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++)
		{
			layer.add(new Sprite(x, y, 0.9f, 0.9f, vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	TileLayer layer2(&shader2);
	layer2.add(&sprite);

	mat4 transform = mat4::translation(vec3(-15.0f, 5.0f, 0.0f));
	Group* group = new Group(transform);
	group->add(new Sprite(0, 0, 6, 3, vec4(1, 1, 1, 1)));

	Group* button = new graphics::Group(mat4::translation(vec3(0.5f, 0.5f, 0.0f)));
	button->add(new Sprite(0.0f, 0.0f, 5.0f, 2.0f, vec4(1, 0, 1, 1)));
	button->add(new Sprite(0.5f, 0.5f, 3.0f, 1.0f, vec4(0.2f, 0.3f, 0.8f, 1)));
	group->add(button);

	layer.add(group);

	vec3 sprite_pos(0.0f, 8.0f, 0.0f);
	sprite.setPosition(sprite_pos);
	float y_velocity = 0.0f; // initial y velocity
	float gravity = 0.01f; // do want to fall too fast
	bool jumped = false;

	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		shader2.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));

		layer.render();
		//layer2.render();

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