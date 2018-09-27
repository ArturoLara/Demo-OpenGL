#pragma once

#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

//#include "ShareInfoClasses/DemorasListController.h"

#include "graphics/window.h"
#include "graphics/shader.h"

#include "graphics/renderer.h"

#include "utils/windowutils.h"

#include "meshes/basics/quad.h"
#include "meshes/basics/triangle.h"
#include "meshes/basics/circle.h"

#include "meshes/basics/mesh.h"

#include "meshes/basics/circle.h"
#include "gui/imgui.h"
#include "gui/imgui_impl_glfw_gl3.h"
#include <glm/glm.hpp>

#include <fstream> //take screenshot

#define NUM_LAYERS 3
/**
 * Crea todos los elementos a renderizar y los gestiona
 */
class Application
{
private:
	// Vector of renders 1 per layer
	std::vector<gfx::Renderer*> aRenderers;

	gfx::Window &aWindow;

	std::map<unsigned, Mesh *> aMeshes;

    // Current state of the keyboard and mouse
    static bool theKeys[GLFW_KEY_LAST];
    static bool theMouseButtons[GLFW_MOUSE_BUTTON_LAST];
    static glm::vec2 theMousePos;

    std::vector<std::uint8_t> theData[100*100*4];

	bool aClosed;

	bool theRightMouseButtonLock = false;
	bool theLeftMouseButtonLock = false;

	//DemorasListController* aTraceListInfo;
	//---------TEST ZONE-----------
	float test = 0.0;
	//---------------------------------
public:
	/**
	* @brief Contructor de la clase
	* @param window ventana donde se renderizarán los elementos
	*/
	Application(gfx::Window &window);
	~Application();

	/**
	* @brief Carga todas las malals y su distribución en la pantalla desde un xml (config.xml)
	*/
	void loadMeshes();
	/**
	* @brief Establece la posición y el tamaño de la selección actual
	* @param id id de la malla
	* @param position Vector de 2 componentes (x, y) nueva posición
	* @param size Vector de 2 componentes (anchura, altura) nuevo tamaño
	*/
	void setSelectionBorder(unsigned id, glm::vec2 position, glm::vec2 size);
	/**
	* @brief Función usada por openGL para comunicar los estados del teclado
	* @param key codigo de la tecla
	* @param action acción que se ha realizado con esa tecla
	*/
	static void onKeyChange(GLFWwindow* window, int key, int scancode, int action, int mods);
	/**
	* @brief Función usada por openGL para comunicar los estados de los botones del ratón
	* @param button codigo del botón
	* @param action acción que se ha realizado con esa tecla
	*/
	static void onMouseChange(GLFWwindow* window, int button, int action, int mods);
	/**
	* @brief Función usada por openGL para comunicar la posición del ratón
	* @param mx posición en x
	* @param my posición en y
	*/
	static void onMouseMove(GLFWwindow* window, double mx, double my);
	/**
	 * Actualiza el estado actual
	 */
	void update();
	/**
	 * Renderiza el estado actual
	 */
	void render();
    /**
     * @brief Identifica si la ventana está cerrada
     * @return boolean true si está cerrada
     */
	inline bool isClosed() const { return aClosed; }
};
