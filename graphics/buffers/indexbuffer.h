#pragma once

#include <glad/glad.h>

namespace gfx
{
/**
 * Clase para gestionar un buffer de indices con openGL
 */
class IndexBuffer
{
private:

	GLuint m_eboId;
	GLsizei m_size;

public:
    /**
     * @brief crea un nuevo buffer
     * @param data puntero a los datos
     * @param size tamaño de los datos
     */
	IndexBuffer(GLubyte *data, GLsizei size);
	~IndexBuffer();

    /**
     * @brief enlaza el buffer en openGL
     */
	void bind() const;
    /**
     * @brief desenlaza el buffer en openGL
     */
	void unbind() const;
};

} // namespace gfx
