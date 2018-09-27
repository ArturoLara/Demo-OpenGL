/*
 * PruebaGLES.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: tecnobit
 */

#include "graphics/window.h"
#include "application.h"

int main(int argc, char* argv[])
{
	gfx::Window window;
	window.init("demoAMD", utils::windowWidth, utils::windowHeight, true);
	// Set clear color to black
	window.setClearColorNormalized(0.0, 0.0, 0.0);

	Application app(window);

	// Main loop
	while(!app.isClosed())
	{
		// Clear the back buffer
		window.clear();

		// Update application state
		app.update();

		// Render to back buffer
		app.render();

		// Swap buffers
		window.swap();
	}
}
