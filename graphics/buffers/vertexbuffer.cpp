/**
* (c) 2017 Pablo Luis Garc�a. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "vertexbuffer.h"

namespace gfx
{

VertexBuffer::VertexBuffer(GLvoid *data, GLsizei size, GLenum drawType)
{
    glGenBuffers(1, &m_vboId);
    setData(data, size, drawType);
}

VertexBuffer::VertexBuffer()
{
    glGenBuffers(1, &m_vboId);
}

void VertexBuffer::setData(GLvoid *data, GLsizei size, GLenum drawType)
{
	bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, drawType);
    unbind();
}

void VertexBuffer::updateData(GLvoid *data, GLsizei size)
{
    bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    unbind();
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_vboId);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

} // namespace gfx
