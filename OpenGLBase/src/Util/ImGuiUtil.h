 #pragma once

struct GLFWwindow;

namespace OpenGLBase
{
	class ImGuiUtil
	{
	public:
		static void Init(GLFWwindow *window);
		static void Shutdown();

		static void BeginFrame();
		static void EndFrame();
	};
}