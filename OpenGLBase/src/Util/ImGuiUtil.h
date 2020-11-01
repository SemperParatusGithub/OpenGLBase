#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


void ImGuiInit(GLFWwindow *window);
void ImGuiShutdown();

void ImGuiNewFrame();
void ImGuiRender();


