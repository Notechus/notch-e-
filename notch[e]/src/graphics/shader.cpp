#include "shader.h"
#include <iostream>

namespace notche {
	namespace graphics {

		Shader::Shader(const std::string& vertPath_, const std::string& fragPath_) :vertPath(vertPath_), fragPath(fragPath_) {
			shaderID = load();
		}

		Shader::~Shader() {
			glDeleteProgram(shaderID);
		}

		GLuint Shader::load() {
			GLuint result = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSrc = FileUtils::read_file(vertPath);
			std::string fragSrc = FileUtils::read_file(fragPath);

			//necessary to use glShaderSource
			const char* vertCSrc = vertSrc.c_str();
			const char* fragCSrc = fragSrc.c_str();

			//get vertex shader compiled
			glShaderSource(vertex, 1, &vertCSrc, NULL);
			glCompileShader(vertex);

			GLint res;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &res);
			if (res == GL_FALSE) {
				//GLint length;
				//glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				//glGetShaderInfoLog(vertex, length, &length, error);
				//std::string errorS(error, length);
				std::cout << "Failed to compile vertex shader" << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			//get fragment shader compiled
			glShaderSource(fragment, 1, &fragCSrc, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &res);
			if (res == GL_FALSE) {
				//GLint length;
				//glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				//glGetShaderInfoLog(fragment, length, &length, error);
				//std::string errorS(error, length);
				std::cout << "Failed to compile fragment shader" << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(result, vertex);
			glAttachShader(result, fragment);

			glLinkProgram(result);
			glValidateProgram(result);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return result;
		}

		GLuint Shader::getShaderID() const {
			return shaderID;
		}

		void Shader::enable() const {
			glUseProgram(shaderID);
		}

		void Shader::disable() const {
			glUseProgram(0);
		}

		GLint Shader::getUniformLocation(const GLchar* name) {
			return glGetUniformLocation(shaderID, name);
		}

		void Shader::setUniform1l(const GLchar* name, const float& value) {
			glUniform1f(getUniformLocation(name), value);
		}
		void Shader::setUniform1i(const GLchar* name, const int& value) {
			glUniform1i(getUniformLocation(name), value);
		}
		void Shader::setUniform2f(const GLchar* name, const maths::vec2& vector) {
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}
		void Shader::setUniform3f(const GLchar* name, const maths::vec3& vector) {
			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
		}
		void Shader::setUniform4f(const GLchar* name, const maths::vec4& vector) {
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}
		void Shader::setUniformMat4(const GLchar* name, const maths::mat4& matrix) {
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}
	}
}