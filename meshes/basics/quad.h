#pragma once

#include "mesh.h"

#include <glad/glad.h>
#include "../../graphics/shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

/**
* Clase que crea un objeto geométrico básico, un cuadrado
*
*/
class Quad : public Mesh
{
private:
	GLuint theVao;
	glm::vec4 theColor;
public:
	/**
	* @brief Contructor de la clase
	* @param position Vector de 2 componentes (x, y)
	* @param size Vector de 2 componentes (anchura, altura)
	* @param color Vector de 4 componentes (RGBA)
	* @param shaderId Objeto openGL con shaders necesarios para su renderizado
	* @param layer Capa en la que se dibujará el objeto
	* @param depth Profundidad del objeto donde será dibujado en la capa especificada (mayor número = menos profundo)
	* @param type String con nombre identificador del objeto
	*/
	Quad(glm::vec2 position, glm::vec2 size, glm::vec4 color, GLuint shaderId,int layer = 0, int depth = 0, std::string type = "none");
	~Quad();
	/**
	* @brief Metodo para obtener el color del borde
	* @return vector vector de 4 componentes con el color del borde (RGBA)
	*/
	inline glm::vec4 getColor() const { return theColor; }
	/**
	* @brief Metodo para actualizar el color del borde
	* @param color vector de 4 componentes con el nuevo color del borde (RGBA)
	*/
	inline void setColor(glm::vec4 color) { theColor = glm::vec4(color); }
	/**
	* @brief Metodo de renderizado del objeto para dibujarlo por pantalla
	*/
	void render();
	/**
	* @brief Metodo para ocultar la simbolog�a por pantalla
	*/
	void hide();
	/**
	* @brief Metodo para mostrar la simbolog�a por pantalla
	*/
	void show();
};
