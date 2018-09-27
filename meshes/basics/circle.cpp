/*
 * circle.cpp
 *
 *  Created on: 17 jul. 2018
 *      Author: arturo
 */

#include "circle.h"

circle::circle(glm::vec2 position, glm::vec2 size, glm::vec4 color, GLuint shaderId,int layer, int depth, std::string type) :
Mesh(position, size, shaderId, 0, layer, depth, type), theColor(color)
{
	GLfloat vertices[200];
	GLubyte indices[200];
	float j;
	for(int i = 0, j = 0.0; j < 100; i+=2, j+=1)
	{
		vertices[i] = cos((j*360/99)*3.141592654 / 180);
		vertices[i+1] = sin((j*360/99)*3.141592654 / 180);
		indices[i] = j;
		indices[i+1] = j+1;
	}
	indices[199] = 0;

	// Bind vao
	glGenVertexArrays(1, &theVao);
	glBindVertexArray(theVao);

	// Setup vertices
	GLuint verticesVbo;
	glGenBuffers(1, &verticesVbo);
	glBindBuffer(GL_ARRAY_BUFFER, verticesVbo);
	glBufferData(GL_ARRAY_BUFFER, 200 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

	// Setup vertices in shader
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	// Setup indices
	GLuint indicesEbo;
	glGenBuffers(1, &indicesEbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesEbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 200 * sizeof(GLubyte), indices, GL_STATIC_DRAW);

	// Unbind vao
	glBindVertexArray(0);

	// Delete unnecessary buffers (not actually deleted until the vao they are in is deleted)
	glDeleteBuffers(1, &verticesVbo);
	glDeleteBuffers(1, &indicesEbo);
}

circle::~circle()
{
	glDeleteVertexArrays(1, &theVao);
}

void circle::render()
{
	gfx::Shader::setVector4(theShaderId, "color", theColor);
	gfx::Shader::setMatrix4(theShaderId, "model", theModel);

	glBindVertexArray(theVao);
	glDrawElements(GL_LINES, 200, GL_UNSIGNED_BYTE, 0);
	glBindVertexArray(0);
}


