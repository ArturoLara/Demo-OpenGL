#include "application.h"

#include <iostream>
#include <GLFW/glfw3.h>

#include "utils/mathutils.h"
#include "glm/gtc/matrix_transform.hpp"

#include "utils/pugixml.hpp"

bool Application::theKeys[GLFW_KEY_LAST];
bool Application::theMouseButtons[GLFW_MOUSE_BUTTON_LAST];
glm::vec2 Application::theMousePos;

Application::Application(gfx::Window &window) : aWindow(window)
{
    ImGui_ImplGlfwGL3_Init(aWindow.getGlfwWindow(), false);

    aClosed = false;
    for(int i = 0; i < NUM_LAYERS; i++)
    {
    	aRenderers.push_back(new gfx::Renderer());
    }

    // Loads all the meshes (set of vertices) from a xml
	loadMeshes();

    // Set Imgui global style
    ImGui::StyleColorsDark();
    ImGuiStyle &style = ImGui::GetStyle();
	style.WindowRounding = 0;
	style.FrameRounding = 0;
	style.FramePadding.y = 1;
	style.ScrollbarRounding = 0;
	style.GrabRounding = 0;

	// Setup the glfw callbacks
	glfwSetKeyCallback(aWindow.getGlfwWindow(), onKeyChange);
	glfwSetMouseButtonCallback(aWindow.getGlfwWindow(), onMouseChange);
	glfwSetCursorPosCallback(aWindow.getGlfwWindow(), onMouseMove);
}

Application::~Application()
{
	for (auto &mesh : aMeshes)
	{
		delete mesh.second;
	}
}

void Application::loadMeshes()
{
    glm::vec4 colors[] =
    {
		{0.91, 0.88, 0.07, 1.0}, // Yellow
		{0.27, 0.76, 0.3, 1.0}, // Green
		{0.92, 0.44, 0.06, 1.0}, // Orange
		{0.91, 0.14, 0.47, 1.0}, // Purple
		{1.0, 0.0, 0.0, 1.0}, // Red
		{0.0, 1.0, 0.0, 1.0}, // Pure green
		{0.0, 0.0, 0.0, 1.0}, //black
		{0.9, 0.9, 0.9, 1.0}, //grey
		{0.18, 0.68, 1.0, 1.0}, //blue
		{1.0, 1.0, 1.0, 1.0} //White
    };
    std::vector<Mesh*> interactuableMeshes;
    aMeshes[0] = new Quad({0, 0}, {3840, 2160}, colors[9], aRenderers[1]->getShader("quadShader"), 1, 1, "quad");
    aMeshes[1] = new Quad({800, 700}, {450, 450}, colors[2], aRenderers[1]->getShader("quadShader"), 1, 2, "quad");
    aMeshes[2] = new triangle({2400, 1200}, {350, 560}, colors[8], aRenderers[1]->getShader("quadShader"), 1, 3, "triangle");
    aMeshes[3] = new Quad({2400, 700}, {560, 560}, colors[1], aRenderers[1]->getShader("quadShader"), 1, 4, "quad");
    aMeshes[4] = new triangle({800, 1200}, {250, 450}, colors[4], aRenderers[1]->getShader("quadShader"), 1, 5, "triangle");
}

// Input callback functions
void Application::onKeyChange(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    theKeys[key] = action != GLFW_RELEASE;
}

void Application::onMouseChange(GLFWwindow* window, int button, int action, int mods)
{
	theMouseButtons[button] = action != GLFW_RELEASE;
}

void Application::onMouseMove(GLFWwindow* window, double mx, double my)
{
    theMousePos.x = mx;
    theMousePos.y = my;
}

void Application::update()
{
	//unlock lockers
	if(!theMouseButtons[GLFW_MOUSE_BUTTON_RIGHT])
	{
		theRightMouseButtonLock = false;

	}
	if(!theMouseButtons[GLFW_MOUSE_BUTTON_LEFT])
	{
		theLeftMouseButtonLock = false;
	}

	// Retrieve
	aWindow.pollEvents();

	if (aWindow.isClosed() || theKeys[GLFW_KEY_ESCAPE])
	{
		aClosed = true;
	}

	aRenderers[aMeshes[0]->getLayer()]->addToRenderQueue(aMeshes[0]);

	aMeshes[1]->rotate(test, 0, 0, 0.5);
	aRenderers[aMeshes[1]->getLayer()]->addToRenderQueue(aMeshes[1]);

	aMeshes[2]->rotate(-test, 0, 0, 0.5);
	aRenderers[aMeshes[2]->getLayer()]->addToRenderQueue(aMeshes[2]);

	aMeshes[3]->rotate(-test, 0, 0, 0.5);
	aRenderers[aMeshes[3]->getLayer()]->addToRenderQueue(aMeshes[3]);

	aMeshes[4]->rotate(test, 0, 0, 0.5);
	aRenderers[aMeshes[4]->getLayer()]->addToRenderQueue(aMeshes[4]);
	test += 0.01;
}

void Application::render()
{
	// Create new Imgui frame
	ImGui_ImplGlfwGL3_NewFrame();

	// Create window with performance information
	ImGui::Begin("Debug", (bool *)true, ImGuiWindowFlags_NoTitleBar);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();


	for(int i = 1; i < NUM_LAYERS; i++)
	{
		aRenderers[i]->render();
	}

	ImGui::Render();
}

