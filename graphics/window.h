#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/vec2.hpp>

namespace gfx
{

void windowResize(GLFWwindow *window, int width, int height);
void ErrorCallback(int, const char* err_str);

/**
 * Crea una ventana para la aplicación
 */
class Window
{
private:

    int theWidth;
    int theHeight;
    bool aFullscreen;
    GLFWwindow* aWindow;

public:
    /**
     * @brief Inicializa paramentros internos
     */
    Window();
    ~Window();

    /**
     * @brief Crea una ventana
     * @param screenTitle String titulo de la ventana
     * @param window_width anchura en pixeles de la ventana
     * @param window_height altura en pixeles de la ventana
     * @param isFullscreen boolean true si se crea en pantalla completa
     * @return boolean true si se ha creado correctamente la ventana
     */
    bool init(const std::string &screenTitle, int window_width, int window_height, bool isFullscreen = false);


    /**
     * @brief Obtiene la anchura de la ventana
     * @return width anchura de la ventana en pixeles
     */
    inline int getWidth() const { return theWidth; }
    /**
     * @brief Obtiene la altura de la ventana
     * @return height altura de la ventana en pixeles
     */
    inline int getHeight() const { return theWidth; }
    /**
     * @brief Obtiene la ventana openGL
     * @return windows GLFWwindow, la ventana openGL
     */
    GLFWwindow* getGlfwWindow() { return aWindow; }
    /**
     * @brief Identifica si la ventana está cerrada
     * @return boolean true si está cerrada
     */
    bool isClosed() const;
    /**
	 * @brief Identifica si la ventana está en pantalla completa
	 * @return boolean true si está en pantalla completa
	 */
    inline bool isFullscreen() const { return aFullscreen; }
    /**
	 * @brief Establece el tamaño de la ventana
	 * @param width anchura de la ventana
	 * @param height altura de la ventana
	 */
    void setSize(int width, int height);
    /**
	 * @brief Establece el color ya normalizado
	 * @param r grado de rojo en el color RGB (0.0 a 1.0)
	 * @param g grado de verde en el color RGB (0.0 a 1.0)
	 * @param b grado de azul en el color RGB (0.0 a 1.0)
	 */
    void setClearColorNormalized(float r, float g, float b);
    /**
	 * @brief Establece el color en RGB
	 * @param r grado de rojo en el color RGB
	 * @param g grado de verde en el color RGB
	 * @param b grado de azul en el color RGB
	 */
    void setClearColor(int r, int g, int b);
    /**
     * @brief Establece el viewPort en openGL la posición y tamaño de la ventana
     */
    void setViewport();
    /**
     * @brief Eventos de teclado o ratón
     */
    void pollEvents();
    /**
     * @brief Intercambia los buffer de openGL (visto y pintado)
     */
    void swap();
    /**
     * @brief Limpia el buffer de openGL
     */
    void clear() const;
};

} // namespace gfx
