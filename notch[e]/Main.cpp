#include <iostream>
#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\maths\maths.h"

using namespace notche;

int main() {

	graphics::Window window("Notche", 960, 540);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	GLfloat vertice[] =
	{
		4, 3, 0,
		12, 6, 0,
		4, 4, 0
	};

	GLfloat vertices[] = {
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	maths::mat4 ortho = maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	graphics::Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", maths::mat4::translation(maths::vec3(4, 3, 0)));
	shader.setUniform2f("light_pos", maths::vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", maths::vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed()) {
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	system("PAUSE");
	return 0;
}