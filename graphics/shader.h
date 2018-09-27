#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace gfx
{
/**
 * Clase para cambiar los parámetros y estados de openGL referente a los Shaders
 */
class Shader
{
private:
    GLuint theProgramId = 0;

public:
    /**
	* @brief Contructor de la clase
	* @param shaderName String con el nombre del archivo "shader" que gestionará este objeto
	*/
    Shader(const std::string &shaderName);
    ~Shader();

    /**
     * @brief Obtiene el id del programa
     * @return m_programId
     */
    inline GLuint getId() const { return theProgramId; }

    /**
	 * @brief Activa el programa especificado
	 * @param programId Id del programa a activar
	 */
    static void enable(GLuint programId);
    /**
	 * @brief Desactiva el programa especificado
	 * @param programId Id del programa a desactivar
	 */
    static void disable(GLuint programId);
    /**
	 * @brief Método para establecer un valor boolean para usar en el shader
	 * @param programId Id del programa donde se establecerá la variable
	 * @param name nombre que tomará la variable en el shader
	 * @param value valor a asignar
	 */
    static void setBool(GLuint programId, const char* name, bool value);
    /**
	 * @brief Método para establecer un valor int para usar en el shader
	 * @param programId Id del programa donde se establecerá la variable
	 * @param name nombre que tomará la variable en el shader
	 * @param value valor a asignar
	 */
    static void setInt(GLuint programId, const char* name, int value);
    /**
	 * @brief Método para establecer un valor float para usar en el shader
	 * @param programId Id del programa donde se establecerá la variable
	 * @param name nombre que tomará la variable en el shader
	 * @param value valor a asignar
	 */
    static void setFloat(GLuint programId, const char* name, float value);
    /**
	 * @brief Método para establecer un vector con 2 componentes para usar en el shader
	 * @param programId Id del programa donde se establecerá la variable
	 * @param name nombre que tomará la variable en el shader
	 * @param value valor a asignar
	 */
    static void setVector2(GLuint programId, const char* name, const glm::vec2 &vec);
    /**
	 * @brief Método para establecer un vector con 3 componentes para usar en el shader
	 * @param programId Id del programa donde se establecerá la variable
	 * @param name nombre que tomará la variable en el shader
	 * @param value valor a asignar
	 */
    static void setVector3(GLuint programId, const char* name, const glm::vec3 &vec);
    /**
	 * @brief Método para establecer un vector con 4 componentes para usar en el shader
	 * @param programId Id del programa donde se establecerá la variable
	 * @param name nombre que tomará la variable en el shader
	 * @param value valor a asignar
	 */
    static void setVector4(GLuint programId, const char* name, const glm::vec4 &vec);
    /**
	 * @brief Método para establecer una matriz de 4 dimensiones para usar en el shader
	 * @param programId Id del programa donde se establecerá la variable
	 * @param name nombre que tomará la variable en el shader
	 * @param value valor a asignar
	 */
    static void setMatrix4(GLuint programId, const char* name, const glm::mat4 &mat);

private:

    /**
	 * @brief Método para compilar el shader especificado
	 * @param shader dirección de memoria donde se almacenará el shader creado
	 * @param shaderType Tipo de shader a crear por openGL
	 * @param shaderCode puntero al código a compilar
	 */
    void compileShader(GLuint &shader, GLenum shaderType, const char *shaderCode);
    /**
	 * @brief Método para imprimir por consola los errores del shader en la compilación (si los tiene)
	 * @param shader Id del shader del que se desea imprimir sus errores
	 */
    void printShaderErrors(GLuint shader) const;
    /**
	 * @brief Método para imprimir por consola los errores del programa en la compilación (si los tiene)
	 * @param program Id del programa del que se desea imprimir sus errores
	 */
    void printProgramErrors(GLuint program) const;
};

} // namespace gfx
