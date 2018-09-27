#pragma once

#include <vector>
#include <map>

#include "buffers/vertexarray.h"
#include "buffers/vertexbuffer.h"
#include "buffers/indexbuffer.h"
#include "shader.h"

#include "../utils/timer.h"
#include "../utils/windowutils.h"

#include "../meshes/basics/mesh.h"

#include <glad/glad.h>

#include <glm/glm.hpp>

namespace gfx
{
/**
* This class is responsible of handling all the shaders and textures in the application
* Uses a map of textures and a map of shaders to store a single instance of each asset
* It has a render queue that contains what is going to be renderered per frame (filled and cleaned per frame)
*/
class Renderer
{
	glm::mat4 theProjection;
	utils::Timer aSyncTimer;
	std::vector<Mesh*> theRenderQueue;
	std::map<std::string, Shader*> theShaders;

public:
	/**
	* @brief Contructor de la clase
	*/
	Renderer();
	~Renderer();

	/**
	* @brief Método para iniciar el proceso de dibujado de todos los objetos Mesh almacenados
	*/
	void render();
	/**
	* @brief Sincroniza la frecuencia de frames del video con la aplicación
	*/
	void update();
	/**
	* @brief Añade un Mesh a la cola de renderizado
	* @param mesh Objeto de tipo Mesh que se desea renderizar
	*/
	void addToRenderQueue(Mesh *mesh);
	/**
	* @brief Método para obtener el shader especificado
	* @param shaderName String del nombre del shader deseado
	* @return GLuint con el id del shader solicitado
	*/
	GLuint getShader(const std::string &shaderName);
	/**
	* @brief Método para obtener las texturas especificadas
	* @param textureName String del nombre de la textura deseada
	* @return GLuint con el id de la textura solicitada
	*/
	GLuint getTexture(const std::string &textureName);

private:
	/**
	* @brief Método para comparar dos Objetos Mesh por su profundidad en la capa
	* @param mesh1 Primer Mesh a se comparado
	* @param mesh2 Segundo Mesh a se comparado
	* @return boolean true si 1 < 2
	*/
    static bool compareMeshes(const Mesh* mesh1, const Mesh* mesh2)
    {
        return (mesh1->getDepth() < mesh2->getDepth());
    }
};

} // namespace gfx
