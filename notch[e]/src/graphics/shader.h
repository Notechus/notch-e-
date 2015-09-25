#pragma once
#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <GL/glew.h>
#include "../utils/fileutils.h"
#include <string>
#include "../maths/maths.h"

namespace notche
{
	namespace graphics
	{

		class Shader
		{
		private:
			GLuint shaderID;
			std::string vertPath, fragPath;
		public:
			Shader(const std::string& vertPath_, const std::string& fragPath_);
			~Shader();
			GLuint load();
			GLuint getShaderID() const;
			void enable() const;
			void disable() const;
			GLint getUniformLocation(const GLchar* name);

			void setUniform1l(const GLchar* name, const float& value);
			void setUniform1i(const GLchar* name, const int& value);
			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);
			void setUniformMat4(const GLchar* name, const maths::mat4& matrix);
		};
	}
}

#endif