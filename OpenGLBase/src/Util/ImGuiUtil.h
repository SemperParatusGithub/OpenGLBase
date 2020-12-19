#pragma once


struct GLFWwindow;

class ImGuiUtil
{
public:
	static void ImGuiInit(GLFWwindow *window);
	static void ImGuiShutdown();

	static void ImGuiNewFrame();
	static void ImGuiRender();
};