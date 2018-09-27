#pragma once

#include <glad/glad.h>

namespace gfx
{
/**
 * Clase para gestionar "Vertex Buffer Object" con openGL
 */
class VertexBuffer
{
private:
    GLuint m_vboId;

public:
    /**
     * @brief crea un nuevo vbo
     * @param data puntero a los datos
     * @param size tamaño de los datos
     * @param drawType tipo de dibujado en openGL
     */
    VertexBuffer(GLvoid *data, GLsizei size, GLenum drawType = GL_STATIC_DRAW);
    VertexBuffer();
    ~VertexBuffer();

    /**
     * @brief obtiene el Id del vbo
     * @return vboId Id del vbo
     */
    inline GLuint getId() const { return m_vboId; };

    /**
     * @brief enlaza el vbo en openGL
     */
    void bind() const;
    /**
     * @brief desenlaza el vbo en openGL
     */
    void unbind() const;
    /**
     * @brief establece unos nuevos datos para el buffer
     * @param data puntero a los datos
     * @param size tamaño de los datos
     * @param drawType tipo de dibujado en openGL
     */
	void setData(GLvoid* data, GLsizei size, GLenum drawType = GL_STATIC_DRAW);
    /**
     * @brief acutaliza los datos para el buffer
     * @param data puntero a los datos
     * @param size tamaño de los datos
     */
	void updateData(GLvoid* data, GLsizei size);
};

} // namespace gfx
