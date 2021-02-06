#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ImGuiUtil.h"


namespace OpenGLBase
{
	static uint32_t s_WindowCount = 0;

	Window::Window(const std::string &title, uint32_t width, uint32_t height)
	{
		if(s_WindowCount != 0)
			throw std::runtime_error("Only one window supported");

		if (!glfwInit())
			throw std::runtime_error("Failed to initialize GLFW!");

		std::cout << "Creating GLFW window: " << title << " (" << width << ", " << height << ")" << std::endl;
		m_Window = glfwCreateWindow((int) width, (int) height, title.c_str(), nullptr, nullptr);

		if (!m_Window)
			throw std::runtime_error("Failed to create window!");

		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
			throw std::runtime_error("Failed to initialize Glad!");

		ImGuiUtil::Init(m_Window);
		s_WindowCount++;
	}
	Window::~Window()
	{
		ImGuiUtil::Shutdown();
		glfwDestroyWindow(m_Window);
	}

	bool Window::isOpen() const
	{
		return !glfwWindowShouldClose(m_Window);
	}
	void Window::Close()
	{
		glfwSetWindowShouldClose(m_Window, true);
	}
	void Window::Clear(const glm::vec4 &clearColor)
	{
		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Window::Update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	glm::vec2 Window::GetPosition() const
	{
		int xPos, yPos;
		glfwGetWindowPos(m_Window, &xPos, &yPos);
		return { (float) xPos, (float) yPos };
	}
	glm::vec2 Window::GetSize() const
	{
		int xSize, ySize;
		glfwGetWindowSize(m_Window, &xSize, &ySize);
		return { (float) xSize, (float) ySize };
	}

	void Window::SetPosition(const glm::vec2 &pos)
	{
		glfwSetWindowPos(m_Window, (int) pos.x, (int) pos.y);
	}
	void Window::SetSize(const glm::vec2 &size)
	{
		glfwSetWindowSize(m_Window, (int) size.x, (int) size.y);
	}

	bool Window::IsKeyPressed(KeyCode kc) const
	{
		auto state = glfwGetKey(m_Window, static_cast<uint32_t>(kc));
		return state == GLFW_PRESS;
	}
	bool Window::IsMouseButtonPressed(MouseCode mc) const
	{
		int state = glfwGetMouseButton(m_Window, static_cast<uint32_t>(mc));
		return state == GLFW_PRESS;
	}
	std::pair<float, float> Window::GetMousePosition() const
	{
		double xPos, yPos;
		glfwGetCursorPos(m_Window, &xPos, &yPos);

		return std::pair { static_cast<float>(xPos), static_cast<float>(yPos) };
	}
}