/*
 * triangle.cpp
 *
 *  Created on: 17 jul. 2018
 *      Author: arturo
 */

#include "triangle.h"

triangle::triangle(glm::vec2 position, glm::vec2 size, glm::vec4 color, GLuint shaderId, int layer, int depth, std::string type) :
	Mesh(position, size, shaderId, 0, layer, depth, type), theColor(color)
{
	 GLfloat vertices[6] =
	 {
			0.0f, 0.0f,
			1.0f, 1.0f,
			-1.0f, 1.0f
	 };

	GLubyte indices[3] =
	{
		0, 1, 2
	};

	// Bind vao
	glGenVertexArrays(1, &theVao);
	glBindVertexArray(theVao);

	// Setup vertices
	GLuint verticesVbo;
	glGenBuffers(1, &verticesVbo);
	glBindBuffer(GL_ARRAY_BUFFER, verticesVbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

	// Setup vertices in shader
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	// Setup indices
	GLuint indicesEbo;
	glGenBuffers(1, &indicesEbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesEbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(GLubyte), indices, GL_STATIC_DRAW);

	// Unbind vao
	glBindVertexArray(0);

	// Delete unnecessary buffers (not actually deleted until the vao they are in is deleted)
	glDeleteBuffers(1, &verticesVbo);
}

triangle::~triangle()
{
	glDeleteVertexArrays(1, &theVao);
}

void triangle::render()
{
	gfx::Shader::setVector4(theShaderId, "color", theColor);
	gfx::Shader::setMatrix4(theShaderId, "model", theModel);

	glBindVertexArray(theVao);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, 0);
	glBindVertexArray(0);
}

