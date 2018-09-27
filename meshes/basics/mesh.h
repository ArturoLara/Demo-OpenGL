#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>

/**
* This class contains the common attributes and methods for all meshes
* It could also contain the VBO and other opengl calls for a quad, since it is the same for all meshes (optimization)
*/
class Mesh
{
protected:
	glm::mat4x4 theModel;
	glm::vec2 thePosition;
	glm::vec2 theSize;
	int theLayer;
	int theOriginalLayer;
	int theDepth;
	std::string theType;
	GLuint theShaderId;
	GLuint theTextureId;

public:
	/**
	* @brief Contructor de la clase
	* @param position Vector de 2 componentes (x, y)
	* @param size Vector de 2 componentes (anchura, altura)
	* @param shaderId Objeto openGL con shaders necesarios para su renderizado
	*
	* @param layer Capa en la que se dibujará el objeto
	* @param depth Profundidad del objeto donde será dibujado en la capa especificada (mayor número = menos profundo)
	* @param type String con nombre identificador del objeto
	*/
	Mesh(glm::vec2 position, glm::vec2 size, GLuint shaderId, GLuint textureId, int layer, int depth, std::string type) :
		thePosition(position), theSize(size), theShaderId(shaderId), theTextureId(textureId), theLayer(layer), theDepth(depth), theType(type), theOriginalLayer(layer)
	{
		theModel = glm::translate(theModel, glm::vec3(position, 0.0f));
		theModel = glm::scale(theModel, glm::vec3(size, 0.0f));
	}
	virtual ~Mesh() = default;

	/**
	* @brief Metodo de renderizado del objeto para dibujarlo por pantalla
	*/
	virtual void render() = 0;
	/**
	* @brief Metodo para el evento de clic derecho
	*/
	virtual void singleRigthClick(int mouseX, int mouseY) { ; }
	/**
	* @brief Metodo para el evento de clic izquierdo
	*/
	virtual void singleLeftClick(int mouseX, int mouseY) { ; }
	/**
	* @brief Metodo para el evento de doble clic derecho
	*/
	virtual void dobleRigthClick(int mouseX, int mouseY) { ; }
	/**
	* @brief Metodo para el evento de doble clic izquierdo
	*/
	virtual void dobleLeftClick(int mouseX, int mouseY) { ; }
	/**
	* @brief Metodo para el evento de scroll hacia arriba
	*/
	virtual void scrollUp() { ; }
	/**
	* @brief Metodo para el evento de scroll hacia abajo
	*/
	virtual void scrollDown() { ; }
	/**
	* @brief Metodo para el evento de arrastre con el boton derecho
	*/
	virtual void pullRigthButton(int mouseX, int mouseY) { ; }
	/**
	* @brief Metodo para el evento de arrastre con el boton izquierdo
	*/
	virtual void pullLeftButton(int mouseX, int mouseY) { ; }
	/**
	* @brief Metodo para terminar el evento de arrastre
	*/
	virtual void endPull() { ; };
	/**
	* @brief Metodo para ocultar la simbolog�a por pantalla
	*/
	void hide(){
		this->theLayer = 0;
	}
	/**
	* @brief Metodo para mostrar la simbolog�a por pantalla
	*/
	void show(){
		this->theLayer = this->theOriginalLayer;
	}
	/**
	* @brief Actualiza el id de la textura del objeto
	* @param textureId nuevo id de la textura del objeto
	*/
	void setTextureId(GLuint textureId) { theTextureId = textureId; }
	/**
	* @brief Actualiza la capa en la que se encuentra el objeto
	* @param layer entero con el nuevo valor para la capa donde ser� renderizado
	*/
	inline void setLayer(int layer){ theLayer = layer; }
	/**
	* @brief Obtiene el modelo del objeto
	* @return glm::mat4 modelo del objeto
	*/
	inline glm::mat4 getModel() const { return theModel; }
	/**
	* @brief Obtiene la posici�n del objeto
	* @return glm::vec2 vector de 2 componentes con la posici�n del objeto (x, y)
	*/
	inline glm::vec2 getPosition() const { return thePosition; }
	/**
	* @brief Obtiene el tama�o del objeto
	* @return glm::vec2 vector de 2 componentes con el tama�o del objeto (altura, anchura)
	*/
	inline glm::vec2 getSize() const { return theSize; }
	/**
	* @brief Obtiene el id del Shader
	* @return GLuint id del Shader que lo forma
	*/
	inline GLuint getShaderId() const { return theShaderId; }
	/**
	* @brief Obtiene el id de la textura
	* @return GLuint id de la textura que lo forma
	*/
	inline GLuint getTextureId() const { return theTextureId; }
	/**
	* @brief Obtiene la capa donde se renderiza el objeto
	* @return int entero con la capa donde se renderiza el objeto
	*/
	inline int getLayer(){ return theLayer; }
	/**
	* @brief Obtiene la profundidad del elemento en la capa
	* @return int entero con la profundidad del elemento en la capa
	*/
	inline int getDepth() const { return theDepth; }
	/**
	* @brief Obtiene el tipo del objeto
	* @return std::string String con el tipo de objeto
	*/
	inline std::string getType() const { return theType; }

	/**
	* @brief Reconstruye la matriz del modelo
	* @param position Vector de 2 componentes (x, y)
	* @param size Vector con 2 componentes (anchura, altura)
	*/
	void changeModelMatrix(glm::vec2 position, glm::vec2 size)
	{
		thePosition = position;
		theSize = size;

		glm::mat4 model;
		model = glm::translate(model, glm::vec3(position, 0.0f));
		theModel = glm::scale(model, glm::vec3(size, 1.0f));
	}

	/**
	* @brief Método para rotar el objeto hasta el alngulo dado
	* @param angle Float con el número del grado de rotación donde se desea situal el objeto
	* @param x Float que aplica el angulo en el eje x en el porcentaje (1.0 == 100%)
	* @param y Float que aplica el angulo en el eje y en el porcentaje (1.0 == 100%)
	* @param z Float que aplica el angulo en el eje z en el porcentaje (1.0 == 100%)
	*/
	void rotate(float angle, float x,  float y,  float z)
	{
		glm::mat4 model;

		model = glm::translate(model, glm::vec3(thePosition[0], thePosition[1], 0.0f));
		model = glm::rotate(model, (float)angle, glm::vec3((float)x, (float)y, (float)z));
		theModel = glm::scale(model, glm::vec3(theSize, 1.0f));
	}
	/**
	* @brief Metodo para obtener un vector que define el area del elemento
	* @return glm::vec4 Vector con 4 componentes para definir el area del elemento, (xTopLeft, yTopLeft, xBottomRigth, yBottomRigth)
	*/
	inline glm::vec4 getArea()
	{
		int xBottomRigth;
		int xTopLeft;
		int yBottomRigth;
		int yTopLeft;
		int tempX = thePosition[0]+theSize[0];
		int tempY = thePosition[1]+theSize[1];
		if(thePosition[0] < tempX)
		{
			xBottomRigth = tempX;
			xTopLeft = thePosition[0];
		}
		else
		{
			xBottomRigth = thePosition[0];
			xTopLeft = tempX;
		}
		if(thePosition[1] < tempY)
		{
			yBottomRigth = tempY;
			yTopLeft = thePosition[1];
		}
		else
		{
			yBottomRigth = thePosition[1];
			yTopLeft = tempY;
		}
		return glm::vec4(xTopLeft, yTopLeft, xBottomRigth, yBottomRigth);
	}
};
