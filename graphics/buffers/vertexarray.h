/**
* (c) 2017 Pablo Luis Garc�a. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <glad/glad.h>

namespace gfx
{
/**
 * Clase para gestionar "Vertex Array Object" con openGL
 */
class VertexArray
{
private:

    GLuint m_vaoId;

public:
    /**
     * @brief crea un nuevo vao
     */
    VertexArray();
    ~VertexArray();

    /**
     * @brief enlaza el vao en openGL
     */
    void bind() const;
    /**
     * @brief desenlaza el vao en openGL
     */
    void unbind() const;
};

} // namespace gfx
