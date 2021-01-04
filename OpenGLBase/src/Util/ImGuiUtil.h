 #pragma once

struct GLFWwindow;

namespace OpenGLBase
{
	class ImGuiUtil
	{
	public:
		static void Init(GLFWwindow *window);	// Init and Shutdown is called by the window class
		static void Shutdown();

		static void BeginFrame();
		static void EndFrame();
	};
}