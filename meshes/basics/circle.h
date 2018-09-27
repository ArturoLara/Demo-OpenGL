#ifndef MESHES_CIRCLE_H_
#define MESHES_CIRCLE_H_

#include "mesh.h"

#include <glad/glad.h>
#include "../../graphics/shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

/**
* Clase que crea un objeto geométrico básico, un circulo
*
*/
class circle : public Mesh{
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
	circle(glm::vec2 position, glm::vec2 size, glm::vec4 color, GLuint shaderId,int layer, int depth, std::string type);
	~circle();

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

#endif /* MESHES_CIRCLE_H_ */
