#pragma once
#include <glm/glm.hpp>
#include <iostream>


struct GLFWwindow;

namespace OpenGLBase
{
	class Window
	{
	public:
		Window(const std::string &title, uint32_t width, uint32_t height);
		~Window();

		static void HideConsole();

		bool isOpen() const;
		void Update();
		void Close();
		void Clear(const glm::vec4 &clearColor = { 0.7f, 0.7f, 0.7f, 0.7f });

		inline GLFWwindow *GetWindow() const { return m_Window; }

		glm::vec2 GetPosition() const;
		glm::vec2 GetSize() const;

		void SetPosition(const glm::vec2 &pos);
		void SetSize(const glm::vec2 &size);

	private:
		GLFWwindow *m_Window;

		friend class ImGuiUtil;
	};
}