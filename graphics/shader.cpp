/*
 * shader.cpp
 *
 *  Created on: 7 dic. 2017
 *      Author: extplgarcia
 */

#include "shader.h"

#include <iostream>

#include "../utils/fileutils.h"

#include <glm/gtc/type_ptr.hpp>

namespace gfx
{

	Shader::Shader(const std::string &shaderName)
	{
		// Compile shaders
		GLuint vertex, fragment;

		compileShader(vertex, GL_VERTEX_SHADER, utils::readFileString("shaders/" + shaderName + ".vs").c_str());
		compileShader(fragment, GL_FRAGMENT_SHADER, utils::readFileString("shaders/" + shaderName + ".fs").c_str());

		theProgramId = glCreateProgram();
		glAttachShader(theProgramId, vertex);
		glAttachShader(theProgramId, fragment);
		glLinkProgram(theProgramId);

		// Print errors if any
		printProgramErrors(theProgramId);

		// Delete unnecessary shaders (we have program)
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	Shader::~Shader()
	{
		glDeleteProgram(theProgramId);
	}

	void Shader::compileShader(GLuint &shader, GLenum shaderType, const char *shaderCode)
	{
		shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &shaderCode, NULL);
		glCompileShader(shader);

		// Print compile errors if any
		printShaderErrors(shader);
	}

	void Shader::printShaderErrors(GLuint shader) const
	{
		GLint success;
		char compileLog[512];

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, compileLog);
			std::cout << "Error in shader compilation\n" << compileLog << std::endl;
		}
	}

	void Shader::printProgramErrors(GLuint program) const
	{
		GLint success;
		char linkLog[512];

		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program, 512, NULL, linkLog);
			std::cout << "Error in shader compilation\n" << linkLog << std::endl;
		}
	}

	void Shader::enable(GLuint programId)
	{
		glUseProgram(programId);
	}

	void Shader::disable(GLuint programId)
	{
		glUseProgram(0);
	}

	void Shader::setBool(GLuint programId, const char* name, bool value)
	{
		glUniform1i(glGetUniformLocation(programId, name), (int)value);
	}

	void Shader::setInt(GLuint programId, const char* name, int value)
	{
		glUniform1i(glGetUniformLocation(programId, name), value);
	}

	void Shader::setFloat(GLuint programId, const char* name, float value)
	{
		glUniform1f(glGetUniformLocation(programId, name), value);
	}

	void Shader::setVector2(GLuint programId, const char* name, const glm::vec2 &vec)
	{
		glUniform2f(glGetUniformLocation(programId, name), vec.x, vec.y);
	}

	void Shader::setVector3(GLuint programId, const char* name, const glm::vec3 &vec)
	{
		glUniform3f(glGetUniformLocation(programId, name), vec.x, vec.y, vec.z);
	}

	void Shader::setVector4(GLuint programId, const char* name, const glm::vec4 &vec)
	{
		glUniform4f(glGetUniformLocation(programId, name), vec.x, vec.y, vec.z, vec.w);
	}

	void Shader::setMatrix4(GLuint programId, const char* name, const glm::mat4 &mat)
	{
		glUniformMatrix4fv(glGetUniformLocation(programId, name), 1, GL_FALSE, glm::value_ptr(mat));
	}

} // namespace gfx
