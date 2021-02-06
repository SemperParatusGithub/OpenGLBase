#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include "Codes.h"


struct GLFWwindow;

namespace OpenGLBase
{
	class Window
	{
	public:
		Window(const std::string &title, uint32_t width, uint32_t height);
		~Window();

		bool isOpen() const;
		void Close();

		void Update();
		void Clear(const glm::vec4 &clearColor = { 0.7f, 0.7f, 0.7f, 0.7f });

		inline GLFWwindow *GetWindow() const { return m_Window; }

		glm::vec2 GetPosition() const;
		glm::vec2 GetSize() const;

		void SetPosition(const glm::vec2 &pos);
		void SetSize(const glm::vec2 &size);

		bool IsKeyPressed(KeyCode kc) const;
		bool IsMouseButtonPressed(MouseCode mc) const;

		std::pair<float, float> GetMousePosition() const;

	private:
		GLFWwindow *m_Window;

		friend class ImGuiUtil;
	};
}