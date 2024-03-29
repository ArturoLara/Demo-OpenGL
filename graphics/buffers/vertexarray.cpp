/**
* (c) 2017 Pablo Luis Garc�a. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "vertexarray.h"

namespace gfx
{

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_vaoId);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_vaoId);
}

void VertexArray::bind() const
{
    glBindVertexArray(m_vaoId);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}

} // namespace gfx
