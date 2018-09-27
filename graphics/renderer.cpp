/*
 * renderer.cpp
 *
 *  Created on: 10 ene. 2018
 *      Author: extplgarcia
 */

#include "renderer.h"

#include "glm/gtc/matrix_transform.hpp"

#include <algorithm>

namespace gfx
{

	Renderer::Renderer()
	{
		theProjection = glm::ortho(0.0f, utils::baseWindowWidth, utils::baseWindowHeight, 0.0f, -1.0f, 1.0f);

		aSyncTimer.start();
	}

	Renderer::~Renderer()
	{
		for (auto &shader : theShaders)
		{
			delete shader.second;
		}
	}

	void Renderer::update()
	{
		// Sync video framarate (every 50 frames takes one image of the video)
		if (aSyncTimer.getTicks() / 1000.0 > 1000.0 / 50.0)
		{
			aSyncTimer.start();
		}
	}

	void Renderer::render()
	{
		// Sort vector by shader and by texture to optimize the rendering of OpenGL (less binds is better) BUT this make and expecific order to render so you can't manage layers
		std::sort(theRenderQueue.begin(), theRenderQueue.end(), compareMeshes);

		GLuint lastShader = 0;
		GLuint lastTexture = 0;

		for (unsigned i = 0; i < theRenderQueue.size(); i++)
		{
			if (theRenderQueue[i]->getShaderId() != lastShader)
			{
				// Bind the shader for the following meshes to render
				gfx::Shader::enable(theRenderQueue[i]->getShaderId());

				// Upload projection matrix uniform to shader (common for all meshes)
				gfx::Shader::setMatrix4(theRenderQueue[i]->getShaderId(), "projection", theProjection);
				lastShader = theRenderQueue[i]->getShaderId();
			}

			if (theRenderQueue[i]->getTextureId() != 0 && theRenderQueue[i]->getTextureId() != lastTexture)
			{
				// Bin the texture for the following meshes to render
				glBindTexture(GL_TEXTURE_2D, theRenderQueue[i]->getTextureId());
				lastTexture = theRenderQueue[i]->getTextureId();
			}
			// Use the render function for each mesh
			theRenderQueue[i]->render();
		}

		theRenderQueue.clear();

	}

	void Renderer::addToRenderQueue(Mesh *mesh)
	{
		theRenderQueue.push_back(mesh);
	}

	GLuint Renderer::getShader(const std::string &shaderName)
	{
		if (!theShaders.count(shaderName))
		{
			theShaders[shaderName] = new Shader(shaderName);
		}

		return theShaders[shaderName]->getId();
	}

} // namespace gfx
